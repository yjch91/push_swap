# ARG=$(./tester/test 6) ; ./push_swap $ARG

ARG=$(./tester/test 500) ; ./push_swap $ARG | wc -l

# ARG=$(./tester/test 5) ; ./push_swap $ARG | ./checker $ARG

