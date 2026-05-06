#include "../wholefunction.h"

void test1(){

    wholefunc("Instances/CloudComp_instances/tai4_4_2.txt","ex",10);
}

void test2(){

    wholefunc("Instances/CloudComp_instances/tai20_20_2.txt","nje",10);
}

void test3(){

    wholefunc("Instances/CloudComp_instances/tai15_15_2.txt","locfil",5);
}

int main(){
    test3();
    return 0;
}