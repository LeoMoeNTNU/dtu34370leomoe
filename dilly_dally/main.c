#include "wholefunction.h"
#include <stdio.h>
#include <stdlib.h>
#include "randomlist.h"

double smallnum(int x){
    double ret=1;
    for(int i=0;i<x;i++){
        ret/=3;
    }

    return ret;
}

int main(int argc, char** args){
    
    if(argc!=4){
        printf("wrong amount of arguments!\n");
        return -1;
    }
    
    startrandom();


    int number_of_same_runs = 50;
    double mutation_rates[]= {smallnum(4),smallnum(5),smallnum(6),smallnum(7),
        smallnum(8),smallnum(9),smallnum(10),smallnum(11),smallnum(12)};
    /*
    for(int i=0;i<9;i++){
        printf("%lf\n",mutation_rates[i]);
    }
    */
    //double mutation_rates[] = {,0.001,0.0003,0.0001,0.00003,0.00001,0.000003,};
    printf("[");
    for(int i=0;i<sizeof(mutation_rates)/sizeof(double)*number_of_same_runs;i++){
        int index = i%number_of_same_runs;

        printf("(%f, ",mutation_rates[index]);
        wholefunc(args[1],args[2],atoi(args[3]),mutation_rates[index]);
        printf("),\n");
    }
    printf("]");

    return 0;
}