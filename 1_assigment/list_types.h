#ifndef LISTTYPES_H
#define LISTTYPES_H
typedef struct {
    float x;
    float y;
    
} entry_t;


enum status {MINUSONE,NOTMINUSONE, MAYBE};
typedef struct {
    int len;
    int* p;
    enum status * sP;
}list_t;



typedef struct {

    int len;
    int* p;

} topsortmatrix_t;

#endif