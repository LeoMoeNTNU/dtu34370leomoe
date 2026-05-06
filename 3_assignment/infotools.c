
#include "types.h"



/*
typedef struct {
    int len;
    int* duration;
    int* processors;
    
} info_t;*/
int job(info_t info, int index){
    return index/info.len;
}

int duration(info_t info, int index){
    
    return info.duration[index];
}

int processor(info_t info, int index){
    return info.processors[index];
}


