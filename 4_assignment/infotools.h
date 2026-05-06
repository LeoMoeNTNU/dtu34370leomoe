#ifndef INFOTOOLS_H
#define INFOTOOLS_H

#include "types.h"
#include <stdbool.h>

//as a clarification, x is how far down and y is how far right.  

int distance(info_t info,int x, int y, bool debugging);
void setdistance(info_t info, int x, int y, int val);

#endif