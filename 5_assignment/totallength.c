#include "types.h"
#include <stdio.h>
#include <stdlib.h>


int totallength(allprocs_t ap){
    int retlen=0;
    for(int i=0;i<ap.len;i++){
        proc_list_t proc=ap.p[i];
        int len=proc.p[proc.len-1].end;
        if(len>retlen){retlen=len;}
    }
    return retlen;
}