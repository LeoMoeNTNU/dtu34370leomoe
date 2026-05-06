#ifndef TYPES_H
#define TYPES_H



typedef struct{
    int tasks;
    int * rev_values;
    int* rev_mat;
    int buckets;
    int planning_horizon;
    int * prodtimes;

}info_t;

typedef struct {
    int * p;
    int length;
}bucket_t;

#endif