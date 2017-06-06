#!/bin/bash
done=0
for((i=0;i<100;i++)) do
	mv ./orig/in/input$i.txt ./orig/in/input$done.txt
	mv ./orig/out/output$i.txt ./orig/out/output$done.txt
	if [ $? = 0 ]; then
		echo $i "-->" $done
		done=$((done+1))
	fi
done
