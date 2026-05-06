CC = gcc
CFLAGS = -O2
SRC = easy_solution.c get.c infotools.c init_tl.c insert_into_tl.c isswaplegal.c \
      objective_function.c tabusearch.c tl_contains.c writetofile.c fillarraywithrandom.c

program: $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o program
run: program
	./program $(ARG1) $(ARG2) $(ARG3)
	rm ./program
