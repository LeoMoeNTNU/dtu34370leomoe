#include <time.h>//I imagine that this is where we'll get it. 
#include <stdlib.h>

void fillarraywithrandom(int * ip, int len, int maxnum){
    if(maxnum<len){maxnum=len;}
    int ind=0;
    while(ind<len){

        int insert=rand()%maxnum;
        for(int j=0;j<ind;j++){
            if(ip[j]==insert){
                goto failed; 
            }
        }
        ip[ind]=insert;
        ind++;
        failed:
    }
}

