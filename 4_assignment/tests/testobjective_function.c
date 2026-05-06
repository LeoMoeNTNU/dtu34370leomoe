#include "../objective_function.h"

#include <stdio.h>
#include "../get.h"
    
void test1(){
    printf("TEST1\n");
    info_t info= get("Instances/leo_easy.sop");
    int ints[]={0,1,2,3};
    int value= objective_function(info,ints);
    if(value!=18)printf("why is the value %d and not 18?",value);
    
}

void test2(){
    printf("TEST2\n");
    info_t info= get("Instances/leo_easy.sop");
    int ints[]={0,1,2,3};
    int value= objective_function(info,ints);
    if(value!=18)printf("why is the value %d and not 18?",value);
    
    objective_function_alt(info,ints,1,2);//this one is supposed to change and then undo the change. 
    //I'm not checking because I'm not lazy, sadly. 
    
     value= objective_function(info,ints);
    if(value!=18)printf("on the reset, why is the value %d and not 18?",value);
    
}

int main(){
    test1();
    test2();
    return 0;
}