#ifndef INFO_H
#define INFO_H





typedef struct {
    int len;
    int* duration;
    int* processors;
    
} info_t;

typedef struct {
    int start;
    int end;
    //int end; //I just deduce this whenever I need it lol. 
    int index;
} op_in_proc_t;

typedef struct{
    int len;
    op_in_proc_t * p;
} proc_list_t;

typedef struct {
    int len;
    proc_list_t* p;
}allprocs_t;

typedef struct {
    int val;
    allprocs_t ap;
} ap_and_val_t;






#endif

