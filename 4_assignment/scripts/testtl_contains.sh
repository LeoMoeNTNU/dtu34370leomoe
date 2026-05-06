gcc tl_contains.c init_tl.c insert_into_tl.c tests/testtl_contains.c -o run
./run
rm ./run
#include "../tl_contains.h"
#include "../tl_init.h"
#include "../insert_into_tl.h"