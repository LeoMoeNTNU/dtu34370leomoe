#include "types.h"
#include "isallowedtoplacehere.h"
#include "get_first_valid_index.h"
#include "infotools.h"
#include "init.h"
#include <stdbool.h>
#include "placeopinjob.h"
#include "printallprocs.h"
#include "totallength.h"
#include "writetofile.h"
//the functions that I will need: 
/*

int getfirstvalidindex(int firstvalidtime, int duration, op_in_proc_t* array, int arraylength);
int isallowedtoplacehere(info_t info, proc_list_t plt, int start, int end, int index);
void placeopinjob(op_in_proc_t* p, int len, op_in_proc_t in);


*/

int iteration(info_t info, allprocs_t ap,int duration, int processor,int locjob){
    int start =0;
    int timetotry;
    while(true){
        trynewattempt:
        //printf("inputting into timetotry: (%d,%d),len %d\n",start,duration,ap.p[processor].len);
        int timetotry=getfirstvalidindex(start,duration,ap.p[processor].p, ap.p[processor].len);
        
        //printf("trying to place at time (%d,%d) in processor%d\n",timetotry,timetotry+duration,processor);  
        for(int proc=0;proc<info.len;proc++){
            //printf("proc is %d\n",proc);
            if(proc==processor){continue;}
            int status= isallowedtoplacehere(info, ap.p[proc],timetotry, timetotry+duration, locjob);

            //TODO: in the function call the argument shouldn't be indextotry but the index, which we don't have right now.
            //To do this, I could have it in. 
            //There was a reason that I didn't do this earlier but I don't remember it right now.  
            if(status>0){
                //printf("at proc %d got a violation and status %d\n",proc,status);
                start=status;
                goto trynewattempt;
                

            }
            //printf("good\n");
           
            
        }
        //printf("should have %d good's after eachother!\n",info.len-1);
        return timetotry;

    }
}




ap_and_val_t value(info_t info, int* array){

    int len=info.len;
    int arraylength=len*len;
    int lengths[len];

    allprocs_t ap=init(info);
    for(int i=0;i<len;i++){lengths[i]=0;}
    for(int i=0;i<arraylength;i++){//should be arraylength.
        int index=array[i];
        int proc=processor(info,index);
        int dur=duration(info,index);
        int locjob=job(info,index);
        //printf("index %d: passing proc %d, duration %d, localjob %d into localiteration\n",i,proc,dur,locjob);
        int position=iteration(info,ap,dur, proc,locjob);
        //printf("3\n");

        //printf("placing process %d in processor %d and duration %d\n",index,proc,dur);
        //printf("got position: %d\n",position);
        int input=ap.p[proc].len;
        //printf("got here!\n");
        //printf("the length of the array is %d\n",input);

        op_in_proc_t toplace={position,position+dur,index};
        placeopinjob(ap.p[proc].p, input, toplace);
        //printf("2 got here as well!\n");
        ap.p[proc].len=ap.p[proc].len+1;//TODO: put this inside of the function instead. 
        //printallprocs(ap);
        //printf("hi\n");

    
    }
    
    int retlength= totallength(ap);
    //printf("total length is %d\n",retlength);
    
    
    return (ap_and_val_t){retlength,ap};
    
}
//pesudocode: 
/*
int value()
    for(operation in operations):
        get processor p of operation. 
        ask the processor where it can place it. 
        ask the others if that works. 
        if not get a new position
        (THIS SHOULD PROBABLY BE A WHILE LOOP) or just a while(true) with break. 
        
        
        then place it there. 
        placing it is a whole thing that I dont think it difficult, but has to be done correctly, as everything.  


        This is another function. 
    for each bucket, find the one that ends the latest. 
    return that value.  

*/