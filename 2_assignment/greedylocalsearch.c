#include "bucket.h"
#include "types.h"
#include "infotools.h"
#include <stdio.h>
#include <time.h>



int iteminbucketval(bucket_t b,info_t info, int bucket,int item){

    int timeitemtakes=info.prodtimes[item];
    int init_val=info.rev_values[item];

    //remainingtime(bucket_t b, info_t info, int bucket)
    int remtime=remainingtime(b,info,bucket);
    if(timeitemtakes>remtime){return -1;}

//int local_insertion_val(bucket_t b, info_t info, int bucket, int item)
    int loc_val=local_insertion_val(b,info,bucket,item);
    
    
    int retval=(init_val+loc_val)/timeitemtakes;
    //printf("initial value: %d, loc_val: %d, time it takes: %d\n",init_val,loc_val,timeitemtakes);

    return retval;

}

int putoneinbucket(bucket_t* bp, info_t info, int bucket, int howmany,bool*taken, int indexinbucket){
    bucket_t b=*bp;
    //I think it'll have to maintain a sorted list, it's just easier. 
    int indexes[howmany];
    int vals[howmany];
    for(int i=0;i<howmany;i++){
        indexes[i]=-1;
        vals[i]=-1;
    }
    
    for(int i=0;i<info.tasks;i++){
        if(!taken[i]){
            // iteminbucketval(bucket_t b,info_t info, int bucket,int item)
            /*
            int indextoinsert=7;
            int valtoinsert=4;

            int tempind;
            int tempval;
            for(int i=0;i<4;i++){
                if(valtoinsert>vals[i]){
            tempind=indexes[i];
            tempval=vals[i];
            indexes[i]=indextoinsert;
            vals[i]=valtoinsert;
            indextoinsert=tempind;
            valtoinsert=tempval;

        }
    }
            */
            int ind=i;
            int val=iteminbucketval(b,info,bucket,i);
            int tempval;
            int tempind;
            //The thing I did in this for loop to make things trickle down was pretty slick!
            for(int j=0;j<howmany;j++){
                if(val>vals[j]){
                    //printf("inserting %d into the index %d on the list of contenders because its value is %d\n", ind,j,val);
                    tempind=indexes[j];
                    tempval=vals[j];
                    indexes[j]=ind;
                    vals[j]=val;
                    ind=tempind;
                    val=tempval;

                }
            }
        }
    }
    int startind=rand()%howmany;
    //printf("starting with startind=%d\n",startind);
    //printf("the array to pick between is %d, %d and %d\n",indexes[0],indexes[1],indexes[2]);
    for(int i=0;i<howmany;i++){
        int ind=(startind+i)%howmany;
        if(indexes[ind]!=-1){
            //printf("inserting %d into bucket %d\n",indexes[ind],bucket);
            b.p[b.length*bucket+indexinbucket]=indexes[ind];//This should really be moved to somewhere.
            taken[indexes[ind]]=true;
            //printf("actually inserting %d into bucket %d!\n",indexes[ind],bucket);
            return 0;
        }
    }
    return -1;

    //now we have to put in the specific one!
    //For this, timing matters!



}
//The retval is just to check if anything has fit at all!
//If nothing even fit the first time, then I dont have to run it more times and this is of course a lot better!
int fill_individual_bucket(bucket_t* bp, info_t info, int bucket,int things,bool* taken){
    //This one will do several things. 
    //First thing that it will do is that it will maintain a list of int things. 
    //For each decision, it is going to find out which 4 things are the best. 
    //Then it will find the best of them. 
    //which means, while we can fit it on time, we pick it.
      
    int retval=-1;
    for(int i=0;i<info.buckets;i++){
        int status= putoneinbucket(bp,info,bucket,things,taken,i);
        if(status!=-1)retval=0;
        if(status==-1)return retval;
    }
    return retval;
}


void insertintotopx();//This is the one I will use to input it if necessary. For now I will do it in the easiest way. 

bucket_t* greedylocalsearch(info_t info, int things){
    bool taken[info.tasks];
    for(int i=0;i<info.tasks;i++){taken[i]=false;}
    bucket_t* bp= init_buckets(info);
    bucket_t b=*bp;
    for(int i=0;i<info.buckets;i++){
        int status= fill_individual_bucket(bp,info,i,things,taken);
        if(status==-1){return bp;}
    }
    return bp;
    /*
    for(int i=0;i<info.tasks;i++){
        taken[i]=false;
    }
    bucket_t* bp= init_buckets(info);
    bucket_t b=*bp;
    for(int i=0;i<info.tasks;i++){
        printf("task: %d, value: %d\n",i, iteminbucketval(b,info,0,i));
    }
    */
    return bp;
    
    //several things here need to be implemented. 

    /*

    I also actually need a bunch of buckets. 

    1. Find out which is the best one to greedily insert based on info and bucket. 

    while(true){
        find the best one to insert. 
        if failed: break. 
    
    }
    
    find the best one to insert. 
    have a bool array to know which one that we are allowed to put. 

    findonestoinsert:
    maintain both value and index.  
    insert the first ones that fit on time. 
    for the rest of them, check if they they get a better value and if so: 
        put it in. Through out the least valuable one. Potentially keep it sorted but who cares... 


    find valueof inserting in specific bucket: 
        find remaining time
        for(int i=0;i<tasks;i++){

        }
    
    */
}
