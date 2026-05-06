gcc -O2 printallprocs.c writetofile.c randomlist.c totallength.c wholefunction.c init.c get_first_valid_index.c placeopinjob.c get.c objective_function.c infotools.c isallowedtoplacehere.c main.c -o run
echo "compilation done!"
./run Instances/CloudComp_instances/tai15_15_2.txt file.txt 60




rm ./run
