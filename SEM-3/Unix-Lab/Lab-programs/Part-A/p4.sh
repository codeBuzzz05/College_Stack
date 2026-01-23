clear
echo Before:
ls

for var in $*
do
	if [ -e $var ]
	then 
		new=`echo $var | tr "[a-z]" "[A-Z]"`
		mv $var $new
	else
		echo file does not exist
	fi
done
echo after:
ls
