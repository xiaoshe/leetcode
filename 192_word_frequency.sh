cat words.txt | sed 's# #\n#g' | sort |uniq -c | sort -nr -k2 | awk '{if($2!="") print $2,$1}'
