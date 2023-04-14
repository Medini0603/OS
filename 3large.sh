echo "enter 3 numbers"
read n1
read n2
read n3

large=$n1

if [ $large -lt $n2 ];
then
    large=$n2
fi

if [ $large -lt $n3 ];
then
    large=$n3
fi

echo "Largest = $large"
