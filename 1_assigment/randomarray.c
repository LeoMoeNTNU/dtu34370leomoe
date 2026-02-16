#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void initalize_random(){
    srand(time(NULL));
}


void swap(int* array, int len){

    int ind_1=rand()%len;
    int ind_2=rand()%len;
    int val_1=array[ind_1];
    int val_2=array[ind_2];
    array[ind_1]=val_2;
    array[ind_2]=val_1;

}

int* randomarray(int len){
  
    //printf("2\n");
    int* array= malloc(len*sizeof(int));
    for(int i=0;i <len;i++){
        array[i]=i;
    }
    for(int i=0;i<2*len;i++){
        swap(array,len);
    }
    return array;


    
}

int isvalidarray(int *p, int len){
    bool found[len];
    for(int i=0;i<len;i++){
        found[i]=false;
    }

    for(int i=0;i<len;i++){
        found[p[i]]=true;
        
    }

    for(int i=0;i<len;i++){
        if(!found[i]) {
           
            return 0;
        }

    }
    return 1;
}
