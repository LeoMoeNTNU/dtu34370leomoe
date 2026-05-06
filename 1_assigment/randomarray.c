#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdlib.h>

int start_time;

void initialize_random(){
    srand(time(NULL));
    start_time=time(NULL);
}

int timewent(){
    return time(NULL)-start_time;
}

void swap(int* array, int len){

    int ind_1=rand()%len;
    int ind_2=rand()%len;
    int val_1=array[ind_1];
    int val_2=array[ind_2];
    array[ind_1]=val_2;
    array[ind_2]=val_1;

}

void randomarray(int* array,int len){
  
    //printf("2\n");
    //int* array= malloc(len*sizeof(int));
    for(int i=0;i <len;i++){
        array[i]=i;
    }
    for(int i=0;i<2*len;i++){
        swap(array,len);
    }
    //return array;


    
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
//the reason that I input the int pointer is that I then dont have to do malloc and can just send in an array-pointer (on stack)
void randomindexes(int* ip,int amount, int maxVal){
    for(int i=0;i<amount;i++){
        ip[i]=rand()%maxVal;
    }
}
