declare -A X
declare -A Y
declare -A Z

echo "Enter order of matrices"
read n

echo "Enter first matrix"
for((i=0;i<n;i++))
do
    for((j=0;j<n;j++))
    do
        read X[$i,$j]
    done
done  

echo "Second matrix"
for((i=0;i<n;i++))
do
    for((j=0;j<n;j++))
    do
        read Y[$i,$j]
    done
done  

echo "First matrix"
for((i=0;i<n;i++))
do
    for((j=0;j<n;j++))
    do
        echo -ne "${X[$i,$j]} "
    done
    echo
done  

echo "Second matrix"
for((i=0;i<n;i++))
do
    for((j=0;j<n;j++))
    do
        echo -ne "${Y[$i,$j]} "
    done
    echo
done  


echo "Sum of 2 matrices"

for((i=0;i<n;i++))
do
    for((j=0;j<n;j++))
    do
        Z[$i,$j]=$((X[$i,$j]+Y[$i,$j]))
        echo -ne "${Z[$i,$j]} "
    done
    echo
done






