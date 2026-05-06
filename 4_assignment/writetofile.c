#include "types.h"
#include <stdio.h>
#include <stdlib.h>

void writetofile(int* ip, int len,char * writeto){
    FILE * file=fopen(writeto, "w");
    for(int i=0;i<len;i++){
           //fprintf(f, "%d ", p[i * length + j]);
        fprintf(file,"%d ",ip[i]);
    }
}