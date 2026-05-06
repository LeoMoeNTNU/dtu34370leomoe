#include "types.h"
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
int counter;
void insert_into_tl(tl_t tl, int* ip,bool debugging){
    int*p;
    
    p=tl.p+(counter*tl.lengthofarrays);
    for(int i=0;i<tl.lengthofarrays;i++){
        p[i]=ip[i];
    }
    
    if(debugging)printf("current index is %d and next will be: %d\n"
        ,counter,(counter+1)%tl.len);
    counter=(counter+1)%tl.len;
}
