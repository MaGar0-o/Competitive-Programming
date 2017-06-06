#!/bin/bash
mkdir tmp
ac=0
wa=0
tle=0
for((i=0;i<100;i++)) do
	echo "Testing $i:"
	timeout $1 ./bt_shuffle.out < ./in/input$i.txt > ./tmp/output$i.txt
	if [ $? = 0 ]; then
		diff -Bbq ./tmp/output$i.txt ./out/output$i.txt
		if [ $? = 0 ]; then
			echo "Correct Answer :)"
			ac=$((ac+1))
		else
			echo "Wrong Answer :("
			wa=$((wa+1))
		fi
	else
		echo "Time Limit Exceeded :|"
		tle=$((tle+1))
	fi
done
echo
echo "AC: $ac"
echo "WA: $wa"
echo "TLE: $tle"
return $ac
