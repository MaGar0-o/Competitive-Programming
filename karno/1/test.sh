#!/bin/sh
#gpp Ggen.cpp -o gen
#gpp G.cpp -o my
#gpp Gnaive.cpp -o nai

./gen > tst.in
./my < tst.in > my.out
./nai < tst.in > nai.out
diff -Bbq my.out nai.out
