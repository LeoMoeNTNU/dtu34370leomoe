#include <time.h>
#include <stdlib.h>

int weighted_binarysearch(int lowerIn, int upperIn){
    int lower=lowerIn;
    int upper=upperIn;
    int middle;
    while(lower!=upper){
        if(upper-lower==1){
            return lower;

        }
        middle=(lower+upper)/2;
        if(rand()%4<3){
            upper=middle;
        }else{
            lower=middle;
        }
    }
}


int lowint(int upperbound){
    startagain:
    int counter=0;
    while(counter<upperbound){
        if(rand()%4==0){
            return counter;
        }
        counter++;
    }
    goto startagain;
}

int highint(int upperbound){
    return upperbound-1-lowint(upperbound);
}