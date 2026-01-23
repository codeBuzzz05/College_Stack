clear
echo enter a number
read n
num=$n
sum=0
while [ $num -gt 0 ]
do
	d=`expr $num % 10`
	sum=`expr $sum \* 10 + $d`
       num=`expr $num / 10`
done
echo $sum


