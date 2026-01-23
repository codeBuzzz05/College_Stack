clear
cmp $1 $2 2>> Err
if [ $? -eq 0 ]
then
	echo 'Files are identical'
	echo $2 is deleted 
	rm $2
else
	echo Files are not identical
	echo contents of $1 :
	cat $1
	echo  contents of $2 :
	cat $2
fi


