#include "objective_function.h"

int hamming_distance(int* a, int*b, int len){
    int distance=0;
    for(int i=0;i<len;i++){
        distance+=(a[i]==b[i]);
    }
    return distance;
}

/* This one will have several things: 
    1. an intermediate array for the current one. 
    2. an intermediate array for the best one.
    3. generation of random swap. This could be very slow at some point. 
        To not do it like this, I will have an array of the indexes that are different. 
        Then I'll only have to use these.  
    4. I dont think I actually need a hamming distance function. 
        The reason I don't need a hamming distance function is because I just keep it as a list. 
        The function is expensive so it is easier to just do it like that.      

*/
int * path_relink_best_option_from_a(int *a, int* elite, int len){
    int current[len];
    int current_best[len];
    int hamming_distance;
    //TODO: set current and hamming_distance. current_best doesnt have to be set yet. 


    for(int i=0;i<len;i++){
        //reduce hamming distance
    
        //if it better than best, then we need to copy the array!
        
    }
    //malloc and return this one. 
    //I'm not sure if I actually use malloc any more in the code. This I can find out!

    
}

int * path_relink_best_option_from_elite(int* a, int * elite, int len);

int * path_relink_best_both_sides(int *a, int *elite, int len);