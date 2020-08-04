
f=`ls *.c *.cc -t | head -n 1`

echo $f
ret=`echo $f|grep cc`
if [ "$ret" = "$f" ] ; then
    g++ -g -o a $f
else
    gcc -g -o a $f
fi
