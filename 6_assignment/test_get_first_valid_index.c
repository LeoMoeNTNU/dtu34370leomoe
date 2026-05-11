#include "get_first_valid_index.h"
#include "types.h"
#include <stdio.h>

//int getfirstvalidindex(int firstvalidtime, int duration, op_in_proc_t* array, int arraylength)

/*
typedef struct {
    int start;
    int end;
    //int end; //I just deduce this whenever I need it lol. 
    int processorFrom;
    int indexinjob;
} op_in_proc_t;
*/
void test1basic(int a){
    if(a<0){printf("I'm using the test wrong with %d under 0!\n",a);}
    int ans= getfirstvalidindex(a, 5, 0, 0);
    if(ans!=a)printf("answer is %d and should be %d\n",ans,a);
}

void testoneelem(){
    op_in_proc_t ops[1];
    ops[0].start=3;
    ops[0].end=6;
   
    int a1=getfirstvalidindex(0,2,ops,3);
    if(a1!=0){
        printf("an error in here, answer is %d instead of 0\n",a1);
    }


}


void test2(){
    op_in_proc_t ops[3];
    ops[0].start=0;
    ops[0].end=2;
    ops[1].start=4;
    ops[1].end=6;
    ops[2].start=9;
    ops[2].end=10;
    int a1=getfirstvalidindex(0,2,ops,3);
    if(a1!=2){
        printf("an error in here, answer is %d instead of 2\n",a1);
    }
    else{
        printf("FOUND A VALID VALUE!\n");
    }


}


void test3(){
    //supposed to end at the end by changing the duration!
    op_in_proc_t ops[3];
    ops[0].start=0;
    ops[0].end=2;
    ops[1].start=4;
    ops[1].end=6;
    ops[2].start=9;
    ops[2].end=10;
    int a1=getfirstvalidindex(0,20,ops,3);
    int correct=10;
    if(a1!=correct){
        printf("an error in here, answer is %d instead of %d\n",a1,correct);
    }
    else{
        printf("FOUND A VALID VALUE!\n");
    }


}


int main(){
    /*
    for(int i=0;i<10;i++){
        test1basic(i);
    }
    */
    //test2();
    //testoneelem();
    test3();
    return 0;

}