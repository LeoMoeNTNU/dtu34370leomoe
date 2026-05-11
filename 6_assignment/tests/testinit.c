#include "../types.h"
#include "../init.h"
#include "../get.h"

#include "stdio.h"

void test1(){
    info_t info= get("Instances/CloudComp_instances/tai4_4_2.txt");
    allprocs_t ap=init(info);
    printf("amount of processors:%d\n",ap.len);
    for(int i=0;i<ap.len;i++){
        proc_list_t plt=ap.p[i];
        printf("processor %d has %d operations in it!\n",i,plt.len);
        for(int j=0;j<plt.len;j++){
            printf("    index %d,%d is %d and should be -1 during init\n",i,j,plt.p[i].index);
        }

    }

}

void test(char* cp){
    printf("TEST:\n");
    info_t info= get(cp);
    allprocs_t ap=init(info);
   

}





int main(){
    test1();
    test("Instances/CloudComp_instances/tai4_4_2.txt");
        test("Instances/CloudComp_instances/tai10_10_1.txt");

            test("Instances/CloudComp_instances/tai20_20_1.txt");

    

    return 0;
}