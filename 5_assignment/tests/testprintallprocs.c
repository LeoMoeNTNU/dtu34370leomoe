#include "../printallprocs.h"
#include <stdio.h>
//void printallprocs(allprocs_t ap);

void test1(){
    allprocs_t ap;
    ap.len=0;
    printallprocs(ap);
}

void test2(){
    op_in_proc_t op1={1,3,0};
    op_in_proc_t op2={5,7,1};
    op_in_proc_t opsfirst[]={op1,op2};
    proc_list_t pl1={2,opsfirst};

     op_in_proc_t op3={0,4,2};
    op_in_proc_t op4={4,7,3};
        op_in_proc_t op5={8,9,4};


    op_in_proc_t opssec[]={op3,op4,op5};
    proc_list_t pl2={3,opssec};

    proc_list_t all[]={pl1,pl2};

    allprocs_t ap={2,all};
    printallprocs(ap);




}

int main(){
    test1();
    test2();
    return 0;
}