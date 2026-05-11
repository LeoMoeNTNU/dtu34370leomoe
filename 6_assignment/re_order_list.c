#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
int * re_ordered_list(int *ip, int len){
    int* i_new=malloc(sizeof(int)*len);
    int ind1;
    int ind2;
    int temp;
    for(int i=0;i<len;i++)i_new[i]=ip[i];

    for(int i=0;i<2*len;i++){
        ind1=rand()%len;
        ind2=rand()%len;
        temp=i_new[ind2];
        i_new[ind2]=i_new[ind1];
        i_new[ind1]=temp;
    }
    return i_new;
}