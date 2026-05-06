#include "../randomlist.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdbool.h>



void test1(){
    int * arr=randomlist(5);
    for(int i=0;i<5;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");

}

void test2(){
    int count=0;
    for(int i=0;i<100000;i++){
        if(yesorno(60, 50)){count++;}

    }
    printf("50 out of 60 is approximately %d/100000\n",count);
    
    
}

void test3(){
    int count=0;
    for(int i=0;i<100000;i++){
        if(yesorno(60, 2)){count++;}

    }
    printf("2 out of 60 is approximately %d/100000\n",count);
    
    
}




int main(){
    startrandom();
    test1();
    test2();
    test3();
    return 0;
}