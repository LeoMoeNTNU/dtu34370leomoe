#include "../types.h"
#include <stdio.h>
#include "../placeopinjob.h"
//This one is going to write to one higher because it exists that this exists.
//assumes that it is a valid insert.
//void placeopinjob(op_in_proc_t* p, int len, op_in_proc_t in);
void testplacebefore(){

    op_in_proc_t ops[3];
    ops[0]=(op_in_proc_t){2,3,0};
    ops[1]=(op_in_proc_t){4,5,0};
    placeopinjob(ops, 2, (op_in_proc_t){0,1,0});
    if(ops[0].start!=0||ops[0].end!=1){
        printf("first element may be wrong!");
    }
    if(ops[1].start!=2||ops[1].end!=3){
        printf("second element may be wrong!");
    }
     if(ops[2].start!=4||ops[2].end!=5){
        printf("third element may be wrong, value here is (%d,%d)\n",ops[2].start,ops[2].end);
    }





}

void testplacemiddle(){
    op_in_proc_t ops[3];
    ops[0]=(op_in_proc_t){2,3,0};
    ops[1]=(op_in_proc_t){4,5,0};
    placeopinjob(ops, 2, (op_in_proc_t){3,4,0});
    if(ops[0].start!=2||ops[0].end!=3){
        printf("first element may be wrong!\n");
    }
    if(ops[1].start!=3||ops[1].end!=4){
        printf("second element may be wrong!\n");
    }
     if(ops[2].start!=4||ops[2].end!=5){
        printf("third element may be wrong, value here is (%d,%d)\n",ops[2].start,ops[2].end);
    }

}

void testend(){
     op_in_proc_t ops[3];
    ops[0]=(op_in_proc_t){2,3,0};
    ops[1]=(op_in_proc_t){4,5,0};
    placeopinjob(ops, 2, (op_in_proc_t){7,11,0});
    if(ops[0].start!=2||ops[0].end!=3){
        printf("first element may be wrong!\n");
    }
    if(ops[1].start!=4||ops[1].end!=5){
        printf("second element may be wrong!\n");
    }
     if(ops[2].start!=7||ops[2].end!=11){
        printf("third element may be wrong, value here is (%d,%d)\n",ops[2].start,ops[2].end);
    }

}

void screechonerror(){

      op_in_proc_t ops[3];
    ops[0]=(op_in_proc_t){2,3,0};
    ops[1]=(op_in_proc_t){4,5,0};
    printf("expecting an error here!\n");
    placeopinjob(ops, 2, (op_in_proc_t){3,5,0});
    


}

int main(){
testplacebefore();
testplacemiddle();
screechonerror();
    return 0;
}