echo "Enter 2 numbers"
read n1
read n2
echo "Enter operator"
read op

case $op in
'+') echo "$n1 + $n2 = $((n1+n2))"
;;

'-') echo "$n1 - $n2 = $((n1-n2))"
;;

'*') echo "$n1 * $n2 = $((n1*n2))"
;;

'/') echo "$n1 / $n2 = $((n1/n2))"
;;

*) echo "Invalid"
esac
