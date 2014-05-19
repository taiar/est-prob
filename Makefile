main:
	gcc -o prob binomial_2_normal.c -g -Wall
test: main
	./prob