#include "wholefunction.h"
#include <stdio.h>
#include <stdlib.h>
#include "randomlist.h"

int main(int argc, char** args){
    
    if(argc!=4){
        printf("wrong amount of arguments!\n");
        return -1;
    }
    
    startrandom();

    wholefunc(args[1],args[2],atoi(args[3]));
    return 0;
}