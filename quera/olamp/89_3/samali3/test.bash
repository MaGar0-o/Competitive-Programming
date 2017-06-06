#!/bin/bash
CELL=$1
if diff -wbB $CELL/ans $CELL/stdout &> /dev/null
then
	echo "OK"
	exit 0
else
	echo "W"
	exit 1
fi
