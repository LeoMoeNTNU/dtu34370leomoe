#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LENGTH 40

void int_arr_crossover(int *parent1, int *parent2, int *child, int length)
{
    // Randomly shuffle parent1 and parent2
    if (rand() % 2)
    {
        int *temp = parent1;
        parent1 = parent2;
        parent2 = temp;
    }

    // Create a mapping from parent1 to parent2 and track visited elements
    int map[MAX_LENGTH];
    int visited[MAX_LENGTH];
    for (int i = 0; i < length; i++)
    {
        map[parent1[i]] = parent2[i];
        visited[i] = 0;
    }

    // Randomly select two split points
    int split1 = rand() % length;
    int split2 = rand() % length;
    if (split1 > split2)
    {
        int temp = split1;
        split1 = split2;
        split2 = temp;
    }

    // Copy the middle segment from parent1 to child and mark visited elements
    for (int i = split1; i <= split2; i++)
    {
        child[i] = parent1[i];
        visited[parent1[i]] = 1;
    }

    // Fill the remaining positions in child with elements from parent2
    for (int i = 0; i < length; i++)
    {
        if (i >= split1 && i <= split2)
            continue; // Skip the middle segment

        int candidate = parent2[i];
        while (visited[candidate])
        {
            candidate = map[candidate]; // Follow the mapping until an unvisited element is found
        }
        child[i] = candidate;
        visited[candidate] = 1; // Mark the candidate as visited
    }
}


