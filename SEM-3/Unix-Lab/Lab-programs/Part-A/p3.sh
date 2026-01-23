clear
if [ -f $1 ]
then 
	echo $1 is a regular File
elif [ -d $1 ]
then
	echo $1 is a Directory
elif [ -L $1 ]
then 
	echo $1 is a link file
elif [ -c $1 ]
then 
	echo character device
elif [ -b $1 ]
then 
	echo block device
elif [ -p $1 ]
then 
	echo $1 is a pipe file 
else
	echo invalid file format
fi

