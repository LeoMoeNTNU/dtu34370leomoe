
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

void startrandom(){
    srand(time(NULL));
}

int * randomlist(int x){
    int *p=malloc(sizeof(int)*x);
    int temp;
    int index1;
    int index2;
    for(int i=0;i<x;i++){
        p[i]=i;
    }
    for(int i=0;i<2*x;i++){
        index1=rand()%x;
        index2=rand()%x;
        temp=p[index1];
        p[index1]=p[index2];
        p[index2]=temp;
    }
    return p;
}

float timeleft(int maxtime, int currenttime){
    return ((float)(maxtime-currenttime))/(float)maxtime;
}

bool yesorno1(int maxtime, int currenttime){
    int likelihood=50+(currenttime*50)/maxtime;
    int randval=rand()%100;
//    printf("likelihood is that %d/%d");
    return likelihood>randval;
}

bool yesorno2(int maxtime, int currenttime){
    
    if(currenttime*2>maxtime){return false;}
    return (rand()%100)<20;
    
}

bool yesorno3(int maxtime, int currenttime){
    
    if(currenttime*2>maxtime){return false;}
    return (rand()%100)<40;
    
}

bool yesorno4(int maxtime, int currenttime){
    
    if(currenttime*3>maxtime){return false;}
    return (rand()%100)<10;
    
}


  
bool yesorno(int maxtime, int currenttime){
    
    if(currenttime*3>maxtime){return false;}
    return (rand()%100)<10;
    
}