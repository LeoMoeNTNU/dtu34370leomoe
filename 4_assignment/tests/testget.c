#include "../types.h"
#include "../get.h"
#include "stdio.h"
void printmatrix(info_t info){
    for(int i=0;i<info.len;i++){
        for(int j=0;j<info.len;j++){
            printf("%d ",info.p[i*info.len+j]);
        }
        printf("\n");
    }
}

void test1(){
    info_t info=get("Instances/ESC07.sop");
    printmatrix(info);
}

int main(){
    test1();

    return 0;
}