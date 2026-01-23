clear
max3 () {
	res=$1
	if [ $2 -gt $res ]
	then
		res=$2
	fi
	if [ $3 -gt $res ]
	then
		res=$3
	fi
	echo $res
	return 1
}

echo enter fist number
read n1
echo enter  second number
read n2
echo read 3rd number
read n3
res=`max3 $n1 $n2 $n3`
echo maximum of three numbers is $res

