#include "types.h"
#include "stdlib.h"
#include "infotools.h"
#include "stdio.h"

allprocs_t init(info_t info){
    allprocs_t ret;
    ret.len=info.len;
    ret.p=malloc(sizeof(proc_list_t)*info.len);
    //now I am initializing them all to 0 before then I'm after setting it up.
    for(int i=0;i<info.len;i++){
        ret.p[i].len=0;
    }

    for(int i=0;i<info.len;i++){
        //printf("allocating %d\n",info.len);
        ret.p[i].p=malloc(sizeof(op_in_proc_t)*info.len);
        for(int j=0;j<ret.p[i].len;j++){
            ret.p[i].p[j].index=-1;
        }
    }
    /*
    for(int i=0;i<info.len;i++){
        printf("%d\n",ret.p[i].len);
    }
    */
    return ret;


}