#include "../types.h"
#include "../tl_contains.h"
#include <stdio.h>
#include "../init_tl.h"
#include "../insert_into_tl.h"

void test1(){
    printf("TEST1\n");
    tl_t tl= init_tb_list(2, 3);
    int a[]={1,2,3};
    insert_into_tl(tl, a);
    int b[]={1,2,3};
    if(!tl_contains(tl, b)){
        printf("it didn't have it for some reason!");

    int c[]={3,4,5};
    int d[]={4,4,4};
    if(tl_contains(tl,b)){
        printf("shouldn't have b");
    }
    if(!tl_contains(tl,c)){
        printf("should have c");
    }
    if(!tl_contains(tl,d))printf("should also have d");
    }
    printf("TEST1 done!\n");
}

int main(){
    test1();
    return 0;
}

