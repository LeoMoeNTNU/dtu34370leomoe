#include <stdio.h>
#include <stdlib.h>
#include "types.h"

info_t get(const char * filename){

    info_t ret={0,0,0};
    FILE* file= fopen(filename, "r");
    if(!file){
        printf("couldn't open file\n");
        return (info_t){0,0,0};
    }

    int countedlines=0;
    
    while(countedlines<1){
        int letter1 =fgetc(file);
        if(letter1==EOF){
            printf("less than 4 lines!\n");
            return (info_t){0,0,0};
        }
        if(letter1=='\n'){
            countedlines++;
        }
    }


    int import_num;
    int valid_items=fscanf(file, "%d", &import_num);
    ret.len=import_num;
    //printf("processors, jobs and operations per job: %d\n",import_num);
    countedlines=0;

    while(countedlines<2){
        int letter1 =fgetc(file);
        if(letter1==EOF){
            printf("less than 4 lines!\n");
            return (info_t){0,0,0};
        }
        if(letter1=='\n'){
            countedlines++;
        }
    }
    ret.duration=malloc(sizeof(int)*ret.len*ret.len);
    int found_val;
    for(int i=0;i<ret.len*ret.len;i++){
        valid_items=fscanf(file, "%d", &found_val);
        ret.duration[i]=found_val;
        //printf("found num: %d\n",found_val);
    }
    countedlines=0;
    while(countedlines<2){
        int letter1 =fgetc(file);
        if(letter1==EOF){
            printf("less than 4 lines!\n");
            return (info_t){0,0,0};
        }
        if(letter1=='\n'){
            countedlines++;
        }
    }
    ret.processors=malloc(sizeof(int)*ret.len*ret.len);
    found_val;
    for(int i=0;i<ret.len*ret.len;i++){
        valid_items=fscanf(file, "%d", &found_val);
        ret.processors[i]=found_val-1;
        
        //printf("found num: %d\n",found_val);
    }

    return ret;    


}

info_t get_random(int widthandlength){
    int len=widthandlength;
    int * duration=malloc(sizeof(int)*len*len);
    int * processors=malloc(sizeof(int)*len*len);
    info_t ret;
    ret.len=len;
    ret.duration=duration;
    ret.processors=processors;

    //setting duration to random numbers...
    for(int i=0;i<len*len;i++){
        duration[i]=rand()%100;
    }
    //now we set the processors up before we shuffle them...
    for(int i=0;i<len;i++){
        for(int j=0;j<len;j++){
            processors[i*len+j]=j;
        }
    }

    //This is the shuffle operation. 
    //In the previous code base, this was shuffled, so I do it here as well. 
    for(int i=0;i<len;i++){
        int * basepointer=processors+i*len;
        for(int j=0;j<len;j++){
            int index1=j;
            int index2=rand()%len;
            int temp;
            temp=basepointer[index1];
            basepointer[index1]=basepointer[index2];
            basepointer[index2]=temp;
        }
    }
    return ret;
}