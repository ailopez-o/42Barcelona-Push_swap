echo "\n******* 500 Num Ops Test *********"
var1=$(./push_swap $(ruby -e "puts (-249..250).to_a.shuffle.join(' ')") | wc -l)
echo $var1
var2=$(./push_swap $(ruby -e "puts (-249..250).to_a.shuffle.join(' ')") | wc -l)
echo $var2
var3=$(./push_swap $(ruby -e "puts (-249..250).to_a.shuffle.join(' ')") | wc -l)
echo $var3
var4=$(./push_swap $(ruby -e "puts (-249..250).to_a.shuffle.join(' ')") | wc -l)
echo $var4
var5=$(./push_swap $(ruby -e "puts (-249..250).to_a.shuffle.join(' ')") | wc -l)
echo $var5
var6=$(./push_swap $(ruby -e "puts (-249..250).to_a.shuffle.join(' ')") | wc -l)
echo $var6
var7=$(./push_swap $(ruby -e "puts (-249..250).to_a.shuffle.join(' ')") | wc -l)
echo $var7
var8=$(./push_swap $(ruby -e "puts (-249..250).to_a.shuffle.join(' ')") | wc -l)
echo $var8
var9=$(./push_swap $(ruby -e "puts (-249..250).to_a.shuffle.join(' ')") | wc -l)
echo $var9
var10=$(./push_swap $(ruby -e "puts (-249..250).to_a.shuffle.join(' ')") | wc -l)
echo $var10

var11=$(( var1 + var2 + var3 + var4 + var5 + var6 + var7 + var8 + var9 + var10 ))
var11=$(( var11 /10))
echo "--> $var11\n"