echo "Enter string"
read str
length=${#str}
for((i=length-1;i>=0;i--))
do
    rev=$rev${str:$i:1}
done

echo "Reversed string = $rev"
if [ $rev == $str ];
then
echo "Palindrome"
else echo "Not Palindrome"
fi
