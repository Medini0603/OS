echo "Enter range"
read n1
read n2
flag=0
for((i=n1+1;i<n2;i++))
do
    flag=0
    for((j=2;j<=(i/2);j++))
    do
        if [ $((i%j)) == 0 ];
        then
            flag=1
            break
        fi
    done
    
    if [ $flag == 0 ];
    then
        echo "$i"
    fi
done


        
