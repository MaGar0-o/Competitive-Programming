#!/bin/bash
#./script amali1 queue data/amali1/101.tar.gz tests/queue "time 1 mem $((64*1024*1024)) out $((1*1024*1024))"
if [ $# -ne 5 ]; then echo "Not enough"; exit 1; fi
PREFIX=""
USER_NAME=$1
PROB_NAME=$2
ARCHIVE_NAME=$3
PROB_DIR=$4
LIMS=$5
FOLDER_NAME=`echo "$ARCHIVE_NAME" | sed 's/^\(.*\)\(\.zip$\)/\1/'`
FOLDER_NAME=`echo "$FOLDER_NAME" | sed 's/^\(.*\)\(\.rar$\)/\1/'`
FOLDER_NAME=`echo "$FOLDER_NAME" | sed 's/^\(.*\)\(\.tar\.gz$\)/\1/'`
STDID=`echo "$FOLDER_NAME" | sed 's/^\(.*\/\)\(.*$\)/\2/'`
FILENAME=`echo "$ARCHIVE_NAME" | sed 's/^\(.*\/\)\(.*$\)/\2/'`
#STDID=`echo "$STDID" | sed 's/^\(.*_\)\(.*$\)/\2/' | sed 's/\[//' | sed 's/\]//'`

echo -e '\E[36m'"\033[1m$STDID\033[0m"
if [ ! -d $STDID ];
then
	EDIR=/tmp/aaaa
	[ -e $EDIR ] && sudo rm -r $EDIR
	mkdir $EDIR
	cp "$ARCHIVE_NAME" /tmp/$FILENAME
	sudo tar -xzf /tmp/$FILENAME -C $EDIR && rm /tmp/$FILENAME
	sudo chown -R $USER $EDIR
	sudo chgrp -R $USER $EDIR
	sudo chmod -R 744 $EDIR
fi
[ -e results ] || ( echo -ne "\t\t"; cd $PROB_DIR && ls | sort -n | sed 's/$/\t/' | tr -d '\n' | sed 's/\t$//'; echo ) >> results
echo -ne "$STDID\t" >> results
SRC_NAME=$EDIR/home/$USER_NAME/"$PROB_NAME".cpp;
if [ -e $SRC_NAME ];
then
	cat $SRC_NAME | grep 'rand' >> results
	cat $SRC_NAME | grep 'system' >> results
	STDNAME=`cat $SRC_NAME | grep '//name: ' | sed 's/^\(.*\)\(\/\/name: \)\(.*$\)/\3/' | tr -d '\n' `
	echo -e '\E[36m'"\033[1m$STDNAME\033[0m"
fi
echo -ne "$STDNAME\t" >> results
./judge.bash "$SRC_NAME" "$PROB_DIR" "$LIMS"
rm -r $EDIR
