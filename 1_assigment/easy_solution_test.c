#include <stdio.h>
#include "list_types.h"
#include "easy_solution_test_interface.h"
#include "getmatrix.h"
#include <stdbool.h>

#include "eval.h"

void testinsertifallallowed(){
    list_t matrix=getmatrix("/home/moeth/optimization_metaheuristics/1_assigment/Instances/leo1.sop");

    bool bp[matrix.len];
    for(int i=0;i<matrix.len;i++){
        bp[i]=true;
    }
    int testerrors=0;
    for(int i=0;i<matrix.len;i++){
        bool assumed=(i==0)?false:true;
        bool actual=isvalidinsertion(matrix,i,bp);
        if(assumed!=actual){
            printf("assumed %d and got %d\n",assumed,actual);
            testerrors++;
        }
    }
    printf("total amount of errors: %d\n",testerrors);
    //bool isvalidinsertion(list_t matrix, int i, bool* allowed);

}

void testinsertifnothingallowed(){
    list_t matrix=getmatrix("/home/moeth/optimization_metaheuristics/1_assigment/Instances/leo1.sop");

    bool bp[matrix.len];
    for(int i=0;i<matrix.len;i++){
        bp[i]=false;
    }
    int testerrors=0;
    for(int i=0;i<matrix.len;i++){
        bool assumed=false;
        bool actual=isvalidinsertion(matrix,i,bp);
        if(assumed!=actual){
            printf("assumed %d and got %d\n",assumed,actual);
            testerrors++;
        }
    }
    printf("total amount of errors if everything assumed false!: %d\n",testerrors);
    //bool isvalidinsertion(list_t matrix, int i, bool* allowed);

}


void testvalidinsertion(){
    list_t matrix=getmatrix("/home/moeth/optimization_metaheuristics/1_assigment/Instances/ESC63.sop");
    bool allowed[matrix.len];
    for(int i=0;i<matrix.len;i++){allowed[i]=true;}
    int errors=0;
    /*
    printf("we are testing (0,2) which for some reason is wrong!\n");
    for(int i=0;i<matrix.len;i++){
        printf("localdistance for (0,%d) is %d\n",i,localdistance2(0,i,matrix));
    }
    */
    int assumed=0;
    int actual=valid_insertion(matrix,allowed);
    if(assumed!=actual){
        printf("we expected %d and got %d, weirdly\n",assumed,actual);
        errors++;
    }
     //printf("we are testing (0,2) which for some reason is wrong!\n");
    for(int i=0;i<matrix.len;i++){
        //printf("localdistance for (0,%d) is %d\n",i,localdistance2(0,i,matrix));
    }

    //in this matrix, 0 has to be chosen, so if I make 0 impossible, then I assume it won't work!
    allowed[0]=false;
    assumed=-1;
    actual=valid_insertion(matrix,allowed);
    if(assumed!=actual){
        printf("in this edgecase we expected %d and got %d, weirdly\n",assumed,actual);
        errors++;
    }
    printf("in testvalidinsertion we got %d errors\n",errors);

    

}
/*
int valid_insertion(list_t matrix,bool* allowed){
    for(int i=0;i<matrix.len;i++){
        //now we are investigating i. 
        if(isvalidinsertion(matrix,i,allowed)){return i;}
    }
    return -1;
}
*/
void testfull1(bool print){
    list_t matrix=getmatrix("/home/moeth/optimization_metaheuristics/1_assigment/Instances/ESC63.sop");
    int *ip= basic_valid(matrix);
    if(print){

        for(int i=0;i<matrix.len;i++){
            printf("index%d: %d\n",i,ip[i]);
        }
    }


    return ;
}

void testfull2(bool print){
  
    list_t matrix=getmatrix("/home/moeth/optimization_metaheuristics/1_assigment/Instances/leo1.sop");
    int *ip= basic_valid(matrix);
    if(print){

        for(int i=0;i<matrix.len;i++){
            printf("index%d: %d\n",i,ip[i]);
        }
    }


    return ;

}

void testfull3(bool print){
  
    list_t matrix=getmatrix("/home/moeth/optimization_metaheuristics/1_assigment/Instances/ESC47.sop");
    int *ip= basic_valid(matrix);
    if(print){

        for(int i=0;i<matrix.len;i++){
            printf("index%d: %d\n",i,ip[i]);
        }
    }


    return ;

}

void testfull4(bool print){
  
    list_t matrix=getmatrix("/home/moeth/optimization_metaheuristics/1_assigment/Instances/ft53.2.sop");
    int *ip= basic_valid(matrix);
    if(print){

        for(int i=0;i<matrix.len;i++){
            printf("%d ",ip[i]);
        }
        printf("\n");
    }


    return ;

}


int main(){
    testinsertifallallowed();
    testinsertifnothingallowed();
    testvalidinsertion();

    testfull1(false);
    testfull2(false);
    testfull3(false);
    testfull4(true);





    return 0;
}