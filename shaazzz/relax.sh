#!/bin/bash
if [ $1 ] && [ $2 ] && [ $3 ]; then
	g++ -Wall -O2 -std=c++0x -o solution ../code.cpp
	g++ -Wall -O2 -std=c++0x -o generator generator.cpp
	mkdir test
	for ((i=$1; i<=$1; i++))
	do
		for ((j=1; j<=$2; j++))
		do
			c=$(($j+$4));
			x=$(($c/10));
			y=$(($c%10));
			./generator $i $j $3 > test/$i-$x$y.in
			./solution < test/$i-$x$y.in > test/$i-$x$y.out
			echo $i-$x$y
		done
	done
else
	echo "    Usage : bsah relax.sh [test_number] [random_base]"
fi

