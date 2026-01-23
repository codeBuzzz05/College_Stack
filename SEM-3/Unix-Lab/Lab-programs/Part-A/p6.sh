clear
echo Enter the first string 
read str1
echo enter the second string 
read str2
echo length of string 1 : ${#str1}
echo length of string 2 : ${#str2}
if [ -z "$str1" ]
then 
	echo Frist string is null
fi
if [ -z "$str2" ]
then
	echo second string is Null
fi
if [ "$str1" = "$str2" ]
then
	echo Both the strings are equal
else
	echo Strings are Unequal
fi
