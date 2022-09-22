echo "\n******* Checker Test *********"
ARG=$(ruby -e "puts (0..500).to_a.shuffle.join(' ')"); 
#./push_swap $ARG 
echo "\n******* CHECKER *********\n"
./push_swap $ARG | ./my_checker $ARG