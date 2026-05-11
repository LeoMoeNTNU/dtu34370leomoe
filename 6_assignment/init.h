#ifndef INIT_H
#define INIT_H

#include "types.h" 

/*What this is supposed to do is fairly uncomplicated. 
At the end of the algorithm, we will know how many things will be in each bucket, but we don't know
this after the get. This function simply just counts it up and then allocates for a bunch of 

*/
allprocs_t init(info_t info);


#endif