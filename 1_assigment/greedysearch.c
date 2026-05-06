#include "list_types.h"
#include "randomarray.h"
#include <stdbool.h>
#include "eval.h"
#include <stdlib.h>
#include <stdio.h>
//this function has not at all dealt with the higher index potentially being too high and meant to be zero.
//should be done in the greedyfunction instead.
//What this one does: It is supposed to get the current tour and it will give a value to indicate if this is a good swap. 
int swapval(int xin, int yin, list_t matrix, int* ip){
    if(xin==yin){return 0;}//idk if it is good to have this line...

    int x_back;
    if(__builtin_expect(xin!=0,1)){
        x_back=ip[xin-1];
    }else{
        x_back=ip[matrix.len-1];
    }
    //int x_back= (xin!=0)?ip[xin-1]:ip[matrix.len-1];
    int x_forth= (xin!=matrix.len-1)?ip[xin+1]:ip[0];
    int x=ip[xin];

    int y_back=(yin!=0)?ip[yin-1]:ip[matrix.len -1];
    int y_forth=(yin!=matrix.len-1)?ip[yin+1]:ip[0];
    int y=ip[yin];

    
    if(x+1==y){
        return distance4nodes(x_back,y,x,y_forth,matrix)-distance4nodes(x_back,x,y,y_forth,matrix);
       
    }
    if(y+1==x){
        
        return distance4nodes(y_back,x,y,x_forth,matrix)-distance4nodes(y_back,y,x,x_forth,matrix);
     
    }
    //in this instance they arent just by each other and I can do it more easily. 
    return 
    distance3nodes(x_back,y,x_forth,matrix)+distance3nodes(y_back,x,y_forth,matrix)
    -
    distance3nodes(x_back,x,x_forth,matrix)+distance3nodes(y_back,y,y_forth,matrix);

}

typedef struct {
    int x;
    int y;
    bool doswap; 
}swap_t;


swap_t one_iteration(int size, list_t matrix, int* currentExtra){
    int ip[size];
    
    //
    //This fills the integer array with random values. 
    //int swapval(int xin, int yin, list_t matrix, int* ip)
    randomindexes(ip,size,matrix.len);
    swap_t swap={0,0,false};
    int swapmin=0;
    for(int i=0;i<size;i++){
        for(int j=i+1;j<size;j++){
            int potswapmin=swapval(ip[i],ip[j],matrix,currentExtra);
            if(potswapmin<swapmin){
                swap=(swap_t){i,j,true};
                swapmin=potswapmin;
            }

        }
    }
    return swap;
}


void doperturbation(int* p,int len, int howmanyswaps){
    for(int i=0;i<howmanyswaps;i++){
        swap(p,len);
    }

    //I think this one is easy to implement. 
    //I just need a swap 
}



int * greedysearch(int time, list_t matrix, int neighboursIn, int local_iterations,int perturbationsizeIn){
    int neighbours=(neighboursIn>=matrix.len)?matrix.len:neighboursIn;
    int perturbationsize=(perturbationsizeIn>=matrix.len)?matrix.len:neighboursIn;


    int blockone[matrix.len];
    int blocktwo[matrix.len];
    int *ind_arr=blockone;
    randomarray(ind_arr,matrix.len);
    int curr_dist=distance(ind_arr,matrix);
    int *extra_array=blocktwo;
    int extra_dist;
    while(timewent()<time){
        //printf("entered the loop!\n");

        for(int i=0;i<matrix.len;i++){
            extra_array[i]=ind_arr[i];
        }
        doperturbation(extra_array,matrix.len,perturbationsize);
       

        for(int i=0;i<local_iterations;i++){
            swap_t swap=one_iteration(neighbours,matrix,extra_array);
            if(swap.doswap){
                int ind1=extra_array[swap.x];
                int ind2=extra_array[swap.y];
                extra_array[swap.x]=ind2;
                extra_array[swap.y]=ind1;
            }
        }

        extra_dist=distance(extra_array,matrix);
        if(extra_dist<curr_dist){
            curr_dist=extra_dist;
            int* temp= ind_arr;
            ind_arr=extra_array;
            extra_array=temp;




        }


    }

    int * retP=malloc(sizeof(int)*matrix.len);
    for(int i=0;i<matrix.len;i++){
        retP[i]=ind_arr[i];
    }
    return retP;//This is completely wrong but ok!
    //I have been using stack variables the whole time and now I have to stop doing that!
}
