#include "types.h"
#include "randomlist.h"
#include "get.h"
#include "objective_function.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "printallprocs.h"
#include "writetofile.h"
#include <stddef.h>
#include <stdint.h>
#include "weighted_binarysearch.h"
#include "int_arr_crossover.h"

long long millis_now(void) {
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    return ts.tv_sec * 1000LL + ts.tv_nsec / 1000000LL;
}


#define POPULATION 40

void swap_up(int j, int *ip, int** ipp){
    int swap_int;
    int *swap_p;
    swap_int=ip[j];
    ip[j]=ip[j+1];
    ip[j+1]=swap_int;

    //swap the pointers: 
    swap_p=ipp[j];
    ipp[j]=ipp[j+1];
    ipp[j+1]=swap_p;
}

int wholefunc(char* cp, char* towriteto, int intime_sec){
    long long intime = (long long)intime_sec * 1000LL;
    info_t info=get(cp);
    int arrlen=info.len*info.len;
    int *sols[POPULATION];
    int sol_vals[POPULATION];
    long long starttime=millis_now();
    //printf("got here!\n");
    //this is to initialize a random population. 
    for(int i=0;i<POPULATION;i++){
        int* ip=randomlist(arrlen);
        sols[i]=ip;
        sol_vals[i]=value(info,sols[i]);

    }

    //now I want to get it sorted:
    //I can probably change j<POPULATION-1 to j<POPULATION-1-i if I so wish because thats how bubble sort works. 
    for(int i=0;i<POPULATION;i++){
        for(int j=0;j<POPULATION-1;j++){
            if(sol_vals[j]>sol_vals[j+1]){
               swap_up(j,sol_vals,sols);
            }
        }
    } 
    /*
    for(int i=0;i<POPULATION;i++){
        printf("%d: %d\n",i,sol_vals[i]);
    }
    */
    //printf("got here 2\n");
    int *current;
    int current_value;
    while(millis_now()-starttime<intime){
        //printf("got here 3\n");
        int firstint=highint(POPULATION);
        int secint=highint(POPULATION);
        current=malloc(sizeof(int)*arrlen);
        //printf("first int: %d, second int: %d\n",firstint,secint);
        /*
        for(int i=0;i<arrlen;i++){
            printf("%d ",sols[firstint][i]);
        }printf("\n");
        */
        int_arr_crossover(sols[firstint], sols[secint], current, arrlen);
        //printf("got a value\n");
        current_value=value(info,current);
        //printf("the value is %d\n",current_value);
        //printf("got here 4\n");
        
        if(current_value>sol_vals[0]){
            free(current);
            continue;

        }
        sol_vals[0]=current_value;
        free(sols[0]);
        sols[0]=current;
        int index=0;
        //printf("got here 5\n");
        while(sol_vals[index]<sol_vals[index+1]&&index<POPULATION){
            swap_up(index,sol_vals,sols);
        }
        //printf("got here 6\n");
    }
    ap_and_val_t toprint=value_with_procs(info,sols[0]);
    writetofile(info.len,toprint.ap,towriteto);
    killallprocs(toprint.ap);
    /*
    for(int i=0;i<POPULATION;i++){
        printf("%d ",sol_vals[i]);
    }printf("\n");
    */
   printf("final value: %d\n",toprint.val);
   for(int i=0;i<POPULATION;i++){
    free(sols[i]);
   }
    return toprint.val;
    
} 