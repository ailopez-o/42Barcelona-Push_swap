leaks --atExit -- ./push_swap $(ruby -e "puts (-50..50).to_a.shuffle.join(' ')")

ARG=$(ruby -e "puts (0..500).to_a.shuffle.join(' ')"); 
echo "\n******* CHECKER *********\n"
./push_swap $ARG | leaks --atExit -- ./my_checker $ARG
