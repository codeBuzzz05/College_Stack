clear
echo enter start
read start
echo enter end
read end
while [ $start -lt $end ]; do
  i=2
  flag=0
  while [ $i -lt $start ]; do
    if [ $(expr $start % $i) -eq 0 ]; then
      flag=1
      break
    fi
    i=$(expr $i + 1)
  done
  if [ $flag -eq 0 ]; then
    echo $start
  fi
  start=$(expr $start + 1)
done