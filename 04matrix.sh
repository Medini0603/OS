#declare -a arr
#echo "Enter array elements"

#for((i=0;i<5;i++))
#do
 #   read arr[$i]
#done

#echo "${arr[*]}" ‘ 

declare -A x
declare -A y
declare -A z
echo "Enter order of matrix"
read n
echo "Enter values of matrix 1"
for((i=0;i<n;i++))
do
    for((j=0;j<n;j++))
    do
        read x[$i,$j]
    done
done
echo "Enter values of matrix 2"
for((i=0;i<n;i++))
do
    for((j=0;j<n;j++))
    do
        read y[$i,$j]
    done
done

echo "MAtrix 1"

for((i=0;i<n;i++))
do
    for((j=0;j<n;j++))
    do
        echo -ne "${x[$i,$j]} "
    done
    echo
    
done
echo "Matrix 2"
for((i=0;i<n;i++))
do
    for((j=0;j<n;j++))
    do
        echo -ne "${y[$i,$j]} "
    done
    echo
done
echo "Sum matrix"

for((i=0;i<n;i++))
do
    for((j=0;j<n;j++))
    do
        z[$i,$j]=$((x[$i,$j]+y[$i,$j]))
        echo -ne "${z[$i,$j]} "
    done
    echo
done







