#include "types.h"
#include "infotools.h"
#include <stdbool.h>
#include <stdio.h>

bool overlapping(int start1, int end1, int start2, int end2){
    return start1<end2&&start2<end1;
}

//This one will have a bit of a standard. 
//It will return 0 if it is allowed. If the value is over 0, then it is the end of the thing that we have currently crashing with!
int isallowedtoplacehere(info_t info, proc_list_t plt, int time, int end,int locjob){
    if(info.len>100){
        printf("something wrong has been put in here!");
    }
    int start=time;
    
    int start2;
    int end2;
    for(int i=0;i<plt.len;i++){
        op_in_proc_t op=plt.p[i];
        start2=op.start;
        end2=op.end;
        if(op.index==-1){printf("something is wrong in here, we went too far in the list");}
        if(overlapping(start,end,start2,end2)&&(locjob==job(info,op.index))){
            //TODO: shouldnt be processor, it should instead be the job.
            //I dont know exactly where this one is right now. 
            return op.end;
        }
    }
    return 0;



}