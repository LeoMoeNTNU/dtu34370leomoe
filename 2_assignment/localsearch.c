#include "types.h"

#include "greedylocalsearch.h"
#include "time.h"
#include "stdlib.h"
#include "objective.h"
#include "bucket.h"

//I grabbed this one from a different place but it needs to changed a little bit to function as I want. 
/*
TODO: 
    1. ignore one specific index.
        just put it in the if val==-1, a new condition. 
    2. add the actual value of the thing. 

*/
int local_insertion_val2(bucket_t b, info_t info, int bucket, int item, int itemtoignore){
    printf("sketchy1\n");
    int * first=bucketp(b,bucket);
    int ret_val=0;
    int val;
    printf("sketchy 2\n");
    for(int i=0;i<info.tasks;i++){
        val=first[i];
        //printf("thing already in bucket: %d\n",val);
        if(val!=-1&&val!=item)
        {
            printf("allocated memory: %d\n",info.tasks*info.buckets);
            printf("sketchy 3, with item %d and item to ignore: %d\n",item, itemtoignore);
            printf("and val is %d\n",val);
            printf("got val from index %i\n",i);
            ret_val+=rev_mat_get(item,val,info);
            ret_val-=rev_mat_get(itemtoignore,val,info);
            printf("sketchy 4\n");
        }

    }
    return ret_val;
}


//This one is not done yet. 
int bucketofitem(bucket_t b, info_t info,int item){
    for(int i=0;i<info.buckets;i++){
        for(int j=0;j<b.length;j++){
            int invest= b.p[i*info.tasks+j];
            if(invest==-1){break;}
            if(invest==item){return i;}
        }
    }
    return -1;
}

int indexinbucket(bucket_t b, info_t info, int bucket,int item){
    int* ip=bucketp(b,bucket);
    for(int i=0;i<info.tasks;i++){
        int val=ip[i];
        if(val==item){return i;}
        if(val==-1){
            printf("didnt find!");
            return 0;
        }
    }
}

int timeifgone(bucket_t b, info_t info, int bucket,int item){
    
    int rem_time=info.planning_horizon;
    int* ip=bucketp(b,bucket);
    for(int i=0;i<info.tasks;i++){
        int val=ip[i];
        if(val==-1){break;}
        if(val!=item){rem_time-=info.prodtimes[val];}
    }
    return rem_time;
}



//This one will modify the bucket. 
void loc_search(bucket_t* bp, info_t info, int iterations, int loc_search_space){
    /*
    for iterations:
    pick 5 random indexes. Find out where they are. 
        They could either be inside or they could be outside. if outside, I only have to check one time. 
    */
   bucket_t b=*bp;
   for(int i=0;i<1;i++){

       int indexes[loc_search_space];//TODO: All these need to be initialized with values!
       int wheretheyare[loc_search_space];//sometimes this value will be -1. Will use bucketofitem. 

       int howmuchtimeifgone[loc_search_space];
       for(int i=0;i<loc_search_space;i++){
            int item=rand()%info.tasks;
            indexes[i]=item;
            wheretheyare[i]=bucketofitem(b,info,item);
            if(wheretheyare[i]!=-1){
                howmuchtimeifgone[i]=timeifgone(b,info,wheretheyare[i],item);
            }
            
           
        }

        int bestswap1;
        int bestswap2;
        int bestswapvalue=0;
        int totalgain=0;
        
        for(int j=0;j<loc_search_space;j++){
            for(int k=j+1;k<loc_search_space;k++){
                printf("in this loop 1\n");
                if(wheretheyare[j]==wheretheyare[k]){continue;}
                
               int actual_val1=indexes[j];
               int actual_val2=indexes[k];
               printf("in this loop2\n");

               if(wheretheyare[j]!=-1){
                   if(info.prodtimes[actual_val2]>howmuchtimeifgone[j]){continue;}//In this instance, we will skip through. 
               }
               printf("in this loop 3\n");
               if(wheretheyare[k]!=-1){
                    if(info.prodtimes[actual_val1]>howmuchtimeifgone[k]){continue;}//This is the same instance.
               }
               printf("in this loop 4\n");
                int valuetogain1=local_insertion_val2(b,info,wheretheyare[j],actual_val2,actual_val1);
                int valuetogain2=local_insertion_val2(b,info,wheretheyare[k],actual_val1,actual_val2);
                printf("this loop 4.5\n");
                if(wheretheyare[j]==-1){valuetogain1+=info.rev_values[actual_val1];}
                if(wheretheyare[k]==-1){valuetogain2+=info.rev_values[actual_val2];}
                totalgain=valuetogain1+valuetogain2;
                printf("in this loop 5\n");
                if(totalgain>bestswapvalue){
                    printf("%d,%d going to be %d,%d\n",bestswap1,bestswap2,j,k);

                    bestswap1=j;
                    bestswap2=k;
                }
            }
        }
        
        if(totalgain>0){//check to see if we are doing the swap at all. 
            printf("doing a swap in here!\n");
            printf("values here: %d,%d\n", bestswap1, bestswap2);
            
            int val1=indexes[bestswap1];
            int val2=indexes[bestswap2];
            int bucket1=wheretheyare[bestswap1];
            int bucket2=wheretheyare[bestswap2];
            printf("hot in here 1\n");
            if(bucket1!=-1){
                int locationofval1=indexinbucket(b,info,bucket1,val1);
                if(locationofval1==-1){printf("algo incorreto!\n");}
                b.p[bucket1*info.tasks+locationofval1]=val2;
            }
            printf("hotter here 2\n");
            if(bucket2!=-1){
                int locationofval2=indexinbucket(b,info,bucket2,val2);
                if(locationofval2==-1){printf("something wrong inhere:)\n");}
                b.p[bucket2*info.tasks+locationofval2]=val1;

            }
            printf("absolutamente loco!\n");

        }
    
    }
}

bucket_t* grasp(info_t info,int timetospend, int things){
    int starttime=time(NULL);
    int optimalvalue=0;
    bucket_t* bpopt=0;//left undeclared for now...
    while(time(NULL)-starttime<3){
        bucket_t *bp=greedylocalsearch(info,things);
        printf("BEFORE: %d\n",totalbucket_val(bp,info));

        loc_search(bp, info,10,5);
        int newvalue=totalbucket_val(bp, info);
        printf("AFTER: %d\n",newvalue);
        if(newvalue>optimalvalue){
            printf("doing a switch!\n");
            if(bpopt!=0){
                //free(bpopt->p);
                //free(bpopt);
            }
            bpopt=bp;
            optimalvalue=newvalue;
        }
        


    }
    return bpopt;
}