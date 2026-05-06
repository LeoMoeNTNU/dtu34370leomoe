#include "list_types.h"
#include "easy_solution.h"
#include "getmatrix.h"
#include <stdio.h>
#include <string.h>
//#include "eval.h"
/*
int main(int argc, char ** args){
    if(argc!=2){printf("needs to be 2 arguments!\n");
        return -1;
    }
    list_t matrix=getmatrix(args[1]);
    int * ip=basic_valid(matrix);
    for(int i=0;i<matrix.len;i++){
        printf("%d ",ip[i]);
    }
    printf("\n");
    
    return 0;
}
*/

int main(int argc, char **args) {
    if (argc != 2) {
        printf("needs to be 2 arguments!\n");
        return -1;
    }

    list_t matrix = getmatrix(args[1]);
    int *ip = basic_valid(matrix);

    // Build output filename: "sol/<basename>"
    const char *input = args[1];
    const char *slash = strrchr(input, '/');
    const char *basename = slash ? slash + 1 : input;

    char outpath[256];
    snprintf(outpath, sizeof(outpath), "sol/%s", basename);

    FILE *f = fopen(outpath, "w");
    if (!f) {
        perror("fopen");
        return 1;
    }

    for (int i = 0; i < matrix.len; i++) {
        fprintf(f, "%d ", ip[i]);
    }
    fprintf(f, "\n");

    fclose(f);
    return 0;
}

