#include "types.h"
#include "randomlist.h"
#include "get.h"
#include "objective_function.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "printallprocs.h"
#include "writetofile.h"
#include <stddef.h>
#include <stdint.h>
#include "weighted_binarysearch.h"
#include "int_arr_crossover.h"

long long millis_now(void) {
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    return ts.tv_sec * 1000LL + ts.tv_nsec / 1000000LL;
}


#define POPULATION 3000
#define MUTATION_RATE 0.01

void swap_up(int j, int *ip, int** ipp){
    int swap_int;
    int *swap_p;
    swap_int=ip[j];
    ip[j]=ip[j+1];
    ip[j+1]=swap_int;

    //swap the pointers: 
    swap_p=ipp[j];
    ipp[j]=ipp[j+1];
    ipp[j+1]=swap_p;
}

int random_parent(int** population, int* population_vals, int pop_size){
    int max_val = 0;
    for (int i = 0; i < pop_size; i++) {
        if (population_vals[i] > max_val) {
            max_val = population_vals[i];
        }
    }
    
    int total_inverse_value = 0;
    for (int i = 0; i < pop_size; i++) {
        total_inverse_value += (max_val - population_vals[i] + 1);
    }
    
    int r = rand() % total_inverse_value;
    
    int cum_sum = 0;
    for (int i = 0; i < pop_size; i++) {
        cum_sum += (max_val - population_vals[i] + 1);
        if (r < cum_sum) 
            return i;
    }
    return pop_size - 1; 
}

int random_individual_to_kill(int** population, int* population_vals, int total_value, int pop_size){
    int r = rand() % total_value;
    
    int cum_sum = 0;
    for (int i = 0; i < pop_size; i++) {
        cum_sum += population_vals[i];
        if (r < cum_sum) {
            return i;
        }
    }
    
    return pop_size - 1; 
}

int find_best_individual(int* population_vals, int pop_size){
    int best_index = 0;
    for (int i = 1; i < pop_size; i++) {
        if (population_vals[i] < population_vals[best_index]) {
            best_index = i;
        }
    }
    return best_index;
}

int find_worst_individual(int* population_vals, int pop_size){
    int worst_index = 0;
    for (int i = 1; i < pop_size; i++) {
        if (population_vals[i] > population_vals[worst_index]) {
            worst_index = i;
        }
    }
    return worst_index;
}

void copy_individual(int* source, int* destination, int length) {
    for (int i = 0; i < length; i++) {
        destination[i] = source[i];
    }
}

// genetic_algorithm_solver
int wholefunc(char* cp, char* towriteto, int intime_sec, double mutation_rate) {
    long long intime = (long long)intime_sec * 1000LL;
    info_t info=get(cp);
    int arrlen = info.len * info.len;
    
    int *population[POPULATION]; // population
    int population_vals[POPULATION]; // population_vals
    long long starttime=millis_now();
    //printf("got here!\n");
    //this is to initialize a random population. 
    
    int best_value = 0;
    int* best_individual = malloc(arrlen * sizeof(int));
    int total_value=0;
    for(int i=0;i<POPULATION;i++){
        int* ip=randomlist(arrlen);
        population[i]=ip;
        population_vals[i]=value(info,population[i]);
        total_value+=population_vals[i];
        if (i == 0 || population_vals[i] < best_value) {
            best_value = population_vals[i];
            copy_individual(population[i], best_individual, arrlen);
        }
    }
    
    //now I want to get it sorted:
    //I can probably change j<POPULATION-1 to j<POPULATION-1-i if I so wish because thats how bubble sort works. 
    // for(int i=0;i<POPULATION;i++){
        //     for(int j=0;j<POPULATION-1;j++){
            //         if(population_vals[j]>population_vals[j+1]){
                //            swap_up(j,population_vals,population);
                //         }
                //     }
                // } 
                /*
                for(int i=0;i<POPULATION;i++){
                    printf("%d: %d\n",i,population_vals[i]);
                    }
                    */
                    //printf("got here 2\n");
                    
    // double total_average_value = 0;
    int iterations = 0;
    int* current_individual = malloc(arrlen * sizeof(int));

    printf("[");
    while(millis_now()-starttime<intime){
        iterations++;
        if (iterations % 100 == 0) {
            double average_value = (double)total_value / POPULATION;
            printf("(%.2f, %d), ", average_value, best_value);
        }

        //printf("got here 3\n");
        int parent1 = random_parent(population, population_vals, POPULATION);
        int parent2 = random_parent(population, population_vals, POPULATION);
        int indiv_to_kill = random_individual_to_kill(population, population_vals, total_value, POPULATION);
        // int indiv_to_kill = find_worst_individual(population_vals, POPULATION);
        /*
        int =highint(POPULATION);
        int secint=highint(POPULATION);
        */
        //printf("first int: %d, second int: %d\n",firstint,secint);
        
        int_arr_crossover(population[parent1], population[parent2], current_individual, arrlen);
        mutate(population[indiv_to_kill], arrlen, mutation_rate);

        int current_value = value(info, current_individual);
        if (current_value > population_vals[indiv_to_kill])
            continue; 

        //printf("got a value\n");
        //printf("the value is %d\n",current_value);
        //printf("got here 4\n");
        copy_individual(current_individual, population[indiv_to_kill], arrlen);
        total_value -= population_vals[indiv_to_kill];
        total_value += current_value;

        population_vals[indiv_to_kill] = current_value;
        if (current_value < best_value) {
            best_value = current_value;
            copy_individual(population[indiv_to_kill], best_individual, arrlen);
        }
        //printf("got here 6\n");
        
    }
    printf("]\n");


    ap_and_val_t toprint = value_with_procs(info,best_individual);
    
    writetofile(info.len, toprint.ap, towriteto);
    killallprocs(toprint.ap);

    /*
    for(int i=0;i<POPULATION;i++){
        printf("%d ",population_vals[i]);
    }printf("\n");
    */

    //printf("iterations: %d\n",iterations);
    //printf("final value: %d\n",toprint.val);
    for(int i=0;i<POPULATION;i++){
        free(population[i]);
    }
    free(best_individual);
    free(current_individual);

    free(info.processors);
    free(info.duration);
    return toprint.val;
} 