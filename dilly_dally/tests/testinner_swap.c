#include "../inner_swap.h"
#include "../types.h"

void test1(){
    /*
    Lets say:
    original_array is [5,7,1,2,33],
    indexes_to_swap is [1,4]
    order is [1,0] (only valid one with 2...)
    
    next array: [5,33,1,2,7]
    */
    int a[]={5,7,1,2,33};
    int b[]={1,4};
    int c[]={1,0};

    int_arr_t orig_arr;
    orig_arr.p=a;
    orig_arr.len=5;

    int_arr_t inds;
    inds.p=b;
    inds.len=2;

    int_arr_t order;
    order.p=c;
    order.len=2;
    
    info_t dummy;

    inner_swap(orig_arr,inds,order,0,dummy);
    inner_swap(orig_arr,inds,order,0,dummy);
    inner_swap(orig_arr,inds,order,0,dummy);
    inner_swap(orig_arr,inds,order,0,dummy);


    //void inner_swap(int_arr_t original_array, int_arr_t indexes_to_swap, int_arr_t order, int orig_val,info_t info)

}

int main(){
    test1();
    return 0;
}