echo "Enter number"
read n

temp=$n
rev=0
while((n>0))
do
    rem=$((n%10))
    rev=$((rev*10+rem))
    n=$((n/10))
done

echo "reversed number = $rev"

if [ $rev == $temp ];
then 
    echo "Palindrome"
else 
    echo "Not palindrome"
fi
    
