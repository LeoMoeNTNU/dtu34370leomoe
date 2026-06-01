#include "../expanding_local_search.h"
#include <stdio.h>

void printfunction(int *p, int len){
    for(int i=0;i<len;i++){
        printf("%d ",p[i]);
    }
    printf("\n");
}

void test1(){
    printf("TEST 1:\n");
    expanding_localsearch(3,printfunction);

}

void test2(){
    printf("TEST 2:\n");
    expanding_localsearch(5,printfunction);
}

int main(){
    test1();
    test2();
}
