echo "\n******* Checker Test *********"
echo "\n******* 20 *********\n"
ARG=$(ruby -e "puts (-10..10).to_a.shuffle.join(' ')"); ./push_swap $ARG | ./checker $ARG
ARG=$(ruby -e "puts (0..19).to_a.shuffle.join(' ')"); ./push_swap $ARG | ./checker $ARG
