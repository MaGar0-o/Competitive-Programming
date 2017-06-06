#!/bin/bash
#./judge.bash sol1.cpp tests/gtree/ "time 2 mem $((80*1024*1024)) out $((8*1024*1024))
#STDID=$1
if [ $# -ne 3 ]; then echo -e '\E[47;31m'"\033[1mNot enough\033[0m"; tput sgr0; exit 1; fi
code=$1
PROB_DIR=$2
LIMS=$3
CELL=$PWD'/cell/'
mkdir -p $CELL

edit (){
	echo "Press any key to edit the file..."
	read x
	vim $CPP_FILE
}

c_compile (){
#	while ! g++ main.cpp "$CPP_FILE"
#	do
#		echo "==> Compile: FAILED"
#		edit
#	done
	( g++ -O2 -static "$code" -o $CELL/program || \
		( echo -e "\033[1m==> Compile: \033[0m"'\E[31m'"\033[1mFAILED\033[0m"; tput sgr0; false;) ) \
		&& (echo -e "\033[1m==> Compile: \033[0m"'\E[32m'"\033[1mOK\033[0m"; tput sgr0)
}

j_compile(){
	( javac "$code" || \
		( echo -e '\E[47;34m'"\033[1m==> Compile: \033[0m"'\E[47;31m'"\033[1mFAILED\033[0m"; tput sgr0; false;) ) && \
		(echo -e '\E[47;34m'"\033[1m==> Compile: \033[0m"'\E[47;32m'"\033[1mOK\033[0m"; tput sgr0)
}

review () {
	edit && compile
	select ask in Continue Quit 
do
	[ $ask == "Continue" ] && return 1
	break
done
return 0
}

run () {
	if [ $1 == c ]
	then
		rm $CELL/stdout $CELL/stderr
		touch $CELL/stdout $CELL/stderr
		
		echo $LIMS | sudo ./lim $CELL >> run.log 2>> err.log
		RUN_RET1=$?
		cp $CELL/stdout $CELL/stdout2 
		
		rm $CELL/stdout $CELL/stderr
		touch $CELL/stdout $CELL/stderr
		
		echo $LIMS | sudo ./lim $CELL >> run.log 2>>err.log
		RUN_RET2=$?
		RUN_RET=$(($RUN_RET1|$RUN_RET2))
		diff $CELL/stdout $CELL/stdout2 &>/dev/null || echo > stdout
	else
		name=`ls "$code" | sed 's/^\(.*\)\(\.java$\)/\1/' `;
#		cd $STDID
		echo $name
		(timeout 1 java  $name < "$2" > stdout)
#		cd ..
	fi
}

stype=""

if ! [ -e $code ]
then
	echo "NO_SUBMISSION" >> results
	echo -e '\E[35m'"\033[1mNO_SUBMISSION\033[0m"; tput sgr0
	exit
fi

echo -e "\033[1m==> Compiling...\033[0m"; tput sgr0
if [ "`echo "$code" | sed 's/^\(.*\)\(\.cpp$\)/\2/'`" == ".cpp" ]
then
	cp $code $CELL/a.cpp
	code="$CELL/a.cpp"
	stype=c
	c_compile
	compiled=$?
else
	cp $code $CELL/a.java
	code="$CELL/a.java"
	stype=j
	j_compile
	compiled=$?
fi

rm $code

if [ $compiled != 0 ]
then
	echo "COMPILE_ERROR" >> results
	exit
fi
echo -e "\033[1m==> Test Results:\033[0m"; tput sgr0
#while true
#do
	pass_count=0
	test_count=0
	j=0;
	declare -a result
	rm -f run.log err.log
	for i in `cd $PROB_DIR && ls | sort -n`
	do
		((test_count++))
		t=$PROB_DIR/$i

		cp -f $t/* $CELL/
		rm -f $CELL/ans
		touch $CELL/stdin
		touch $CELL/stdout
		touch $CELL/stderr
		chmod 666 $CELL/*
		chmod 777 $CELL/program
		TEST_RUN=1;
		run $stype
		cp -f $t/ans $CELL/

		echo -ne "\033[33m$i: \033[0m"; tput sgr0
		if [[ $RUN_RET -ne 0 ]]
		then
			if [[ $RUN_RET -eq 2 ]]
			then
				result[j]="T\t";
			else
				result[j]="S\t";
			fi
		else
			result[j]=`./test.bash $CELL`
			TEST_RUN=$?
			result[j]=`echo ${result[j]} | tr -d '\n'`"\t"
		fi

		if [ $TEST_RUN -eq 0 ]
		then
			((pass_count++))
			echo -ne "\033[32m"
		else
			echo -ne "\033[31m"
		fi
		echo -ne ${result[j]}
		echo -ne "\033[00m"; tput sgr0

		((j++))
	done

	echo -e "\n\033[1m==> Passed Count: \033[32m$pass_count\033[0m/$test_count"; tput sgr0
#	if [ $pass_count -eq 12 ]
#	then
#		echo "==> Output: OK"
#		break
#	else
#		echo "==> Output: FAILED"
#		review && break
#	fi
#done
#echo -e ${result[*]} | tr -d ' ' | sed 's/\t$//'
echo -e ${result[*]} | tr -d ' ' | sed 's/\t$//' >> results
