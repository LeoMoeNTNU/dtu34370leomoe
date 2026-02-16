#include <stdlib.h>
#include <stdio.h>
#include "getmatrix.h"
#include "randomarray.h"

int main(int argc, char ** argv){
    printf("hi\n");
    printf("%s\n", argv[1]);
    list_t matrix=getmatrix(argv[1]);
    int width=matrix.len;
    for(int i=0;i<width;i++){
        for(int j=0;j<width;j++){
            
            //printf("index %d: %d ", i*width+j, matrix.p[i*width+j]);
                        printf("%d ", matrix.p[i*width+j]);

        }
        printf("\n");
    }

    int * random= randomarray(20);
    /*
    for(int i=0;i<20;i++){
        printf("%d:%d\n",i,random[i]);
    }
    */


    printf("is the array valid? %d\n",isvalidarray(random, 20));

    return 0;
}