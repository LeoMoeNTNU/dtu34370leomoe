gcc -O2 int_arr_crossover.c weighted_binarysearch.c printallprocs.c writetofile.c randomlist.c totallength.c wholefunction.c init.c get_first_valid_index.c placeopinjob.c get.c objective_function.c infotools.c isallowedtoplacehere.c main.c -o run
echo "compilation done!"
#valgrind --leak-check=yes --leak-check=full --show-leak-kinds=all  ./run Instances/CloudComp_instances/tai4_4_1.txt file.txt 10
valgrind --leak-check=full --show-leak-kinds=all  ./run Instances/CloudComp_instances/tai7_7_1.txt file.txt 10

#./run Instances/CloudComp_instances/tai7_7_1.txt file.txt 10




rm ./run
