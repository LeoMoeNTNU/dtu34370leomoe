CC = gcc
CFLAGS = -O3
SRC = printallprocs.c writetofile.c randomlist.c totallength.c wholefunction.c \
      init.c get_first_valid_index.c placeopinjob.c get.c objective_function.c \
      infotools.c isallowedtoplacehere.c int_arr_crossover.c main.c

run: program
	./s251885 $(ARG1) $(ARG2) $(ARG3)
	rm ./s251885

program: $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o program
