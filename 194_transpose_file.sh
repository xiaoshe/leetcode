col=`head file.txt -n 1 | awk '{print NF}'`
echo $col

arr=`cat file.txt`
echo $arr
len=${#arr[@]}
echo $len

for $v in ${arr[@]}; do 
  echo $v
done
