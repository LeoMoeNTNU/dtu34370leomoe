#ifndef IS_SWAP_LEGAL_H
#define IS_SWAP_LEGAL_H

#include "types.h"
#include <stdbool.h>

//from my looking at it, I think isswaplegal are supposed to be indexes into the array ip. 
bool isswaplegal(info_t info, int index1, int index2, int* ip);


#endif