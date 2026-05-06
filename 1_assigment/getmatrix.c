#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#include <float.h>

#include <math.h>
#include "list_types.h"

list_t getmatrix(const char * filename){

    
    FILE* file= fopen(filename, "r");
    if(!file){
        printf("couldn't open file\n");
        return (list_t){0,0};
    }

    int countedlines=0;
    
    while(countedlines<8){
        int letter1 =fgetc(file);
        if(letter1==EOF){
            printf("less than 4 lines!\n");
            return (list_t){0,0};
        }
        if(letter1=='\n'){
            countedlines++;
        }
    }

    int rowsandcols;
    int valid_items=fscanf(file, "%d", &rowsandcols);
    //printf("there are %d items!\n",rowsandcols);
    int * retP=malloc(sizeof(int)*rowsandcols*rowsandcols);
    enum status * statusP=malloc(sizeof(enum status)*rowsandcols*rowsandcols);
    
    for(int i=0;i<rowsandcols*rowsandcols;i++){
        statusP[i]=MAYBE;
    }
    //printf("got here without segfault the first time!\n");
    int i=0;

    while(i<rowsandcols*rowsandcols){
        int number;
        int something=fscanf(file,"%d",&number);

        /*
        if(number==EOF){
            printf("ending early!\n");
            
            continue;
            return (list_t){0,0};
        }
        */
        //printf("%c",endletter);
        //printf("putting %d on position %d\n",number,i);
        retP[i]=number;

        i++;
    }
    return (list_t){rowsandcols,retP,statusP};


    
    /*
    fpos_t pos; 
    int answer=fgetpos(file,&pos);
    //printf("did I use getfpos correctly? %d\n",answer);
    int len;
    while(true){
        

        float x, y;
        
        int valid_items=fscanf(file, "%d %f %f", &len, &x, &y);
        
        if(valid_items<3){
            //printf("length of list is %d\n",len-1);
            break;
        }
        
        //printf("%c",(int)letter);
    }
    //printf("\n");
    //printf("1, allocing for %d\n",len);
    entry_t* entries=malloc(sizeof(entry_t)*(len));
    int index=0;
    fsetpos(file,&pos);
    
    //printf("going again:\n \n");
     while(true){
        //int letter=fgetc(file);
        //if(letter==EOF){break;}

        int id;
        float x, y;
        
        int valid_items=fscanf(file, "%d %f %f", &id, &x, &y);
        if(valid_items<3){
            break;
        }
        entries[index]=(entry_t){x,y};
        index++;
        //printf("%f %f \n", x,y);
        //printf("%c",(int)letter);
    }
    //printf("\n");
    */

    //return (list_t){len,entries};
    return (list_t){0,0};
}