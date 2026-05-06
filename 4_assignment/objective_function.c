#include "types.h"
#include "infotools.h"
#include <stdio.h>
int objective_function(info_t info,int* ip){
    int dist=0;
    for(int i=0;i<info.len-1;i++){
        dist+=distance(info,ip[i],ip[i+1],false);
    }
    return dist;
}

int objective_function_alt(info_t info,int* ip, int x, int y){//x and y are arrays. We will swap it. 
    //printf("length: %d, x: %d, y:%d\n",info.len,x,y);
    int dist=0;
    int temp;
    //printf("in here!\n");
    temp=ip[x];
    ip[x]=ip[y];
    ip[y]=temp;
    //printf("in here 2\n");
    for(int i=0;i<info.len-1;i++){
        //printf("checking index %d and %d\n",ip[i],ip[i+1]);
        dist+=distance(info,ip[i],ip[i+1],false);
    }
    //printf("in here 3\n");
    temp=ip[x];
    ip[x]=ip[y];
    ip[y]=temp;

    return dist;
}


