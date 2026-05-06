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
#include <stddef.h>
#include <stdint.h>

long long millis_now(void) {
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    return ts.tv_sec * 1000LL + ts.tv_nsec / 1000000LL;
}




//I would argue that it should get the value in so that it doesnt have to calculate it itself. 
//Then it doesnt get calculated twice!
int * iterationswap(info_t info, int oldvalue, int * ip, bool* improved, int* newval){
    int arrlen=info.len*info.len;  
    
    int index1 = rand() % arrlen;
    int index2 = rand() % arrlen;
    int temp = ip[index1];
    ip[index1] = ip[index2];
    ip[index2] = temp;

    int newvalue = value(info,ip);

    if(newvalue<oldvalue){
        *newval=newvalue;
        *improved=true;
        return ip;
    }

    temp=ip[index1];
    ip[index1]=ip[index2];
    ip[index2]=temp;
    *improved=false;
    return ip;
}


int * re_order_neighbourhood(info_t info, int oldvalue, int * ip, bool* improved,int*newval){
    int arrlen = info.len * info.len;
    
    //decide which neighbourhood to re-order. 
    int neighbourhood = rand() % info.len;
    
    int indexes[info.len];
    int old_neighbourhood[info.len];
    
    int insertionindex = 0;
    int lowerbound = neighbourhood * info.len;
    int higherbound = (neighbourhood + 1) * info.len;
    
    for(int i = 0; i < arrlen; i++){
        if(ip[i] >= lowerbound && ip[i] < higherbound){
            indexes[insertionindex] = i;
            old_neighbourhood[insertionindex] = ip[i];
            insertionindex++;
        }
    }

    for(int i=0;i<info.len*2;i++){
        int p1 = rand()%info.len;
        int p2 = rand()%info.len;

        int ind1 = indexes[p1];
        int ind2 = indexes[p2];

        int temp   = ip[ind2];
        ip[ind2] = ip[ind1];
        ip[ind1] = temp;
    }
    //This should just do the swapping correctly. 
    //TODO: do the eval and return or not return. 

    int newthingy=value(info,ip);
    if(newthingy<oldvalue){
        *improved=true;
        *newval=newthingy;
        
        return ip;
    }
    

    for (int i = 0; i < info.len; i++)
        ip[indexes[i]] = old_neighbourhood[i];

    *improved=false;
    return ip;
}

int * re_order_neighbourhood_old(info_t info, int oldvalue, int * ip, bool* improved,int*newval){
    /*WHAT FUNCTION WILL DO: 
    1. Initialize some stuff. 
    2. decide which neighbourhood to work with. 
    
    */
    int old_for_testing=value(info,ip);
    if(oldvalue!=old_for_testing){printf("something wrong with the value passed in!\n");}
    
    int arrlen=info.len*info.len;
    int *newp=malloc(sizeof(int)*arrlen);
  //  printf("itswap 1\n");

    for(int i=0;i<arrlen;i++)newp[i]=ip[i];

    //decide which neighbourhood to re-order. 
    int neighbourhood=rand()%info.len;
    //where the indexes will be: 
    int indexes[info.len];
    int insertionindex=0;
    int lowerbound=neighbourhood*info.len;
    int higherbound=(neighbourhood+1)*info.len;
    for(int i=0;i<arrlen;i++){
        //This doesnt yet do what I want it to do.    
        if(newp[i]>=lowerbound && newp[i]<higherbound){
            indexes[insertionindex]=i;
            insertionindex++;
        }
    }
    //printf("indexes and what's in them!\n");
    for(int i=0;i<info.len;i++){
       // printf("index %d: value:%d\n",indexes[i],newp[indexes[i]]);
    }

    //other way of doing it: 
    for(int i=0;i<info.len*2;i++){
        int p1=rand()%info.len;
        int p2=rand()%info.len;

        int ind1=indexes[p1];
        int ind2=indexes[p2];

        int  temp=newp[ind2];
        newp[ind2]=newp[ind1];
        newp[ind1]=temp;
    }
    //This should just do the swapping correctly. 
    //TODO: do the eval and return or not return. 

    int newthingy=value(info,newp);
    if(newthingy<oldvalue){
        *improved=true;
        *newval=newthingy;
        free(ip);
        
        return newp;

    }else{
        *improved=false;
        free(newp);
        return ip;
    }
}





arr_and_val_t do_one_run2(long long intime, info_t info)
{
    int len=info.len;
    int arrlen=len*len;
    int* arr=randomlist(arrlen);
    bool improved;
    int bestvalue=value(info,arr);
    int newval;
    long long starttime=millis_now();
    int iterations=0;
    int improvements=0;
    int deprovements=0;

    int *(*bestone)(info_t, int, int *, bool *, int *);
    int *(*worstone)(info_t, int, int *, bool *, int *);
    int *(*temp)(info_t, int, int *, bool *, int *);//this one is for swapping!
    bestone=iterationswap;
    worstone=re_order_neighbourhood;

    int bestonekarma=0;
    int worstonekarma=0;

    while(millis_now()-starttime<intime){
        if(iterations % 5000 == 0 && iterations != 0){
            if(bestonekarma/2<worstonekarma){
                temp=bestone;
                bestone=worstone;
                worstone=temp;
            }
            bestonekarma=0;
            worstonekarma=0;
        }
        int* potbet;
        if(iterations%5000<3500){potbet=bestone(info,bestvalue,arr,&improved,&newval);}
        else{potbet=worstone(info,bestvalue,arr,&improved,&newval);}
        //int * potentially_better=iterationswap(info,bestvalue,arr,&improved,&newval);
        //int * potentially_better=re_order_neighbourhood(info,bestvalue,arr,&improved,&newval);

        if(improved){
            if(iterations%5000<3500)bestonekarma++;
            if(iterations%5000>=3500)worstonekarma++;

            arr=potbet;//I dont have to free because it already got freed inside...
            improvements++;
            bestvalue=newval;
        }else{
            deprovements++;
        }
        iterations++;

    }

    
    return (arr_and_val_t){.arr=arr,.val=bestvalue};
}
arr_and_val_t do_one_run2_2(long long intime, info_t info)
{
    int len=info.len;
    int arrlen=len*len;
    int* arr=randomlist(arrlen);
    bool improved;
    int bestvalue=value(info,arr);
    int newval;
    long long starttime=millis_now();
    int iterations=0;
    int improvements=0;
    int deprovements=0;

    int *(*bestone)(info_t, int, int *, bool *, int *);
    int *(*worstone)(info_t, int, int *, bool *, int *);
    int *(*temp)(info_t, int, int *, bool *, int *);//this one is for swapping!
    bestone=iterationswap;
    worstone=re_order_neighbourhood;

    int bestonekarma=0;
    int worstonekarma=0;

    while(millis_now()-starttime<intime){
        if(iterations % 5000 == 0 && iterations != 0){
            if(bestonekarma/2<worstonekarma){
                temp=bestone;
                bestone=worstone;
                worstone=temp;
            }
            bestonekarma=0;
            worstonekarma=0;
        }
        int* potbet;
        if(iterations%3<2){potbet=bestone(info,bestvalue,arr,&improved,&newval);}
        else{potbet=worstone(info,bestvalue,arr,&improved,&newval);}
        //int * potentially_better=iterationswap(info,bestvalue,arr,&improved,&newval);
        //int * potentially_better=re_order_neighbourhood(info,bestvalue,arr,&improved,&newval);

        if(improved){
            if(iterations%3<2) bestonekarma++;
            else worstonekarma++;

            arr=potbet;//I dont have to free because it already got freed inside...
            improvements++;
            bestvalue=newval;
        }else{
            deprovements++;
        }
        iterations++;

    }

    
    return (arr_and_val_t){.arr=arr,.val=bestvalue};
}
arr_and_val_t do_one_run3(long long intime, info_t info)
{
    int len=info.len;
    int arrlen=len*len;
    int* arr=randomlist(arrlen);
    bool improved;
    int bestvalue=value(info,arr);
    int newval;
    long long starttime=millis_now();
    int iterations=0;
    int improvements=0;
    int deprovements=0;

    int *(*bestone)(info_t, int, int *, bool *, int *);
    int *(*worstone)(info_t, int, int *, bool *, int *);
    int *(*temp)(info_t, int, int *, bool *, int *);//this one is for swapping!
    bestone=iterationswap;
    worstone=iterationswap;

    int bestonekarma=0;
    int worstonekarma=0;

    while(millis_now()-starttime<intime){
        if(iterations % 5000 == 0 && iterations != 0){
            if(bestonekarma/2<worstonekarma){
                temp=bestone;
                bestone=worstone;
                worstone=temp;
            }
            bestonekarma=0;
            worstonekarma=0;
        }
        int* potbet;
        if(iterations%5000<3500){potbet=bestone(info,bestvalue,arr,&improved,&newval);}
        else{potbet=worstone(info,bestvalue,arr,&improved,&newval);}
        //int * potentially_better=iterationswap(info,bestvalue,arr,&improved,&newval);
        //int * potentially_better=re_order_neighbourhood(info,bestvalue,arr,&improved,&newval);

        if(improved){
            if(iterations%5000<3500)bestonekarma++;
            if(iterations%5000>=3500)worstonekarma++;

            arr=potbet;//I dont have to free because it already got freed inside...
            improvements++;
            bestvalue=newval;
        }else{
            deprovements++;
        }
        iterations++;

    }

    //printf("iterations:%d\n",iterations);
    return (arr_and_val_t){.arr=arr,.val=bestvalue};
}

arr_and_val_t do_one_run4(long long intime, info_t info)
{
    int len=info.len;
    int arrlen=len*len;
    int* arr=randomlist(arrlen);
    bool improved;
    int bestvalue=value(info,arr);
    int newval;
    long long starttime=millis_now();
    int iterations=0;
    int improvements=0;
    int deprovements=0;

    int *(*bestone)(info_t, int, int *, bool *, int *);
    int *(*worstone)(info_t, int, int *, bool *, int *);
    int *(*temp)(info_t, int, int *, bool *, int *);//this one is for swapping!
    bestone=re_order_neighbourhood;
    worstone=re_order_neighbourhood;

    int bestonekarma=0;
    int worstonekarma=0;

    while(millis_now()-starttime<intime){
        if(iterations % 5000 == 0 && iterations != 0){
            if(bestonekarma/2<worstonekarma){
                temp=bestone;
                bestone=worstone;
                worstone=temp;
            }
            bestonekarma=0;
            worstonekarma=0;
        }
        int* potbet;
        if(iterations%5000<3500){potbet=bestone(info,bestvalue,arr,&improved,&newval);}
        else{potbet=worstone(info,bestvalue,arr,&improved,&newval);}
        //int * potentially_better=iterationswap(info,bestvalue,arr,&improved,&newval);
        //int * potentially_better=re_order_neighbourhood(info,bestvalue,arr,&improved,&newval);

        if(improved){
            if(iterations%5000<3500)bestonekarma++;
            if(iterations%5000>=3500)worstonekarma++;

            arr=potbet;//I dont have to free because it already got freed inside...
            improvements++;
            bestvalue=newval;
        }else{
            deprovements++;
        }
        iterations++;

    }
        //printf("iterations: %d\n",iterations);

    
    return (arr_and_val_t){.arr=arr,.val=bestvalue};
}

arr_and_val_t do_one_run4_2(long long intime, info_t info)
{
    int len=info.len;
    int arrlen=len*len;
    int* arr=randomlist(arrlen);
    bool improved;
    int bestvalue=value(info,arr);
    int newval;
    long long starttime=millis_now();
    int iterations=0;
    int improvements=0;
    int deprovements=0;

    int *(*bestone)(info_t, int, int *, bool *, int *);
    int *(*worstone)(info_t, int, int *, bool *, int *);
    int *(*temp)(info_t, int, int *, bool *, int *);//this one is for swapping!
    bestone=re_order_neighbourhood;
    worstone=re_order_neighbourhood;

    int bestonekarma=0;
    int worstonekarma=0;

    while(millis_now()-starttime<intime){
        if(iterations % 5000 == 0 && iterations != 0){
            if(bestonekarma/2<worstonekarma){
                temp=bestone;
                bestone=worstone;
                worstone=temp;
            }
            bestonekarma=0;
            worstonekarma=0;
        }
        int* potbet;
        if(iterations%5000<3500){potbet=bestone(info,bestvalue,arr,&improved,&newval);}
        else{potbet=worstone(info,bestvalue,arr,&improved,&newval);}
        //int * potentially_better=iterationswap(info,bestvalue,arr,&improved,&newval);
        //int * potentially_better=re_order_neighbourhood(info,bestvalue,arr,&improved,&newval);

        if(improved){
            if(iterations%5000<3500)bestonekarma++;
            if(iterations%5000>=3500)worstonekarma++;

            arr=potbet;//I dont have to free because it already got freed inside...
            improvements++;
            bestvalue=newval;
        }else{
            deprovements++;
        }
        iterations++;

    }

    //printf("iterations: %d\n",iterations);
    return (arr_and_val_t){.arr=arr,.val=bestvalue};
}

int wholefunc2(char* cp, char* towriteto, int intime_sec, int num_runs){
    long long intime = (long long)intime_sec * 1000LL;
    if (num_runs<=0)
        num_runs=1;

    info_t info=get(cp);

    bool assigned = false;
    arr_and_val_t best= {.arr=0,.val=__INT_MAX__};

    long long runtime = intime/num_runs;
    for(int i=0;i<num_runs;i++){
        arr_and_val_t current=do_one_run2(runtime,info);
        if(!assigned || current.val<best.val){
            if(assigned)
                free(best.arr);
            assigned=true;
            best=current;
        }
        else{
            free(current.arr);
        }
    }
    
    ap_and_val_t toprint=value_with_procs(info,best.arr);
    //printf("val: %d\n",toprint.val);
    //printallprocs(toprint.ap);
    writetofile(info.len,toprint.ap,towriteto);
    killallprocs(toprint.ap);
    free(best.arr);
    return best.val;
}
int wholefunc2_2(char* cp, char* towriteto, int intime_sec, int num_runs){
    long long intime = (long long)intime_sec * 1000LL;
    if (num_runs<=0)
        num_runs=1;

    info_t info=get(cp);

    bool assigned = false;
    arr_and_val_t best= {.arr=0,.val=__INT_MAX__};

    long long runtime = intime/num_runs;
    for(int i=0;i<num_runs;i++){
        arr_and_val_t current=do_one_run2_2(runtime,info);
        if(!assigned || current.val<best.val){
            if(assigned)
                free(best.arr);
            assigned=true;
            best=current;
        }
        else{
            free(current.arr);
        }
    }
    
    ap_and_val_t toprint=value_with_procs(info,best.arr);
    //printf("val: %d\n",toprint.val);
    //printallprocs(toprint.ap);
    writetofile(info.len,toprint.ap,towriteto);
    killallprocs(toprint.ap);
    free(best.arr);
    return best.val;
}
int wholefunc3(char* cp, char* towriteto, int intime_sec, int num_runs){
    long long intime = (long long)intime_sec * 1000LL;
    if (num_runs<=0)
        num_runs=1;

    info_t info=get(cp);

    bool assigned = false;
    arr_and_val_t best= {.arr=0,.val=__INT_MAX__};

    long long runtime = intime/num_runs;
    for(int i=0;i<num_runs;i++){
        arr_and_val_t current=do_one_run3(runtime,info);
        if(!assigned || current.val<best.val){
            if(assigned)
                free(best.arr);
            assigned=true;
            best=current;
        }
        else{
            free(current.arr);
        }
    }
    
    ap_and_val_t toprint=value_with_procs(info,best.arr);
    //printf("val: %d\n",toprint.val);
    //printallprocs(toprint.ap);
    writetofile(info.len,toprint.ap,towriteto);
    killallprocs(toprint.ap);
    free(best.arr);
    return best.val;
}

int wholefunc4(char* cp, char* towriteto, int intime_sec, int num_runs){
    long long intime = (long long)intime_sec * 1000LL;
    if (num_runs<=0)
        num_runs=1;

    info_t info=get(cp);

    bool assigned = false;
    arr_and_val_t best= {.arr=0,.val=__INT_MAX__};

    long long runtime = intime/num_runs;
    for(int i=0;i<num_runs;i++){
        arr_and_val_t current=do_one_run4(runtime,info);
        if(!assigned || current.val<best.val){
            if(assigned)
                free(best.arr);
            assigned=true;
            best=current;
        }
        else{
            free(current.arr);
        }
    }
    
    ap_and_val_t toprint=value_with_procs(info,best.arr);
    //printf("val: %d\n",toprint.val);
    //printallprocs(toprint.ap);
    writetofile(info.len,toprint.ap,towriteto);
    killallprocs(toprint.ap);
    free(best.arr);
    return best.val;
}

int wholefunc4_2(char* cp, char* towriteto, int intime_sec, int num_runs){
    long long intime = (long long)intime_sec * 1000LL;
    if (num_runs<=0)
        num_runs=1;

    info_t info=get(cp);

    bool assigned = false;
    arr_and_val_t best= {.arr=0,.val=__INT_MAX__};

    long long runtime = intime/num_runs;
    for(int i=0;i<num_runs;i++){
        arr_and_val_t current=do_one_run4(runtime,info);
        if(!assigned || current.val<best.val){
            if(assigned)
                free(best.arr);
            assigned=true;
            best=current;
        }
        else{
            free(current.arr);
        }
    }
    
    ap_and_val_t toprint=value_with_procs(info,best.arr);
    //printf("val: %d\n",toprint.val);
    //printallprocs(toprint.ap);
    writetofile(info.len,toprint.ap,towriteto);
    killallprocs(toprint.ap);
    free(best.arr);
    return best.val;
}

int wholefunc(char* cp, char* towriteto, int intime_sec){
    long long intime = (long long)intime_sec * 1000LL;
    info_t info=get(cp);
    int len=info.len;
    int arrlen=len*len;
    int* arr=randomlist(arrlen);
    int bestvalue=value(info,arr);
    bool improved;
    int newval;
    long long starttime=millis_now();
    int iterations=0;
    int improvements=0;
    int deprovements=0;

    int *(*bestone)(info_t, int, int *, bool *, int *);
    int *(*worstone)(info_t, int, int *, bool *, int *);
    int *(*temp)(info_t, int, int *, bool *, int *);//this one is for swapping!
    bestone=iterationswap;
    worstone=re_order_neighbourhood;

    int bestonekarma=0;
    int worstonekarma=0;


    while(millis_now()-starttime<intime){
    //for(int i=0;i<10000;i++){

        //What will happen now is that I will implement a system for running both. 
        //For each iteration, which will be 16 iterations:
        /*
        if iterations%5000==0: re-calibrate.
            cant be global improvements because then one will sometimes just take it. 
            as such, we just do local improvements.  
        if iterations/5000<3500: function =bestone
        if iterations/5000>=3500: function=worstone.

        if(improved&iterations%5000<3500):bestones++;
        else: worstones++;
        and then I need to run the fast one!
        */
        if(iterations % 5000 == 0 && iterations != 0){
            if(bestonekarma/2<worstonekarma){
                temp=bestone;
                bestone=worstone;
                worstone=temp;
            }
            bestonekarma=0;
            worstonekarma=0;
        }
        int* potbet;
        if(iterations % 5000 < 3500) {
            potbet = bestone(info,bestvalue,arr,&improved,&newval);
        }
        else {
            potbet = worstone(info,bestvalue,arr,&improved,&newval);
        }
        //int * potentially_better=iterationswap(info,bestvalue,arr,&improved,&newval);
        //int * potentially_better=re_order_neighbourhood(info,bestvalue,arr,&improved,&newval);

        if(improved){
            if(iterations%5000<3500)bestonekarma++;
            if(iterations%5000>=3500)worstonekarma++;
            arr=potbet;//I dont have to free because it already got freed inside...
            improvements++;
            bestvalue=newval;
        }else{
            deprovements++;
        }
        iterations++;

    }
    ap_and_val_t toprint=value_with_procs(info,arr);
    // printf("wholefunc 2\n");
    // printf("val: %d, total iterations: %d\n",toprint.val,iterations);
    // printf(" improvements: %d, deprovements: %d\n",improvements,deprovements);
    //printallprocs(toprint.ap);
    writetofile(len,toprint.ap,towriteto);
    killallprocs(toprint.ap);
    free(arr);
    return toprint.val;
} 