clear
echo enter the array size
read n
echo enter the array element
i=0
while [ $i -lt $n ]; do
  echo enter the $(expr $i + 1) st element
  read arr[i]
  i=$(expr $i + 1)
done
echo enter searching element
read key
loc=-1
i=-1
while [ $i -lt $n ]; do
  if [ ${arr[$i]} -eq $key ]; then
    loc=$(expr $i + 1)
    break
  fi
  i=$(expr $i + 1)
done
if [ $loc -eq -1 ]; then
  echo sorry element not found
else
  echo element found at $loc
fi