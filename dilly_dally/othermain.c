#include "wholefunction.h"
#include <stdio.h>
#include <stdlib.h>
#include "randomlist.h"

#define NUM_RUNS 5

#define NUM_TESTS 20
int main(int argc, char** args){
    
    if(argc!=4){
        printf("wrong amount of arguments!\n");
        return -1;
    }
    
    
    wholefunc2_2(args[1],args[2],atoi(args[3]));
    
    //printinfo(info);

    return 0;
}