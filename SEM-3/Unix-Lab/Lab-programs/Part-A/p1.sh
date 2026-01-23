clear
cat > db.txt
echo -e "The studemt list"
cut -d ',' -f 2,3 db.txt
echo 'The frequency of sudents'
cut -d ',' -f 3 db.txt | sort | uniq -c
