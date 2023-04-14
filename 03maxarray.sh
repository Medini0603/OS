echo "Enter elements one by one"

read -a arr
echo "Array elements : ${arr[*]}"

len=${#arr[*]}
max=${arr[0]}
for((i=0;i<len;i++))
do
    if [ ${arr[i]} -gt $max ];
    then 
    max=${arr[i]}
    fi
done

echo "Largest = $max"
