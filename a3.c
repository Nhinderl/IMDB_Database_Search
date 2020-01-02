#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "name.h"
#include "common.h"

int main(){

    FILE *fp;
    int actors;

    struct name_basics **array;

    fp = fopen("data.tsv", "r");

    if(fp == NULL){

        fprintf(stderr, "failed to open file.\n");
        return 0;

    }

    actors = getNumActors(fp);

    array = createArray(actors, fp);

    printf("%d\n", actors);

    return 0;

}