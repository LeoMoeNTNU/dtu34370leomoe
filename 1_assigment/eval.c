#include "list_types.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

//it is implied that status pointer has matrix.len squared allocated to it. 
//I guess this one has to be pushed all the way down to distance so that we can fix things up from there. 

int matrixcheck(int x, int y, list_t matrix){
    //printf("segfault in matrixcheck\n");
    return matrix.p[matrix.len*x+y];
}

enum status statuscheck(int x, int y, list_t matrix){
    //printf("segfault in statuscheck\n");
    return matrix.sP[matrix.len*x+y];
}

void setstatus(int x, int y, list_t matrix, enum status stat){
    //printf("segfault in setstatus\n");
    matrix.sP[matrix.len*x+y]=stat;
}

void setdistance(int x, int y, int value, list_t matrix){
    matrix.p[matrix.len*x+y]=value;
}


bool hastobeafter(int x, int y, list_t matrix,bool* bp){
    if(bp[x]==true){return false;}
    bp[x]=true;
    enum status stat=statuscheck(x,y, matrix);
    if(stat==MINUSONE){
        bp[x]=false;
        return true;
    }
    if(stat==NOTMINUSONE){
        bp[x]=false;
        return false;
    }
    for(int i=0;i<matrix.len;i++){
        bool deeper=hastobeafter(i,y,matrix,bp);
        if(deeper==true){
            setstatus(x,y,matrix,MINUSONE);
            bp[x]=false;
            return true;
        }
    }
    setstatus(x,y,matrix,NOTMINUSONE);
    bp[x]=false;
    return false;

}

int localdistance2(int x, int y,list_t matrix){
    /*
    if(hastobeafter(y,x,matrix)){
        return 1000000;
    }
    */
    int dist=matrixcheck(x,y,matrix);
    
    return dist;
}

int localdistance(int x, int y, list_t matrix){
    /*
    ACTUAL PSEUDOCODE: 
    1. GET STATUS
    2. IF STATUS NOT MINUS ONE: RETURN VALUE IN MATRIX
    3. ELSE: RETURN VERY HIGH NUMBER.
    4. BEFORE THIS i NEED TO HAVE THE ACTUAL FUNCTION AND PROBABLY AN ACTUAL TEST FOR IT AS WELL. 
    */
   bool* bp=malloc(sizeof(bool)*matrix.len);
    if(hastobeafter(x,y,matrix,bp)){return 10000000;}
    free(bp);
    return matrixcheck(x,y,matrix);
}





int distance3nodes(int first, int second, int third, list_t matrix){
    return localdistance(first, second,matrix)+localdistance(second,third,matrix);
}

int distance4nodes(int first, int second, int third, int fourth, list_t matrix){
    return localdistance(first,second,matrix)+localdistance(second,third,matrix)+localdistance(third,fourth,matrix);
}




//assumes that the first
int distance(int* ip, list_t matrix){
    int currentnode=0;
    int distanceTravelled=0;
    for(int i=1;i<matrix.len;i++){
        distanceTravelled+=localdistance(currentnode,ip[i],matrix);
        currentnode=ip[i];
    }
    distanceTravelled+=localdistance(ip[matrix.len-1],ip[0],matrix);
    //printf("distance found: %d\n",distanceTravelled);
    return distanceTravelled;
}


