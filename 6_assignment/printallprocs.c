#include "types.h" 
#include <stdio.h>
#include <stdlib.h>


void printallprocs(allprocs_t ap){
    printf("PRINTING ALL THE INFO:\n");
    for(int i=0;i<ap.len;i++){
        printf("proc %d:",i);
        proc_list_t proc=ap.p[i];
        for(int j=0;j<proc.len;j++){
            printf("(%d [%d ] %d) ",proc.p[j].start,proc.p[j].index,proc.p[j].end);
        }
        printf("\n");
    }
}

void killallprocs(allprocs_t ap){
    for(int i=0;i<ap.len;i++){
        free(ap.p[i].p);
    }
    free(ap.p);
}