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




    
    return ret;
    


}