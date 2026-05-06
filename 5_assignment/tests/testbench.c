#include <stdio.h>
#include <stdbool.h>




bool overlapping(int start1, int end1, int start2, int end2){
    return start1<end2&&start2<end1;
}

int main(){
    printf("should be 1, is %d\n",overlapping(0,2,1,3));

    printf("should be 0, is %d\n",overlapping(0,1,2,3));

        printf("should be 1, is %d\n",overlapping(0,3,1,2));

    




}