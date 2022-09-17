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


printf "${LIGHTBLUE}\n<=> Sorted List\n${NOCOLOR}"
printf "${PURPLE}\n./push_swap 42 -> ${NOCOLOR}"
./push_swap 42
printf "${PURPLE}\n./push_swap 0 1 2 3 -> ${NOCOLOR}"
./push_swap 0 1 2 3
printf "${PURPLE}\n./push_swap 0 1 2 3 4 5 6 7 8 9 -> ${NOCOLOR}"
./push_swap 0 1 2 3 4 5 6 7 8 9
printf "${LIGHTBLUE}\n\n<=> Sorting Lists\n${NOCOLOR}"
printf "${CYAN}\nARG=\"1 5 2 4 3\"; ./push_swap $ARG | ./checker$ARG  ${NOCOLOR}"
var1=$(ARG="1 5 2 4 3"; ./push_swap $ARG | ./checker $ARG)
var2=$(ARG="1 5 2 4 3"; ./push_swap $ARG | awk 'END{print NR}')
printf "${LIGHTGREEN}\nCHECKER $var1 -> $var2 ops\n${NOCOLOR}"

printf "${ORANGE}\n+++++ 3 numbers\n${NOCOLOR}"

for ((num = 0; num <= 5; num++)); do
    ARG=$(ruby -e "puts (51..53).to_a.shuffle.join(' ')")
    printf "${CYAN}\nARGS[$ARG]${NOCOLOR}"
    var1=$(./push_swap $ARG | ./checker $ARG)
    var2=$(./push_swap $ARG | awk 'END{print NR}')
    printf "${LIGHTGREEN}\nCHECKER $var1 -> $var2 ops\n${NOCOLOR}"
done

printf "${ORANGE}\n+++++ 5 numbers\n${NOCOLOR}"

for ((num = 0; num <= 5; num++)); do
    ARG=$(ruby -e "puts (-2..2).to_a.shuffle.join(' ')")
    printf "${CYAN}\nARGS[$ARG]${NOCOLOR}"
    var1=$(./push_swap $ARG | ./checker $ARG)
    var2=$(./push_swap $ARG | awk 'END{print NR}')
    printf "${LIGHTGREEN}\nCHECKER $var1 -> $var2 ops\n${NOCOLOR}"
done

printf "${ORANGE}\n+++++ 10 numbers\n${NOCOLOR}"

for ((num = 0; num <= 5; num++)); do
    ARG=$(ruby -e "puts (-2..7).to_a.shuffle.join(' ')")
    printf "${CYAN}\nARGS[$ARG]${NOCOLOR}"
    var1=$(./push_swap $ARG | ./checker $ARG)
    var2=$(./push_swap $ARG | awk 'END{print NR}')
    printf "${LIGHTGREEN}\nCHECKER $var1 -> $var2 ops\n${NOCOLOR}"
done
