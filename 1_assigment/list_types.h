#ifndef LISTTYPES_H
#define LISTTYPES_H
typedef struct {
    float x;
    float y;
    
} entry_t;

typedef struct {
    int len;
    int* p;
}list_t;

#endif