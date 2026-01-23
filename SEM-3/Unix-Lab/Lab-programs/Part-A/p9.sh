clear
a=0
b=1
res=""
i=0
while [ $i -lt 23 ]
do
	sum=`expr $a + $b`
	res=$res" "$sum
	a=$b
	b=$sum
	i=`expr $i + 1`
done
echo $res