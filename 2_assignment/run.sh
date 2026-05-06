gcc get.c infotools.c bucket.c greedylocalsearch.c objective.c localsearch.c main.c  -o exec
#   valgrind --leak-check=full ./exec

./exec
rm ./exec