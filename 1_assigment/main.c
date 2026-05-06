#include <stdlib.h>
#include <stdio.h>
#include "getmatrix.h"
#include "randomarray.h"
#include "eval.h"
#include "accessory.h"

#include "greedysearch.h"



void leostest(){
    list_t matrix=getmatrix("/home/moeth/optimization_metaheuristics/1_assigment/Instances/leo1.sop");
    int a[]={0,1,2,3};

    int my_dist=distance(a, matrix);
    printf("result of leos test: %d\n",my_dist);
}
/*
void leosnexttest(){
    list_t matrix=getmatrix("/home/moeth/optimization_metaheuristics/1_assigment/Instances/leo1.sop");
    int *
    printf("result of leos test: %d\n",my_dist);
}
*/



void testgreedy(int time, list_t matrix){
    int * greedy1= greedysearch(1, matrix, 5, 20,20);
    printf("is greedy%d valid? %d\n",time,isvalidarray(greedy1, matrix.len));
    printf("distance:%d\n",distance(greedy1,matrix));
   //printpath(greedy1,matrix.len);
}

int main(int argc, char ** argv){
    initialize_random();
    //printf("hi\n");
    //printf("%s\n", argv[1]);
    list_t matrix=getmatrix(argv[1]);
    /*
    int width=matrix.len;
    for(int i=0;i<width;i++){
        for(int j=0;j<width;j++){
            
        //printf("index %d: %d ", i*width+j, matrix.p[i*width+j]);
        printf("%d ", matrix.p[i*width+j]);
        
    }
    printf("\n");
}
*/
    //int random[20];
    //randomarray(random,20);
    /*
    for(int i=0;i<20;i++){
        printf("%d:%d\n",i,random[i]);
    }
    */


    //printf("is the array valid? %d\n",isvalidarray(random, 20));

    
    leostest();
    //int * greedysearch(int time, list_t matrix, int neighbours, int local_iterations,int perturbationsize);
    //int localdistance(int x, int y,list_t matrix)
    printf("localdistance 64,0:%d and localdistance (0,64):%d\n",localdistance(64,0,matrix),localdistance(0,64,matrix));

    //testgreedy(1,matrix);
    //testgreedy(5,matrix);
    //testgreedy(15,matrix);


    return 0;
}