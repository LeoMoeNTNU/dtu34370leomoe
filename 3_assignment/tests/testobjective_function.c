#include "../objective_function.h"
#include "../types.h"
#include "../get.h"

#include "../randomlist.h"
#include <stdio.h>


void test1(){
    info_t info=get("Instances/CloudComp_instances/tai4_4_2.txt");
    int array[]={0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
    printf("test 1 value: %d\n",value(info,array).val);

}

void test2(){
    info_t info=get("Instances/CloudComp_instances/tai15_15_2.txt");
    int a[15*15];
    for(int i=0;i<15*15;i++){
        a[i]=i;
    }
    for(int i=0;i<15*15;i++){
        printf("%d ",a[i]);
    }
    printf("\n");
    printf("test 2 value: %d\n",value(info,a).val);

}

void test3(){
    info_t info=get("Instances/CloudComp_instances/tai4_4_2.txt");
    int *array=randomlist(info.len*info.len);
    printf("test 3 value: %d\n",value(info,array).val);

}

int main(){
    startrandom();
    //test1();
    //test2();
    test3();
    return 0;

}