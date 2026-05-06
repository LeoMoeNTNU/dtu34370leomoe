#gcc getmatrix.c main.c randomarray.c eval.c greedysearch.c
#./a.out "/home/moeth/optimization_metaheuristics/1_assigment/Instances/ESC63.sop"

#path instance:"/home/moeth/optimization_metaheuristics/1_assigment/Instances/ESC63.sop"

#!/bin/bash

# Check that the user provided a path
if [ $# -lt 2 ]; then
    echo "Usage: ./run.sh <path-to-instance> time"
    exit 1
fi

# Compile
rm ./tsp
gcc getmatrix.c main.c randomarray.c eval.c greedysearch.c accessory.c -o tsp

# Run with the provided path
./tsp "$1"
