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
    
    startrandom();

    int total = 0;
    total = 0;
    printf("Running \"whole_func\" with %s, %s, %d\n", args[1], args[2], atoi(args[3]));
    for(int j = 0; j < NUM_TESTS; j++)        {
        total += wholefunc(args[1],args[2],atoi(args[3]));
    }
    printf("\tAverage best %f\n", (float)total/NUM_TESTS);


    for(int i = 2; i <= 10; i ++)
    {
        printf("Running \"whole_func2\" with %s, %s, %d, %d\n", args[1], args[2], atoi(args[3]), i);
        total = 0;
        for(int j = 0; j < NUM_TESTS; j++)        {
            total += wholefunc2(args[1],args[2],atoi(args[3]), i);
        }
        printf("\tAverage best %f\n", (float)total/NUM_TESTS);
        printf("Running \"whole_func2_2\" with %s, %s, %d, %d\n", args[1], args[2], atoi(args[3]), i);
        total = 0;
        for(int j = 0; j < NUM_TESTS; j++)        {
            total += wholefunc2_2(args[1],args[2],atoi(args[3]), i);
        }
        printf("\tAverage best %f\n", (float)total/NUM_TESTS);
        printf("Running \"whole_func3\" with %s, %s, %d, %d\n", args[1], args[2], atoi(args[3]), i);
        total = 0;
        for(int j = 0; j < NUM_TESTS; j++)        {
            total += wholefunc3(args[1],args[2],atoi(args[3]), i);
        }
        printf("\tAverage best %f\n", (float)total/NUM_TESTS);
        printf("Running \"whole_func4\" with %s, %s, %d, %d\n", args[1], args[2], atoi(args[3]), i);
        total = 0;
        for(int j = 0; j < NUM_TESTS; j++)        {
            total += wholefunc4(args[1],args[2],atoi(args[3]), i);
        }
        printf("\tAverage best %f\n", (float)total/NUM_TESTS);
    }

    //printinfo(info);

    return 0;
}