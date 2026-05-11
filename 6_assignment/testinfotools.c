#include "get.h"
#include "infotools.h"
#include <stdlib.h>
#include <stdio.h>
/*
int job(info_t info, int index);

int duration(info_t info, int index);

int processor(info_t info, int index);
*/
void test1(){
    info_t info= get("Instances/CloudComp_instances/tai4_4_2.txt");
    for(int i=0;i<info.len*info.len;i++){
        printf("operation %d has job %d, duration %d and is in processor %d\n",
            i,job(info,i),duration(info,i),processor(info,i));
    }

}

int main(){

    test1();


}