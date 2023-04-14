declare -a A
echo "Enter number of elements"
read n
echo "Enter elements of array one by one"
for((i=0;i<n;i++))
do
    read A[$i]
done

echo "${A[*]}"
echo "${#A[*]}"

large=${A[0]}

for((i=0;i<n;i++))
do
    if [ $large -lt ${A[i]} ];
    then
        large=${A[i]}
   fi
done

echo "Largest = $large"

    
