#include "types.h"
#include <stdlib.h>
/*
typedef struct {
    int len;
    int** p;
    int lengthofarrays;
    int rollingp;

} tl_t;
*/
tl_t init_tb_list(int howmanyarrays, int howlongarrays){
    tl_t ret;
    ret.len=howmanyarrays;
    
    //ret.p=malloc(sizeof(int*)*howmanyarrays);
    ret.p=malloc(sizeof(int)*howmanyarrays*howlongarrays);
    for(int i=0;i<howmanyarrays*howlongarrays;i++){
        ret.p[i]=0;
    }
    
    ret.lengthofarrays=howlongarrays;
    ret.rollingp=0;
    return ret;
}
