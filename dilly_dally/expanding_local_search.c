/*
This one will do several things: 
1. It will start with a with of 2, and try to swap every combination of 2. 
2. Then it will try to swap every combination of 3. 
3. Then it will try to swap every combination of 4. 
int indexes[MAX];
bool active[MAX];
for(int i=0;)
    if(active[i])
    for(for j=i+1)
        for()

I really dont know how to write expansive yet. 
Maybe I just add a function. 




*/

/*
pattern for 4:
0,1,2,3
0,1,3,2 (shuffled last one)
0,2,1,3
0,2,3,1


*/

/*
pattern for 4: 
4x3x2x1
0: (rest 1,2,3)
    1: (2,3)
        2: (3)
            3:
        3: (2)
            2:
    2: (1,3)
        1: 3
            3
        3: 1
    3: 2,1
*/

/* the thing that will happen is that we make a stack of x length and for each of them we insert
//this function will see all the variations but won't do anything with them. 

localsearch(int max, bool* taken, int currently_taken, int* indexes_set){
    if(currently_taken==MAX):
        print the int array THIS IS TO CHECK IF IT HAS GOTTEN TO ALL
    for(int i=0;i<max;i++)
        if(*taken[i]):
            //taking the thing:
            indexes_set[currently_taken]=i;
            taken[i]=true;

            local_search(max,taken,currently_taken+1,indexes_set);

            //giving it back:
            indexes_set[currently_taken]=Ø
            taken[i]=false

}
    


*/
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>


int recursive_localsearch(int max, bool * taken, int * indexes_set, int currently_taken,void (*f)(int* ,int)){    
    if(currently_taken==max){
        f(indexes_set,max);
        return 0;
    }

    for(int i=0;i<max;i++){
        if(!taken[i]&&i!=currently_taken){
            
            //The reason for i!=currently_taken is fairly nuanced. 
            //The reason is to not revisit things. 

            taken[i]=true;
            indexes_set[currently_taken]=i;
            recursive_localsearch(max,taken,indexes_set,currently_taken+1,f);
            taken[i]=false;

        }
    }    


    return 0;
}

int expanding_localsearch(int max, void (*f)(int* ,int)){
    bool taken[max];
    int indexes_set[max];

    for(int i=0;i<max;i++){
        taken[i]=false;
    }

    recursive_localsearch(max,taken,indexes_set,0,f);
    return 0;
}

/*
There are several things to do after I have implemented the pattern roughly.
Right now I dont have a list of indexes that I am taking from, which I should probably have. 

Also, the returns don't do anything yet.

The thing right assumes that we will swap every number. Maybe I could do it better. 

The reasonable way to do this:
This function needs to have something that it can do when it has found all of the things. 
This function should just produce all the things sequentially. 
And then, from here, we can do things. 
We can give it a function that uses an int * and a len. 
From there, it will surely just do things corrently. 
Then, it just calls this function. 

Then an outer function will have an int array which moves things accordingly. 

*/