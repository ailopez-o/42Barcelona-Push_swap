echo "\n******* Num Ops Test *********"
./push_swap $(ruby -e "puts (-200..200).to_a.shuffle.join(' ')") | wc -l