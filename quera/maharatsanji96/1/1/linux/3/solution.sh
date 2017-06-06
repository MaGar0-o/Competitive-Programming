#!/bin/sh
tail -n 8000 log.txt > log-recent.txt

echo "CRITICAL $(grep CRITICAL log-recent.txt | wc -l)" > count.txt
echo "ERROR $(grep ERROR log-recent.txt | wc -l)" >> count.txt
echo "WARNING $(grep WARNING log-recent.txt | wc -l)" >> count.txt
echo "INFO $(grep INFO log-recent.txt | wc -l)" >> count.txt
echo "DEBUG $(grep DEBUG log-recent.txt | wc -l)" >> count.txt
echo "NOTSET $(grep NOTSET log-recent.txt | wc -l)" >> count.txt

fgrep "apps/blog" count
