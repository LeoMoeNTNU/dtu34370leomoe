#include "types.h"
#include "randomlist.h"
#include "get.h"
#include "objective_function.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "printallprocs.h"
#include "writetofile.h"
#include <stddef.h>
#include <stdint.h>
#include "expanding_local_search.h"

/*psuedo: 
fix time. 
generate random. 
get value of outer. 
int local_search_width=2;

maximal int array with a length. 
while time:
    
    produce each tuple of length local_search_width. 

    produce each order of length local_search_width.
    
    do the swaps of these.
    how this function would work:
        as an input, it gets:
            original array. 
            indexes to swap between (from each_tuple)
            specific order to swap in between (from expanding_localsearch)
            do the swapping for each of these and check the value. 
            I guess it just has to be called recursively. 
            the easy way of doing this is to just put the code in here. 
            inner_swap needs a set of things. 

    inner swap needs: 
        original array. 
        array of indexes. 
        The order to swap it in. 
        original value. 
        info. 
        based on this, it will find the new one. 

        how I will do this. 
        I will just send it the solution and then it will be fine. 

    
    check it out. 
    if better, keep it.  

    expanding local search(local_search_width)


*/

/*
each order of length x in array of length y.
for x=2, y: 
for(int i=0;i<y;i++){
    for(int j=i+1;j<y;j++){
    
    }
} 




*/

void check_maybe_update


int exp_outer(info_t info,int in_time){

}
