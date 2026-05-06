#include "../easy_solution.h"
#include "../types.h"
#include "../get.h"

#include <stdio.h>

void test1(){
    info_t info=get("Instances/ESC07.sop");
    int * bv=basic_valid(info);
    for(int i=0;i<info.len;i++){
        printf("%d ",bv[i]);

    }
    printf("\n");
}

int main(){
    test1();
    return 0;
}