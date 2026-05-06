#include "types.h"

void rev_mat_insert(int x, int y,int value,info_t info){
    info.rev_mat[x*info.tasks+y]=value;
}

int rev_mat_get(int x, int y, info_t info){
    //printf("indent: %d\n",x*info.tasks+y);
    return info.rev_mat[x*info.tasks+y];
}