#!/bin/sh
cur=0
mkdir in
mkdir out
for i in $( ls input/ | sort -h )
do
	cur=$((cur+1))
	mv ./input/"$i"		./in/input$cur.txt
	mv ./output/"$i"	./out/output$cur.txt
done
rm -rf input output
