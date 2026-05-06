#include "wholefunction.h"
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char** args){
    if(argc!=4){
        printf("wrong amount of arguments!\n");
        return -1;
    }
    wholefunc(args[1],args[2],atoi(args[3]));
    //printinfo(info);




    return 0;
}