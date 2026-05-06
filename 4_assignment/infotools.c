#include "types.h"
#include <stdio.h>
#include <stdbool.h>
//as a clarification, x is how far down and y is how far right.  
int distance(info_t info,int x, int y,bool debugging){
    if(y==-1&&debugging){printf("we are inputting -1!\n");}
    //printf(" first, with length %d , x:%d, y:%d\n",info.len,x,y);
    int ret=info.p[x*info.len+y];
    //if(debugging){
      //  printf("second, returning %d\n",ret);}
    //printf("about to return %d\n",ret);
    return ret;
}

void setdistance(info_t info, int x, int y, int val){
    info.p[x*info.len+y]=val;
}