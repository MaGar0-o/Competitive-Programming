#!/bin/bash
for((i=0;i<100;i++)) do
	echo "Testing $i:"
	./gen $i > ./in/input$i.txt
	time ./bt.out < ./in/input$i.txt > ./out/output$i.txt
	./opt.out < ./in/input$i.txt > ./out/naout$i.txt
	diff -Bbq ./out/output$i.txt ./out/naout$i.txt
done
