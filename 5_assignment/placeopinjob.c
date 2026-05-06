#include "types.h"
#include <stdio.h>

//This one is going to write to one higher because it exists that this exists.
//assumes that it is a valid insert.
void placeopinjob(op_in_proc_t* p, int len, op_in_proc_t in){
    //printf("len in is %d\n",len);

    op_in_proc_t flowingdown=in;
    //printf("1\n");
    op_in_proc_t temp;
    //printf("2\n");
    for(int i=0;i<len;i++){

        //printf("3, not expecting to see this one with i=%d and len=%d\n",i,len);
        if(flowingdown.start<p[i].start){
            if(flowingdown.end>p[i].start){printf("someone has passed in something wrong in placeinjob\n");}
            temp=p[i];
            p[i]=flowingdown;
            flowingdown=temp;
        
        }
    }
    //printf("expecting this to be right before segfault\n");
    p[len]=flowingdown;
    //printf("this one I shouldn't see!\n");
}