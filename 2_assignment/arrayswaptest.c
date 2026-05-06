#include <stdio.h>

int main(){
    int indexes[]={0,3,2,1};
    int vals[]={5,3,2,1};

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

    for(int i=0;i<4;i++){
        printf("%d ",indexes[i]);
    }
    printf("\n");
    for(int i=0;i<4;i++){
        printf("%d ",vals[i]);
    }
    printf("\n");


    return 0;
}