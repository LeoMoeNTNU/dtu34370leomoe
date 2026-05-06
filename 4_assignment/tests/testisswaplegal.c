#include "../types.h"
#include "../isswaplegal.h"

#include <stdbool.h>
#include "../get.h"
#include <stdio.h>
#include "../infotools.h"

void test1(){
    printf("TEST1:\n");
    info_t info=get("Instances/ESC07.sop");
    printf("checking (0,1) should be 0 and is %d\n",distance(info,0,1,false));
        printf("checking (1,0) should be -1 and is %d\n",distance(info,1,0,false));


    int a[]={0,1,2};
    bool shouldbeno=isswaplegal(info,0,1,a);
    if(shouldbeno!=0){
        printf("the answer should be 0 and it is %d\n",shouldbeno);

    }
}

void test2(){
    printf("TEST 2:\n");
    info_t info=get("Instances/ESC07.sop");
    int a[]={1,4};
    bool shouldbeno=isswaplegal(info,0,1,a);
    if(shouldbeno!=false){
        printf("the answer should be 0 and it is %d\n",shouldbeno);

    }
    shouldbeno=isswaplegal(info,1,0,a);
      if(shouldbeno!=false){
        printf("the answer should be 0 and it is %d\n",shouldbeno);

    }
}


void test3(){
    printf("TEST 3:\n");
    info_t info=get("Instances/ESC07.sop");
    int a[]={4,1};
    bool shouldbeyes=isswaplegal(info,1,0,a);
    if(shouldbeyes!=1){
        printf("the answer should be 1 and it is %d\n",shouldbeyes);

    }
    shouldbeyes=isswaplegal(info,0,1,a);
      if(shouldbeyes!=1){
        printf("the answer should be 1 and it is %d\n",shouldbeyes);

    }
}

void test4(){
    printf("TEST 4:\n");
    info_t info=get("Instances/ESC07.sop");
    int a[]={1,4,2};
    bool shouldbeno=isswaplegal(info,0,2,a);
    if(shouldbeno!=0){
        printf("the answer should be 0 and it is %d\n",shouldbeno);
    }
    
  
}


void test5(){
    printf("TEST5:\n");
    info_t info = get("Instances/ESC12.sop");
    int a[]={0,1,2};
    bool shouldbeno=isswaplegal(info,0,1,a);
    if(shouldbeno!=false){
        printf("there is an error here!\n");
    }
}

void test6(){
    printf("TEST6\n");
    info_t info=get("Instances/ESC07.sop");
    int a[]={0,1,2,3,4,6,7,5,8};
    bool shouldbeno=isswaplegal(info,7,2,a);
    if(shouldbeno!=false){
        printf("error in test 6!\n");
    }
}

int main(){
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();
    return 0;
}