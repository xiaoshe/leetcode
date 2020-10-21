
f=`ls *.c -t | head -n 1`

echo $f
gcc -g -o a $f -std=c99
