#include <stdio.h>
#include "types.h"
#include "get.h"
#include "greedylocalsearch.h"
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>
#include "bucket.h"
#include "objective.h"
#include "localsearch.h"

int main(){
    //this sets a seed so that I can call rand() effectively
    srand(time(NULL));
    //info_t info=get("Instances/jeu_100_25_10_3.txt");
    //Instances\jeu_100_25_10_3.txt
    //info_t info=get("Instances/jeu_100_75_5_3.txt");
    info_t info=get("Instances/leosimplesample.txt");
    /*
    for(int i=0;i<info.tasks;i++){
        printf("task has immediate cost %d and duration: %d\n",info.rev_values[i],info.prodtimes[i]);
    }
    */



    bucket_t* bp=greedylocalsearch(info,3);
    printf("value: %d\n",totalbucket_val(bp,info));

    for(int i=0;i<3;i++){
        int loc_len=len(bp, i);
        printf("bucket %d: len %d\n",i,loc_len);
        printf("without deleting, time left: %d\n",timeupuntilhere(bp,info,i,loc_len+1));
        printf("with deleting, time left: %d\n",timeupuntilhere(bp,info,i,loc_len));


        //timeupuntilhere(bucket_t* bp, info_t info, int bucket, int index)
    }
    

    //loc_search(bp, info, 10, 4);
    //printf("value: %d\n",totalbucket_val(bp,info));
    return 0;



}