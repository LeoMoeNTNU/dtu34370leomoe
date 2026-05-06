/*
pseudocode: 
we start it by running the get.
then we need a greedy solution. 
just give it a random solution.  
uses the tl- tabu lists. 
first it inits the tl.  
best_solution = current solution. 
best_solution_value = current_solution_value;
while() keep track of time.  
    generate 5 indexes that arent the same. 
    find out for all of these whether or not they are both legal swaps and not in tabu_list.
    iterate over all of them and pick the best one that is legal for both criteria. 
    pick it. 
        part of this is to insert it in the tl. insert_into_tl.h
    
    if it is better than the best solution yet, change the best solution. 




*/
#include <time.h>//I imagine that this is where we'll get it. 
#include <stdlib.h>
#include "easy_solution.h"
#include "get.h"
#include "objective_function.h"
#include "writetofile.h"
#include <stdio.h>
#include "fillarraywithrandom.h"
#include <limits.h>
#include <stdbool.h>
#include "init_tl.h"
#include "isswaplegal.h"
#include "insert_into_tl.h"
#include <stdio.h>
#include "tl_contains.h"

#define searchspace (info.len/2)
int tabusearch(char * filename, char *writeto, int fulltime){
    int start_time=time(NULL);
    srand(time(NULL));
    //printf("got here1\n");

    info_t info= get(filename);
    int * curr_best=basic_valid(info);
        //printf("got here2\n");

    int curr_val=objective_function(info,curr_best);
        //printf("got here3\n");

    tl_t tl= init_tb_list(500, info.len);
      //  printf("got here4\n");
    
    int arr[searchspace];

    int curr[info.len];
    for(int i=0;i<info.len;i++)curr[i]=curr_best[i];
    int positivedecisions=0;
    int negativedecisions=0;
    
    //printf("got here 5\n");
    while(true){
        if(time(NULL)-start_time>=fulltime){break;}
        //printf("starting the random\n");

        fillarraywithrandom(arr,searchspace,info.len);
        /*
        printf("array:");
        for(int i=0;i<5;i++){
            printf(" %d",arr[i]);
        }
        printf("\n");
        */

        //printf("done with the random\n");
        bool validfound=false;
        int lowestvalue=INT_MAX;//I just use this as a random low value. I assume it will work fine like this. 
        int x=-1;
        int y=-1;
        int temp=-1;
        int value;
        for(int i=0;i<searchspace;i++){
            for(int j=i+1;j<searchspace;j++){
                //printf("got here 6\n");
                value=objective_function_alt(info, curr,arr[i],arr[j]);
                //printf("got here 7\n");
                bool legal=isswaplegal(info, arr[i], arr[j], curr);
                bool better=value<lowestvalue;
                if(legal&&better){
                    lowestvalue=value;
                    validfound=true;
                    x=arr[i];
                    y=arr[j];
                }
                
            }
        }
        //printf("stepping out of the loop!\n");


        if(validfound){
            //printf("is the swap legal? %d\n",isswaplegal(info,x,y,curr));
            //printf("swapping whats on index %d and %d in the array!\n",x,y);
            //printf("whole array: ");for(int i=0;i<info.len;i++){printf("%d ",curr[i]);}printf("\n");
            //much od this needs to get done one abstraction out!
            //do swap to modify curr.  
            temp =curr[x];
            curr[x]=curr[y];
            curr[y]=temp;

            if(tl_contains(tl, curr,false)){//in this case, we reject this option and as such dont do anything with it. 
                temp =curr[x];
            curr[x]=curr[y];
            curr[y]=temp;
                negativedecisions++;
            }else{
                
                positivedecisions++;
                //insert into the table.
                insert_into_tl(tl, curr,false);//ip stands for in-pointer.
                //update the best array. 
                value=objective_function(info, curr);
                if(value<curr_val){
                    curr_val=value;
                    for(int i=0;i<info.len;i++){ curr_best[i]=curr[i]; }
                }
            }
                
        }
        
    }
    
    printf("positive decisions: %d\n",positivedecisions);
    printf("negative decisions: %d\n",negativedecisions);
    printf("objective value: %d\n",curr_val);
    writetofile(curr_best, info.len,writeto);
    return 0;
}


int main(int argc, char** args){
    if(argc!=4){
        printf("wrong amount of arguments!\n");
        return -1;
    }
    printf("starting the function!\n");
    tabusearch(args[1],args[2],atoi(args[3]));
    //printinfo(info);




    return 0;
}

