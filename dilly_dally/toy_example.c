#include <stdio.h>

void printarray(int *p, int len){
    for(int i=0;i<len;i++){
        printf("%d ",p[i]);
    }
    printf("\n");
}

void printfunc(void(*f)()){
    f();
}

int main(){
    int a[3];
    a[0]=2;
    a[1]=3;
    a[2]=43;
    printfunc(printarray(a,3));

    return 0;
}