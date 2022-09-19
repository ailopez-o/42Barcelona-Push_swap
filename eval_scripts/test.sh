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

./$(dirname "$0")/logo.sh

printf "${ORANGE}\n\nNORMINETTE ++++++++++++\n\n${NOCOLOR}"

./$(dirname "$0")/norm.sh

printf "${ORANGE}\n\nCOMPILE ++++++++++++\n\n${NOCOLOR}"

#Make re

printf "${ORANGE}\n\nTESTING ++++++++++++\n\n${NOCOLOR}"

./$(dirname "$0")/basic.sh
./$(dirname "$0")/errors.sh
./$(dirname "$0")/numops.sh

./$(dirname "$0")/logo.sh