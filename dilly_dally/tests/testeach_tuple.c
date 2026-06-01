#include "../each_tuple.h"
#include <stdio.h>

void printfunction(int *p, int len){
    for(int i=0;i<len;i++){
        printf("%d ",p[i]);
    }
    printf("\n");
}

void test1(){

    int a[4];
    each_tuple(a,0,4,0,6,printfunction);
    /*
    int each_tuple(
        int* array,
        int index,
        int max_index,
        int lowest_value,
        int max_value,
        void (*f)(int*,int)
    )
    */
}

int main(){
    test1();
}