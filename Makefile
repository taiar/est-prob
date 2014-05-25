main:
	gcc -o prob binomial_2_normal.c -g -Wall -lm
test: main
	rm -f .nf*
	./prob 10 0.5 6 8 1
binomial: main
	rm -f .nf*
	./prob 225 0.2 39 48 1
normal: main
	rm -f .nf*
	./prob 225 0.2 39 48 2
