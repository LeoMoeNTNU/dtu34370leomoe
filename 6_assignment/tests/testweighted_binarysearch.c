#include "../weighted_binarysearch.h"
#include <stdio.h>
#include "../randomlist.h"
void test1(){
    int a[10];
    for(int i=0;i<10;i++)a[i]=0;

    for(int i=0;i<100000;i++){
        a[lowint(10)]+=1;
    }
    for(int i=0;i<10;i++){
        printf("%d:%d\n",i,a[i]);
    }
}

void test2(){
    int a[10];
    for(int i=0;i<10;i++)a[i]=0;

    for(int i=0;i<100000;i++){
        a[highint(10)]+=1;
    }
    for(int i=0;i<10;i++){
        printf("%d:%d\n",i,a[i]);
    }
}


int main(){
    startrandom();
    test1();
    test2();
}