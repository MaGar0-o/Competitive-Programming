#!/bin/sh
for((i = 10000; i < 100000; i++))
do
	./gen $i | ./sol > tmp_output
	cnt=$?
	if [ $cnt -gt 7 ]
	then
		echo "What a great test is test $i! it says $cnt"
	fi
done
rm tmp_output
