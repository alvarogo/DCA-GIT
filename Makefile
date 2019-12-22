
all: calculator.c
	gcc -Wall -g -o calculator calculator.c

clean:
	rm -r calculator
