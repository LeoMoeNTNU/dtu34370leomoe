#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#include <float.h>

#include <math.h>
#include "list_types.h"
#include "getlist.h"
#include "validindexarray.h"




float distance(int* array, int len, list_t list){
    float accumulated_distance=0;
    int index=0;
    while(index<len-1){
        entry_t elem=list.p[array[index]];
        entry_t elem_next=list.p[array[(index+1)%len]];
        accumulated_distance+=sqrtf((elem.x-elem_next.x)*(elem.x-elem_next.x)+(elem.y-elem_next.y)*(elem.y-elem_next.y));
        index++;
    }
    //accumulated_distance+=sqrtf((list.p[0].x-list.p[len-1].x)*((list.p[0].x-list.p[len-1].x))+(list.p[0].y-list.p[len-1].y)*((list.p[0].y-list.p[len-1].y)));
    return accumulated_distance;
}

float dist(float x, float y, float x_2, float y_2){
    return (x-x_2)*(x-x_2)+(y-y_2)*(y-y_2);
}

int pick_index(float x, float y, list_t list,bool* used){
    float curr_dist=FLT_MAX;
    int index=-1;
    for(int i=0;i<list.len;i++){
        float new_dist=dist(x,y,list.p[i].x,list.p[i].y);
                if(!used[i] && new_dist<curr_dist){

        //if(!list.p[i].used && new_dist<curr_dist){
            index=i;
            curr_dist=new_dist;
        }
    }
    if(index==-1){printf("index here is never supposed to be -1!\n");}
    return index;

}

int * NN(list_t lp){
      int* index_array=malloc(sizeof(int)*lp.len);
    
    bool used[lp.len];
    for(int i=0;i<lp.len;i++){
        used[i]=false;
    }

    int index_to_use=0;
    int indexes_picked=0;
    while(indexes_picked<lp.len){
    
        index_to_use=pick_index(lp.p[index_to_use].x,lp.p[index_to_use].y,lp, used);
        //printf("picked index %d\n",index_to_use);
        index_array[indexes_picked]=index_to_use;
        indexes_picked++;
        used[index_to_use]=true;
        //lp.p[index_to_use].used=true;
    }
    return index_array;
}

#include <time.h>

void swap(int* array, int len){

    int ind_1=rand()%len;
    int ind_2=rand()%len;
    int val_1=array[ind_1];
    int val_2=array[ind_2];
    array[ind_1]=val_2;
    array[ind_2]=val_1;

}

int* shuffledlistoflength(int len){
  
    //printf("2\n");
    int* array= malloc(len*sizeof(int));
    for(int i=0;i <len;i++){
        array[i]=i;
    }
    for(int i=0;i<2*len;i++){
        swap(array,len);
    }
    return array;


    
}




//I know that what and where is a silly name but idk what to call it yet. 
typedef struct {
    int what;
    int where;

}what_and_where_t;

typedef struct {
    int where;
    int value;
} where_and_value_t;


where_and_value_t Best_position_of_x_y(
    int* array, 
    int placed,
    float x,
    float y,
    list_t lp
){
    int index=-1;
    float distance=FLT_MAX;
    float dist_back;
    float dist_forw;
    for(int i=1;i<=placed;i++){
        entry_t back=lp.p[array[i]];
        entry_t forw=lp.p[array[(i+1)%placed]];
        dist_back=dist(x,y,back.x,back.y);
        dist_forw=dist(x,y,forw.x,forw.y);
        
        if(dist_back+dist_forw<distance){
            distance=dist_back+dist_forw;
            index=i;
        }
    }
    if(index==-1){printf("index should never be -1 when we return\n");}
    return (where_and_value_t){index,distance};

}

what_and_where_t NI_now(
    int * array, 
    int placed, 
    bool* used, 
    list_t lp
){
    what_and_where_t ret={-1,-1};
    float distance=FLT_MAX;
    for(int i=0;i<lp.len;i++){
        if(!used[i]){
            where_and_value_t a=Best_position_of_x_y(array,placed,lp.p[i].x,lp.p[i].y,lp);
            if(a.value<distance){
                distance=a.value;
                ret=(what_and_where_t){i,a.where};//Is this even right;
            }
        }
    }
    if(ret.what==-1){printf("the what shouldn't be -1!\n");}
    if(ret.where==-1){printf("the where shouldn't be -1!\n");}
    //if(ret.where!=0){printf("didn't put in zero for once!\n");}

    return ret;
}

what_and_where_t FI_now(
    int * array, 
    int placed, 
    bool* used, 
    list_t lp
){
    what_and_where_t ret={-1,-1};
    float distance=0;
    for(int i=0;i<lp.len;i++){
        if(!used[i]){
            where_and_value_t a=Best_position_of_x_y(array,placed,lp.p[i].x,lp.p[i].y,lp);
            
            if(a.value>distance){
                distance=a.value;
                ret=(what_and_where_t){i,a.where};//Is this even right;
            }
        }
    }
    if(ret.what==-1){printf("the what shouldn't be -1!\n");}
    if(ret.where==-1){printf("the where shouldn't be -1!\n");}
    //if(ret.where!=0){printf("didn't put in zero for once!\n");}
    return ret;
}

int * NI(list_t lp){
    int * array=malloc(sizeof(int)*lp.len);
    bool used[lp.len];
    for(int i=0;i<lp.len;i++){
        used[i]=false;
    }
    array[0]=0;
    int placed=1;
    used[0]=true;
    while(placed<lp.len){
        what_and_where_t toplace=NI_now(array,placed,used,lp);
        //printf("placing %d from original array in %d in new one\n",toplace.what,toplace.where);
        for(int i=placed;i>toplace.where;i--){
            array[i]=array[i-1];
        }
        array[toplace.where]=toplace.what;
        used[toplace.what]=true;
        placed++;
    }
    return array;
}

//furthest insertion!
int * FI(list_t lp){
    int * array=malloc(sizeof(int)*lp.len);
    bool used[lp.len];
    for(int i=0;i<lp.len;i++){
        used[i]=false;
    }
    array[0]=0;
    int placed=1;
    used[0]=true;
    while(placed<lp.len){
        what_and_where_t toplace=FI_now(array,placed,used,lp);
        //printf("placing %d from original array in %d in new one\n",toplace.what,toplace.where);
        for(int i=placed;i>toplace.where;i--){
            array[i]=array[i-1];
        }
        array[toplace.where]=toplace.what;
        used[toplace.what]=true;
        placed++;
    }
    return array;
}

//This one should only be used in some contexts and not in all contexts. 
//I havent implemented it yet because idk what to do if index1-index2=1 or -1
//the general idea is to just swap check A-1 to B to A+1 and B-1 to A to B+1
bool shouldswap(int* array ,list_t lp, int index1, int index2){
    return false;

}

//will n times try to swap and see if it is better. 
int * greedyswap(int * array, list_t lp){
    
    //I copy the array because I don't want it to be altering the original array. 
    int * newarray= malloc(sizeof(int)*lp.len);

    for(int i=0;i<lp.len;i++){
        newarray[i]=array[i];
    }
    int ind1;
    int ind2;
    int val1;
    int val2;

    float curr_dist=distance(newarray,lp.len,lp);
    for(int i=0;i<lp.len;i++){
        ind1=rand()%lp.len;
        ind2=rand()%lp.len;
        val1=newarray[ind1];
        val2=newarray[ind2];
        newarray[ind1]=val2;
        newarray[ind2]=val1;
        float newdist=distance(newarray,lp.len,lp);
        if(newdist<curr_dist){
            curr_dist=newdist;
        }else{
            //this is to revert the change. 
            newarray[ind1]=val1;
            newarray[ind2]=val2;
        }

        }
    return newarray;
}

//will n times try to swap and see if it is better. 
int * greedyswapfortime(int * array, list_t lp, int seconds){
    
    //I copy the array because I don't want it to be altering the original array. 
    int * newarray= malloc(sizeof(int)*lp.len);

    for(int i=0;i<lp.len;i++){
        newarray[i]=array[i];
    }
    int ind1;
    int ind2;
    int val1;
    int val2;



    float curr_dist=distance(newarray,lp.len,lp);
    int start_time=time(NULL);
    while(time(NULL)-start_time<seconds){

        for(int i=0;i<100;i++){
            ind1=rand()%lp.len;
            ind2=rand()%lp.len;
            val1=newarray[ind1];
            val2=newarray[ind2];
            newarray[ind1]=val2;
            newarray[ind2]=val1;
            float newdist=distance(newarray,lp.len,lp);
            if(newdist<curr_dist){
                curr_dist=newdist;
            }else{
                //this is to revert the change. 
                newarray[ind1]=val1;
                newarray[ind2]=val2;
            }
            
        }
    }
    return newarray;
}

//NOT DONE YET, IN PROGRESS! 
int * greedyswapfortime2(int * array, list_t lp, int seconds){
    
    //I copy the array because I don't want it to be altering the original array. 
    int * newarray= malloc(sizeof(int)*lp.len);

    for(int i=0;i<lp.len;i++){
        newarray[i]=array[i];
    }
    int ind1;
    int ind2;
    int val1;
    int val2;

    int bestind1;
    int bestind2;
    int bestval1;
    int bestval2;

    float minobj;



    float curr_dist=distance(newarray,lp.len,lp);
    int start_time=time(NULL);
    while(time(NULL)-start_time<seconds){

        bestind1=0;
        bestind2=0;
        bestval1=0;
        bestval2=0;

        minobj=FLT_MAX;
        for(int i=0;i<20;i++){
            for(int j=0;j<5;j++){

                
                ind1=rand()%lp.len;
                ind2=rand()%lp.len;
                val1=newarray[ind1];
                val2=newarray[ind2];
                newarray[ind1]=val2;
                newarray[ind2]=val1;
                float newdist=distance(newarray,lp.len,lp);
                if(newdist<minobj){
                    minobj=newdist;
                    bestind1=ind1;
                    bestind2=ind2;
                }
                //this is to revert the change. 
                newarray[ind1]=val1;
                newarray[ind2]=val2;
            }
        }

        bestval1=newarray[bestind1];
        bestval2=newarray[bestind2];
        
        newarray[bestind1]=bestval2;
        newarray[bestind2]=bestval1;
            
        }
        return newarray;
    }



/*
//This one can be way more time effective, reducing from N^2 to N if we make another array as well and just mark every number we get!
bool isvalidsolution(int* array, int len){
    bool found;
    for(int i=0;i<len;i++){
        found=false;
        for(int j=0;j<len;j++){
            if(array[j]==i){
                found=true;
                j+=len;
            }
        }
        if(found==false){
            return false;
        }


    }
    return true;
}

bool isvalidsolution2(int* array, int len){
    bool indexfound[len];
    for(int i=0;i<len;i++){
        indexfound[array[i]]=true;
    }
    for(int i=0;i<len;i++){
        if(indexfound[i]==false)return false;
    }
    return true;
}
*/

void printstring(char * cp){
    char *ecp=cp;
    while(*ecp!=0){
        printf("%c",*ecp);
        ecp++;
    }
}

void eval(int * (f)(list_t),list_t lp, float compare_value, char * name){
       int* index_array=f(lp);

    if(isvalidsolution2(index_array,lp.len)){
        printstring(name);
        printf(" is a valid solution\n");
    }else{
        printstring(name);
        printf(" didn't didn't provide a valid solution\n");
    }
    float dist=distance(index_array,lp.len,lp);
    printf("total distance: %f\n",dist);


    printstring(name);
    printf("-relationship: %f\n",compare_value/dist);
    
}

void eval_new_array(int* array, list_t lp,float compare_value, char * name){
    if(!isvalidsolution2(array,lp.len)){
        printstring(name);
        printf("wasn't valid!\n");
        return ;
    }

    printf("%s had an improvement of %f\n",name,compare_value/ distance(array,lp.len,lp));
}


int main(){
    //printstring("hi there!\n");

    srand(time(NULL));



    list_t lp=getlist("tsp_fun.tsp");

    //printf("full list from main of length %d\n",lp.len);
    /*
    for(int i=0;i<lp.len;i++){
        printf("x: %f, y: %f\n", lp.p[i].x, lp.p[i].y);
    }
    */

    if(lp.len==0){
        printf("weird, empty list!\n");
        return 0;
    }

    
    int * array=shuffledlistoflength(lp.len);
     if(isvalidsolution2(array,lp.len)){
        printf("random provides a valid solution\n");
    }else{
        printf("random didn't provide a valid solution\n");
    }
    float random_dist= distance(array,lp.len,lp);
    printf("distance of randomly shuffled list: %f\n", random_dist);
    
    int * improved_array=greedyswap(array,lp);
    
    float improved_dist=distance(improved_array,lp.len,lp);
    if(isvalidsolution2(improved_array,lp.len)){
        printf("improved was valid\n");
        
    }else{printf("improved wasn't valid!\n");}
    printf("distance is %f which gives a ratio of %f\n",improved_dist, random_dist/improved_dist);
    

    //eval(greedyswap,lp,random_dist,"improved");
    //eval(NN,lp,random_dist,"NN");
    //eval(NI,lp,random_dist,"NI");
    //eval(FI,lp,random_dist,"FI");
    
    printf("TRYING THE GREEDY SEARCH ALGORITHM\n");
    for(int i=1;i<8;i++){
        int * greedyfortime=greedyswapfortime(array,lp,i);
        printf("%d:\n",i);
        eval_new_array(greedyfortime, lp,random_dist, "greedy swapper");

    }
    /*
    printf("TRYING THE SECOND GREEDY SEARCH ALGORITHM\n");
    for(int i=1;i<5;i++){
        int * greedyfortime=greedyswapfortime2(array,lp,i);
        printf("%d:\n",i);
        eval_new_array(greedyfortime, lp,random_dist, "greedy swapper");
        
    }
    */
    //int * greedyswapfortime(int * array, list_t lp, int seconds)

    

    return 0;
}