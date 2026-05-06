gcc tl_contains.c init_tl.c insert_into_tl.c tests/testinsert_into_tl.c -o run
./run
rm ./run


#include "../types.h"
#include "../tl_contains.h"
#include <stdio.h>
#include "../init_tl.h"