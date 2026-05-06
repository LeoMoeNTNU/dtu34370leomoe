#include "types.h"
#include <stdbool.h>

#include "infotools.h"
#include <stdio.h>


bool isswaplegal(info_t info, int index1, int index2, int* ip){
    int ind1;
    int ind2;
    if(index1<index2){
        ind1=index1;ind2=index2;
    }else{
        ind1=index2;ind2=index1;
    }
    
    int after=ip[ind1];
    int before=ip[ind2];
    int between;
    int betweenthesetwo=distance(info,before,after,false);
    //printf("is the swap itself illegal? %d\n", betweenthesetwo);

    //to clarify, before and after are after we have swapped it. 
    if(betweenthesetwo==-1){

        //printf("returning false!\n");
        return false;}

    for(int i=ind1+1;i<=ind2;i++){
        between=ip[i];
        if(distance(info,between,after,false)==-1){
            //printf("ret false 2\n");
            return false;}
        if(distance(info,before,between,false)==-1){
            return false;
        }
    }
    //printf("ret true\n");
    return true;
}

