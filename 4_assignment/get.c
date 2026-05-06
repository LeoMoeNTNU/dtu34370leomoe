#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#include <float.h>

#include <math.h>
#include "types.h"




info_t get(const char * filename){


    FILE* file= fopen(filename, "r");
    if(!file){
        printf("couldn't open file\n");
        return (info_t){0,0};
    }

    int countedlines=0;

    while(countedlines<8){
        int letter1 =fgetc(file);
        if(letter1==EOF){
            printf("less than 4 lines!\n");
            return (info_t){0,0};
        }
        if(letter1=='\n'){
            countedlines++;
        }
    }

    int rowsandcols;
    int valid_items=fscanf(file, "%d", &rowsandcols);
    //printf("there are %d items!\n",rowsandcols);
    int * retP=malloc(sizeof(int)*rowsandcols*rowsandcols);
    
    //printf("got here without segfault the first time!\n");
    int i=0;

    while(i<rowsandcols*rowsandcols){
        int number;
        int something=fscanf(file,"%d",&number);

     
        retP[i]=number;

        i++;
    }
    return (info_t){rowsandcols,retP};
}

