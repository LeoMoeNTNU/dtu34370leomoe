#include "types.h"
#include <stdio.h>
#include <stdlib.h>
void writetofile(int length, allprocs_t ap, const char* filename){
    int * p=malloc(sizeof(int)*length*length);

    for(int i=0;i<ap.len;i++){
        proc_list_t locp=ap.p[i];
        for( int j=0;j<locp.len;j++){
            p[locp.p[j].index]=locp.p[j].start;
        }
    }
    /*
    for(int i=0;i<length;i++){
        for(int j=0;j<length;j++){
            printf("%d ",p[i*length+j]);
            
        }
        printf("\n");
    }
    */

    FILE *f = fopen(filename, "w");
    if (!f) {
        fprintf(stderr, "Could not open file for writing\n");
        free(p);
        return;
    }

    // Write matrix to file
    for (int i = 0; i < length; i++) {
        for (int j = 0; j < length; j++) {
            fprintf(f, "%d ", p[i * length + j]);
            printf("%d ",p[i*length+j]);
        }
        fprintf(f, "\n");
        printf("\n");
    }

    fclose(f);
    free(p);


}