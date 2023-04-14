echo "Enter string"
read str
echo "Revresed string"
echo $str|rev
length=${#str}
echo $length

for((i=$length-1;i>=0;i--))
do
    rev=$rev${str:$i:1}
done
echo $rev
if [ $str == $rev ]
then    echo "palindrome"
else echo "Not palindrome"
fi
