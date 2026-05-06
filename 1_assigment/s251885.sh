
# Check that the user provided a path
if [ $# -lt 2 ]; then
    echo "Usage: ./s251885.sh <path-to-instance> time"
    exit 1
fi

# Compile

gcc eval.c getmatrix.c simple.c easy_solution.c -o exec

# Run with the provided path
./exec "$1"
rm ./exec
