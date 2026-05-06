#include <stdio.h>
#include "../tl_contains.h"
#include "../init_tl.h"
#include "../insert_into_tl.h"

void test1(){
    printf("TEST1\n");
    int a[]={1,2,3};
    
    tl_t tl=init_tb_list(2, 3);

    for(int i=0;i<6;i++){printf("%d ",tl.p[i]);}printf("\n");
    for(int i=0;i<3;i++){printf("%d ",a[i]);}printf("\n");
    if(tl_contains(tl,a,false)){printf("why does it contain, it is empty!\n");}
     insert_into_tl(tl, a,true);
     if(!tl_contains(tl,a,false)){printf("why doesn't it contain now huh?\n");}
    int b[]={3,3,4};
    if(tl_contains(tl,b,false)){printf("shouldnt have this!\n");}
    insert_into_tl(tl,b,true);
    printf("arrays in tl:\n");
    for(int i=0;i<3;i++){printf("%d ",tl.p[i]);}printf("\n");
        for(int i=3;i<6;i++){printf("%d ",tl.p[i]);}printf("\n");

    if(!tl_contains(tl,a,false)){printf("it should have a\n");}
    if(!tl_contains(tl,b,false)){printf("it should also have b!\n");}
    int c[]={3,2,1};
    if(tl_contains(tl,c,false)){printf("makes no fucking sense!\n");}
    insert_into_tl(tl,c,false);
    if(tl_contains(tl,a,false)){printf("that's weird!\n");}
    if(!tl_contains(tl,b,false)){printf("odd stuff\n");}
    if(!tl_contains(tl,c,false)){printf(" even odder...scary\n");}


}


int main(){
    test1();

    return 0;
}