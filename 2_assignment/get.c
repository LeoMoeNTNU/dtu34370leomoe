#include <stdio.h>
#include <stdlib.h>
#include "types.h"

int howmanyints(int x){
    return (x*(x-1))/2;
}

typedef struct {
    int row;
    int col;
}rowcol_t;

rowcol_t next(rowcol_t rc, int length){
    if(rc.col<length-1){
        //printf("using this one!\n");
        return (rowcol_t){rc.row,rc.col+1};
    }
    else{
        return (rowcol_t){rc.row+1,rc.row+2};
    }
}

info_t get(const char * filename){

    info_t ret={0,0,0,0};
    FILE* file= fopen(filename, "r");
    if(!file){
        printf("couldn't open file\n");
        return (info_t){0,0,0,0};
    }

    int countedlines=0;
    
    while(countedlines<1){
        int letter1 =fgetc(file);
        if(letter1==EOF){
            printf("less than 4 lines!\n");
            return (info_t){0,0,0,0};
        }
        if(letter1=='\n'){
            countedlines++;
        }
    }


    int rowsandcols;
    int valid_items=fscanf(file, "%d", &rowsandcols);
    //printf("there are %d items!\n",rowsandcols);
    countedlines=0;
    while(countedlines<2){
        int letter1 =fgetc(file);
        if(letter1==EOF){
            printf("leo error message!\n");
            return (info_t){0,0,0,0};
        }
        if(letter1=='\n'){
            countedlines++;
        }
    }

    ret.tasks=rowsandcols;
    ret.rev_mat=malloc(sizeof(int)*rowsandcols*rowsandcols);
    ret.rev_values=malloc(sizeof(int)*ret.tasks);
  
    //printf("got here 1\n");
    for(int i=0;i<rowsandcols;i++){
        for(int j=0;j<rowsandcols;j++){
            rev_mat_insert(i,j,-1,ret);
            //I put everything to -1 so that I can later check.
            //If anything is -1, something is wrong because nothing is supposed to be -1.
        }
    }
    //printf("got here 2\n");
    //These ones need to be 0 because they are to themselves. 
    for(int i=0;i<rowsandcols;i++){
        rev_mat_insert(i,i,0,ret);
    }
    //printf("got here 3\n");
    int toInsert;
    int stat;
    int howmany=howmanyints(rowsandcols);

     for(int i=0;i<ret.tasks;i++){
        stat=fscanf(file, "%d",&toInsert);
        ret.rev_values[i]=toInsert;   
    }
    rowcol_t n={0,1};
    for(int i=0;i<howmany;i++){
        stat=fscanf(file, "%d", &toInsert);
        //printf("number to insert: %d\n",toInsert);
        rev_mat_insert(n.row,n.col,toInsert,ret);
        rev_mat_insert(n.col,n.row,toInsert,ret);
        n=next(n,ret.tasks);

        //printf("algo\n");
    }
    //printf("got here 4\n");

    for(int i=0; i<ret.tasks;i++){
        for(int j=0; j<ret.tasks;j++){
            //printf("%d ",rev_mat_get(i,j,ret));
        }
        //printf("\n");
    }
    //printf("hi1\n");
    stat= fscanf(file, "%d",&toInsert);
    //printf("hi2\n");
    //printf("amount of buckets:%d\n",toInsert);
    //printf("hi3\n");
    ret.buckets=toInsert;
    //printf("my corrupt top size:%ld which is %d ints\n",sizeof(int)*ret.tasks,ret.tasks);
    ret.prodtimes=malloc(sizeof(int)*ret.tasks);
     stat=fscanf(file,"%d",&toInsert);
     ret.planning_horizon=toInsert;
    
    for(int i=0;i<ret.tasks;i++){
        stat=fscanf(file,"%d",&toInsert);
        //printf("prod time %d: %d\n",i,toInsert);
        ret.prodtimes[i]=toInsert;
    }

    //printf("got here 5\n");
    return ret;
    


}