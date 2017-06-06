#!/bin/sh
./gen > samp
./hamid < samp > h.out
./majid < samp > m.out
diff -Bbq h.out m.out
