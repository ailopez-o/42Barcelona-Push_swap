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

printf "${LIGHTBLUE}\n<=> Errors Test\n${NOCOLOR}"
printf "${PURPLE}\n./push_swap j -> ${NOCOLOR}"
./push_swap j
printf "${PURPLE}./push_swap @ -> ${NOCOLOR}"
./push_swap @
printf "${PURPLE}./push_swap = -> ${NOCOLOR}"
./push_swap =
printf "${PURPLE}./push_swap 1 2 6 7 8 1 -> ${NOCOLOR}"
./push_swap 1 2 6 7 8 1
printf "${PURPLE}./push_swap  -> ${NOCOLOR}"
./push_swap
printf "${PURPLE}./push_swap 5 7 3 2147483648 9 1 -> ${NOCOLOR}"
./push_swap 5 7 3 2147483648 9 1
printf "${PURPLE}./push_swap 5 7 3 -2147483649 9 1 -> ${NOCOLOR}"
./push_swap 5 7 3 2147483648 9 1
