#include <stdbool.h>
#include "../re_order_list.h"
#include <stdio.h>
void test1(){
    printf("TEST1:\n"); 
    int arr[]={6,3,2};
    int * next= re_ordered_list(arr, 3);
    for(int i=0;i<3;i++){
        bool found=false;
        for(int j=0;j<3;j++){
            if(arr[i]==next[j])found=true;
        }
        if(!found)printf("couldn't find %d\n",arr[i]);
    }

}

int main(){

    test1();
    return 0;
}