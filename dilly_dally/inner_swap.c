#include "types.h"
#include <stdio.h>

//THIS ISNT DONE. LOOK AT COMMENTS IN THE .H FILE. 
void inner_swap(int_arr_t orig, int_arr_t indexes_to_swap, int_arr_t order, int orig_val,info_t info){
    //I dont really know how to do this properly. 
    /*
    The goal then is to actually swap from the order to the thing.

    Lets say:
        original_array is [5,7,1,2,33],
        indexes_to_swap is [1,4]
        order is [1,0] (only valid one with 2...)
        
        next array: [5,33,1,2,7]
        orig[1]=orig[]
        orig[indexes_to_swap[0]]=orig[]
        orig[1]=orig[4].
            comes from order[0]
        Holy this is annyoing to write even without the swaps.
        orig[order[0]]=orig[]
        orig[0]

        the [1,0] indicates that we swap 1 and 0.
        similarly, [3,2,0,1] would indicate that whatever should be at 0 in the new array is at 0 in the old one. 
        it is just that this is a bit of a misnomer still because that array doesn't actually hold much meaning. 
        Fucking un-fun. 
        orig[indexes_to_swap[0]]=orig[indexes_to_swap[order[0]]]
            orig[1]=orig[indexes_to_swap[1]]
            This is what I want to do, but then I want to copy stuff around to make it correct. 
            orig[indexes_to_swap[0]]=orig[values[0]]


    */
    int values[indexes_to_swap.len];
    
    /*
    for(int i=0;i<indexes_to_swap.len;i++){
        printf("%d ",values[i]);
        }printf("\n");
        */
       
       for(int i=0;i<indexes_to_swap.len;i++){
           values[i]=orig.p[indexes_to_swap.p[i]];
       }
    for(int i=0;i<indexes_to_swap.len;i++){
        //orig.p[i]=orig.p[values[order.p[0]]];
       orig.p[indexes_to_swap.p[order.p[i]]]=values[i];
    }
   

    for(int i=0;i<orig.len;i++){
        printf("%d ",orig.p[i]);
    }printf("\n");

    /*
    In the future, I will have to make it swap back. This I have not done yet. 
    */
    
    
}
