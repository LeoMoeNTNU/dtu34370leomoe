#include "../types.h"
#include "../init.h"
#include "../get.h"

#include <stdio.h>
#include "../isallowedtoplacehere.h"

//int isallowedtoplacehere(info_t info, proc_list_t plt, int start, int end, int index);
void test1(){
    info_t info;
    proc_list_t plt;
    plt.len=3;
    int start=0;
    int end=1;
    int index=3;
    op_in_proc_t ops[3];
    ops[0].start=0;
    ops[0].end=2;
    ops[0].index=0;

    ops[1].start=4;
    ops[1].end=6;
    ops[1].index=10;

    ops[2].start=9;
    ops[2].end=10;
    ops[2].index=4;
    
    plt.p=ops;
    info.len=4;
    int a=isallowedtoplacehere(info, plt, start, end, index);
    printf("number we got should be 2 and is %d\n",a);



}

void test2(){
    info_t info;
    proc_list_t plt;
    plt.len=3;
    int start=1;
    int end=2;
    int index=3;
    op_in_proc_t ops[3];
    ops[0].start=0;
    ops[0].end=2;
    ops[0].index=0;

    ops[1].start=4;
    ops[1].end=6;
    ops[1].index=10;

    ops[2].start=9;
    ops[2].end=10;
    ops[2].index=4;
    
    plt.p=ops;
    info.len=4;
    int a=isallowedtoplacehere(info, plt, start, end, index);
    printf("number we got should be 2 and is %d\n",a);



}


void test3(){
    info_t info;
    proc_list_t plt;
    plt.len=3;
    int start=7;
    int end=9;
    int index=3;
    op_in_proc_t ops[3];
    ops[0].start=0;
    ops[0].end=2;
    ops[0].index=0;

    ops[1].start=4;
    ops[1].end=6;
    ops[1].index=10;

    ops[2].start=9;
    ops[2].end=10;
    ops[2].index=4;
    
    plt.p=ops;
    info.len=4;
    int a=isallowedtoplacehere(info, plt, start, end, index);
    printf("number we got should be 0 and is %d\n",a);



}


int main(){
    test1();
    test2();
    test3();

    return 0;
}