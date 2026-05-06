#include "types.h"
#include <stdlib.h>
#include <stdbool.h>
#include "infotools.h"
#include <stdio.h>

bucket_t* init_buckets(info_t togivesize){
    bucket_t* ret=malloc(sizeof(bucket_t));
    int size=togivesize.tasks;
    int count=togivesize.buckets;
    ret->p=malloc(sizeof(int)*size*count);
    ret->length=size;
    //for default values.
    for(int i=0; i<size*count;i++){
        ret->p[i]=-1;
    }
    return ret;
}

int* bucketp(bucket_t b, int val){
    return b.p+ val* b.length;
}

int len(bucket_t *bp, int val){
    bucket_t b=*bp;
    int * ip=bucketp(b,val);
    for(int i=0;i<b.length;i++){
        if(ip[i]==-1){return i;}
    }
    return -1;
}

int valueupuntilhere(bucket_t* bp, info_t info, int bucket, int index){

}
int timeupuntilhere(bucket_t* bp, info_t info, int bucket, int index){
    bucket_t b=*bp;
    int rem_time=info.planning_horizon;
    int* first=bucketp(b,bucket);
    for(int i=0;i<index-1;i++){
        int val=first[i];
        if(val==-1){
            printf("this isn't supposed to happen, we already know the length\n");
            break;}
        int timeofval=info.prodtimes[i];
        rem_time-=timeofval;
    }
    if(rem_time<0){
        //printf("some bucket was full!\n");
    }
    //printf("remaining time: %d\n",rem_time);
    return rem_time;

}



int bucketposition(bucket_t b, int bucket, int index){
    return b.p[b.length*bucket+index];
}

int remainingtime(bucket_t b, info_t info, int bucket){
    int rem_time=info.planning_horizon;
    int* first=bucketp(b,bucket);
    for(int i=0;i<info.tasks;i++){
        int val=first[i];
        if(val==-1){break;}
        int timeofval=info.prodtimes[i];
        rem_time-=timeofval;
    }
    if(rem_time<0){
        //printf("some bucket was full!\n");
    }
    //printf("remaining time: %d\n",rem_time);
    return rem_time;
    
}
//I may have implemented this twice hehe...
int local_insertion_val(bucket_t b, info_t info, int bucket, int item){
    int * first=bucketp(b,bucket);
    int ret_val=0;
    int val;
    for(int i=0;i<info.tasks;i++){
        val=first[i];
        //printf("thing already in bucket: %d\n",val);
        if(val!=-1){ret_val+=rev_mat_get(item,val,info);}        
    }
    return ret_val;
}
//this is code for validating that no numbers have been repeated in the buckets.
bool no_overlap_in_buckets(bucket_t b, int bucketcount){
    bool arr[b.length];
    for(int i=0;i<b.length;i++){arr[i]=false;}
    for(int i=0;i<b.length*bucketcount;i++){
        int val= b.p[i];
        if(val==-1){continue;}
        if(arr[val]){
            printf("%d was found twice!\n",val);
            return false;}
        arr[val]=true;

    }
    return true; 
}
//heavily inspired by the function no_overlap_in_buckets
bool everything_placed_in_buckets(bucket_t b, int bucketcount){
    bool arr[b.length];
    for(int i=0;i<b.length;i++){arr[i]=false;}
    for(int i=0;i<b.length*bucketcount;i++){
        int val= b.p[i];
        if(val==-1){continue;}
        if(arr[val]){return false;}
        arr[val]=true;

    }
    for(int i=0;i<b.length;i++){
        if(!arr[i]){
            //printf("lacking index %d\n",i);
            return false;
    }

    }
    return true;

}

