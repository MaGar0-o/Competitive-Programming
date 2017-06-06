./gen > input.txt
./min < input.txt > min.out
./nai < input.txt > nai.out
diff -Bbq nai.out min.out
