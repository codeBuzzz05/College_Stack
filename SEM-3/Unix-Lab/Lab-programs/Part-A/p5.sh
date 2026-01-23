clear
p1=` ls -l $1 | cut -c 2-10 `
p2=` ls -l $2 | cut -c 2-10 `
if [ "$p1" = "$p2" ]
then
	echo Permissions are identical 
	echo $p1
else
	echo for $1 : $p1
	echo for $2 : $p2
fi
