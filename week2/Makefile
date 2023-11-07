# numbers: main.o sum.o sum_squares.o
# 	gcc main.o sum.o sum_squares.o -o numbers
# sum.o: sum.c
# 	gcc -c sum.c
# sum_squares.o: sum_squares.c
# 	gcc -c sum_squares.c
main: main.o prime.o
	gcc main.o prime.o -o main
prime.o: prime.c
	gcc -c prime.c
main.o: main.c
	gcc -c main.c
clean:
	rm main.o prime.o main