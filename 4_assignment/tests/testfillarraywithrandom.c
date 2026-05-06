#include "../fillarraywithrandom.h"
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

void test1(){
    printf("TEST1\n");
    int a[10];
    fillarraywithrandom(a, 10, 10);
    for(int i=0;i<10;i++){
        printf("%d ",a[i]);
    }
    printf("\n");

}

void test2(){
    printf("TEST2\n");
    int a[5];
    fillarraywithrandom(a, 5, 100);
    for(int i=0;i<5;i++){
        printf("%d ",a[i]);
    }
    printf("\n");

}


int main(){
    srand(time(NULL));
    test1();
    test2();
}