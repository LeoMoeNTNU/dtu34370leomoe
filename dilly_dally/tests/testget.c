#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../get.h"

void printall(info_t info){
    int len=info.len;

    printf("DURATION:\n");
    for(int i=0;i<len;i++){
        for(int j=0;j<len;j++){
            printf("%d ", info.duration[i*len+j]);

        }
        printf("\n");
    }
    printf("PROCS:\n");
    for(int i=0;i<len;i++){
        for(int j=0;j<len;j++){
            printf("%d ", info.processors[i*len+j]);

        }
        printf("\n");
    }
    
}


void test1(){
    info_t info=get_random(4);
    printall(info);
}

int main(){

    srand(time(NULL));
    test1();
    return 0;
}