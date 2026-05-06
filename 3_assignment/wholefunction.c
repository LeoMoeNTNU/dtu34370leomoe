/* pseudocode: 
    generate the random array. 
    
    while time is less than time: 
        make a swap. 
        check if the swap is better, or how much worse it is. 
        the objective function needs to both return a value and a pointer. 
            it can write to an int pointer to get it that way. 

        if it is better, do the swap. 
        if it is worse, chose it with a likelihood based on how much time has been spent. 
        



*/
#include "types.h"
#include "randomlist.h"
#include "get.h"
#include "objective_function.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "printallprocs.h"
#include "writetofile.h"


void wholefunc(char* cp,char * towriteto,int intime){
    startrandom();
    info_t info=get(cp);
    int len=info.len;
    int arrlen=len*len;
    int arr[len*len];
    randomlist(arr,len*len);
    ap_and_val_t valmain=value(info,arr);
    int nextarr[len*len];
    

    int index1;
    int index2;
    int temp;

    
    int starttime=time(NULL);
    int iterations=0;
    printf("doing things\n");

    while(time(NULL)-starttime<intime){
        iterations++;
        randomlist(nextarr,len*len);

        ap_and_val_t nextval=value(info,nextarr);
        if(nextval.val<valmain.val){
            printf("going from %d to %d\n",valmain.val,nextval.val);
            killallprocs(valmain.ap);
            for(int i=0;i<len*len;i++){arr[i]=nextarr[i];}
            
            valmain=nextval;
        }else{
            killallprocs(nextval.ap);
        }
    }
    printf("val: %d, total iterations: %d\n",valmain.val,iterations);
    //TODO: write to file
    writetofile(len,valmain.ap,towriteto);
}