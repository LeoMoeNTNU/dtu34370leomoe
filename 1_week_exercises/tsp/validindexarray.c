#include <stdbool.h>

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