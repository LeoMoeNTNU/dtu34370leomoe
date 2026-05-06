#include "types.h"
#include <stdbool.h>
#include <stdio.h>
/*
typedef struct {
    int len;
    int* p;
    int lengthofarrays;
    int rollingp;
    
} tl_t;
*/
bool tl_contains(tl_t tl, int* ip, bool debugging){
    if(debugging){

        printf("the whole tl:\n");
        printf("len: %d,lengthofarrays: %d, rollingp:%d\n",tl.len,tl.lengthofarrays,tl.rollingp);
    }
    
    for(int i=0;i<tl.len;i++){
        bool same=true;
        for(int locind=0;locind<tl.lengthofarrays;locind++){
            int firstint=tl.p[i*tl.lengthofarrays+locind];
            int secint=ip[locind];
            if(debugging)printf("at index %d, %d vs %d\n",locind,firstint,secint);
            if(firstint!=secint){
                same=false;
                break;
            }
        }
        if(same)return true;
    }
    return false;
}

