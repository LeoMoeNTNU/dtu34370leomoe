#ifndef INFOTOOLS_H
#define INFOTOOLS_H
#include "types.h"



/*
typedef struct {
    int len;
    int* duration;
    int* processors;
    
} info_t;*/
int job(info_t info, int index);

int duration(info_t info, int index);

int processor(info_t info, int index);



#endif