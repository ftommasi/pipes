all:
	gcc -o program1 program1.c
	gcc -o program2 program2.c
	gcc -o pipe pipe.c
clean:
	rm program1 program2 pipe
