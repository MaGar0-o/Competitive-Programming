#!/bin/sh
./gen > inp
time ./min < inp
#./nai < inp > ou2
#diff -Bbq ou1 ou2
