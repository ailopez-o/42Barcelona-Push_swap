echo "\n******* Checker Test *********"
echo "\n******* 20 *********\n"
ARG=$(ruby -e "puts (-10..10).to_a.shuffle.join(' ')"); ./push_swap $ARG | ./checker $ARG
ARG=$(ruby -e "puts (0..19).to_a.shuffle.join(' ')"); ./push_swap $ARG | ./checker $ARG
echo "\n******* 55 *********\n"
ARG=$(ruby -e "puts (-20..34).to_a.shuffle.join(' ')"); ./push_swap $ARG | ./checker $ARG
ARG=$(ruby -e "puts (0..54).to_a.shuffle.join(' ')"); ./push_swap $ARG | ./checker $ARG
echo "\n******* 100 *********\n"
ARG=$(ruby -e "puts (-50..49).to_a.shuffle.join(' ')"); ./push_swap $ARG | ./checker $ARG
ARG=$(ruby -e "puts (0..49).to_a.shuffle.join(' ')"); ./push_swap $ARG | ./checker $ARG
echo "\n******* 500 *********\n"
ARG=$(ruby -e "puts (-250..250).to_a.shuffle.join(' ')"); ./push_swap $ARG | ./checker $ARG