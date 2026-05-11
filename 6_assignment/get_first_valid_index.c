#include <stdio.h>
#include "types.h"
#include <stdbool.h>
int mmax(int a, int b){
    if(a>=b){return a;}
    return b;
}


int getfirstvalidindex(int firstvalidtime, int duration, op_in_proc_t* array, int arraylength){
    int firstvalidstart;
    int index=0;
    int end1;
    int start2;
    
    if(arraylength==0){
        //printf("found ourself in an empty list and returned immediately!\n");
        return firstvalidtime;}



    while(true){

        if(index==0){
            //printf("we are at the beginning!\n");
            end1=0;   
            start2=array[0].start;
            //printf("at beginning, index %d!\n",index);
            //printf("in the beginning, the gap is between %d and %d!\n",end1,start2);         
        }
        if(index==arraylength){
            
            //printf("at the end, index %d\n",index);
            end1=array[index-1].end;
            int retval=mmax(firstvalidtime,end1);
            return retval;
            /*
            printf("end at %d is %d\n",index-1,end1);
            start2=100000;//just  a big value!
            */
            //printf("the interval we look at %d and %d\n",end1,start2);

        }
        if(index!=0&&index!=arraylength-1){
            //printf("in the middle, index %d!\n",index);
            //printf("using indexes %d and %d to look up!\n",index-1,index);
            end1=array[index-1].end;
            start2=array[index].start;
            //printf("neither at the end or the beginning!\n");
            //printf("in the middle, index: %d, end1:%d, start2: %d\n",index,end1,start2);
             //printf("in the middle, index: %d, end1:%d, start2: %d\n",index,end1,start2);
        }

        
        firstvalidstart=mmax(end1,firstvalidtime);
   
        if(start2<firstvalidtime){
            //printf("next one was too early and we skipped it!\n");
            index++;
            continue;}
        //printf("at index %d, firstvalidstart is %d and start2 is %d\n",index,firstvalidstart,start2);
        int localgap=start2-firstvalidstart;
        if(localgap>=duration){
            //printf("we found a valid skip!\n");
            return firstvalidstart;}
        //printf("we found an invalid gap and just skip then\n");
        index++;





    }
}