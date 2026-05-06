#include "list_types.h"
#include <stdbool.h>
#include "eval.h"


bool isvalidinsertion(list_t matrix, int i, bool* allowed);

int valid_insertion(list_t matrix,bool* allowed);

int insert(list_t matrix, int valuetoput, int wheretoput, int* arraytoputin, bool* allowed);
/* RESPONSIBILITIES: 
    1. TAKE AWAY THE -1's IN THE MATRIX. 
    2. MODIFY THE ALLOWED ARRAY. 
    3. PUT IN THE ARRAYTOPUTIN


*/

int * basic_valid(list_t matrix);


