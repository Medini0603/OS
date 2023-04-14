echo "Enter the range"
read n1
read n2

if [ $n1 == 1 ];
then n1=$n1+1
fi
flag=0
for((i=n1;i<n2;i++))
do
    flag=1
    for((j=2;j<=(i/2);j++))
    do
        if [ $((i%j)) == 0 ];
        then
        flag=0
        break
        fi
    done
    
    if [ $flag == 1 ];
    then
    echo $i
    fi
done
      
