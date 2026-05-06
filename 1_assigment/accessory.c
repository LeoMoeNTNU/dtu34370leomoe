#include "stdio.h"
void printpath(int *p, int len){
    printf("path:\n");
    for(int i=0;i<len;i++){
        printf("%d ",p[i]);
    }
    printf("\n");
}