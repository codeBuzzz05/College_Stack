clear
res=""
for var in $*
do
	res=$var" "$res
done
echo Result : $res
