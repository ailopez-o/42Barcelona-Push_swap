NOCOLOR='\033[0m'
RED='\033[0;31m'
GREEN='\033[0;32m'
ORANGE='\033[0;33m'
BLUE='\033[0;34m'
PURPLE='\033[0;35m'
CYAN='\033[0;36m'
LIGHTGRAY='\033[0;37m'
DARKGRAY='\033[1;30m'
LIGHTRED='\033[1;31m'
LIGHTGREEN='\033[1;32m'
YELLOW='\033[1;33m'
LIGHTBLUE='\033[1;34m'
LIGHTPURPLE='\033[1;35m'
LIGHTCYAN='\033[1;36m'
WHITE='\033[1;37m'

ARG=$(ruby -e "puts (0..25).to_a.shuffle.join(' ')")
./push_swap $ARG

printf "${LIGHTBLUE}\n<=> NumOps Tester (500)\n\n${NOCOLOR}"
var10=0;
for ((num = 0; num < 10; num++)); do
    printf "${DARKGRAY}TEST $num:${NOCOLOR}"
    ARG=$(ruby -e "puts (-249..250).to_a.shuffle.join(' ')")
    var1=$(./push_swap $ARG | ./checker $ARG)
    var2=$(./push_swap $ARG | awk 'END{print NR}')
    var10=$((var10 + var2))
    printf "${WHITE} CHECKER $var1 -> $var2 ops\n${NOCOLOR}"
done

var10=$(( var10 /10))
printf "${LIGHTGREEN}\nAVERAGE +++++++++++++ $var10 ops\n${NOCOLOR}"

