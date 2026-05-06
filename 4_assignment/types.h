#ifndef TYPES_H
#define TYPES_H

typedef struct {
    int len;
    int * p;
} info_t;

typedef struct {
    int len;
    int* p;
    int lengthofarrays;
    int rollingp;

} tl_t;


//tl_t stands for tabu_list_t

#endif