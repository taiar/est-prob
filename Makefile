main:
	gcc -o prob binomial_2_normal.c -g -Wall -lm
test: main
	rm .nf*
	./prob 10 0.5 6 8 1