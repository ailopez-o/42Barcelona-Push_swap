echo "\n*************************\n"
echo "******* COMPILE *********\n"
echo "*************************\n"


echo "\n*************************\n"
echo "******* TESTING *********\n"
echo "*************************\n"

./$(dirname "$0")/basic.sh
./$(dirname "$0")/limits.sh
./$(dirname "$0")/errors.sh
./$(dirname "$0")/500_numops.sh