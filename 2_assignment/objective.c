#include "types.h"
#include <stdio.h>
#include "bucket.h"
int bucket_val(bucket_t* bp, info_t info, int bucket){
    if(bucket>=info.buckets){printf("this bucket doesnt exist!"); return 0;}
    bucket_t b=*bp;
    int valuesbythemselves=0;
    int* loc_point=bucketp(b,bucket);
    for(int i=0;i<info.tasks;i++){
        int val=loc_point[i];
        if(val==-1)break;
        valuesbythemselves+= info.rev_values[val];
    }
    int combinationvals=0;
    int val1=0;
    int val2=0;
    for(int i=0;i<info.tasks;i++){
        for(int j=i+1;j<info.tasks;j++){
            val1=loc_point[i];
            val2=loc_point[j];
            if(val1==-1||val2==-1){break;}
            combinationvals+=rev_mat_get(val1,val2,info);
        }
        if(val1==-1){break;}
    }
    int ret_val=valuesbythemselves+combinationvals;
    printf("returning %d from bucket %d\n",ret_val,bucket);
    return ret_val;
}   

int totalbucket_val(bucket_t* bp, info_t info){
    int totalvalue=0;
    for(int i=0;i<info.buckets;i++){
        totalvalue+=bucket_val(bp,info,i);
    }
    return totalvalue;
}