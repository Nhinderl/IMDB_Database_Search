/**
 * Name: Noah Hinderle
 * Student Number: 1053077
 * Email: nhinderl@uoguelph.ca
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "name.h"
#include "common.h"

/*creates the array of all actors in the file*/
struct name_basics *createActorArray(int numStructs, FILE *fp){

    int tabCount, i, j, startReading, index;

    struct name_basics *actorArr = malloc(sizeof(struct name_basics) * (numStructs + 1));

    char nextLine[1024], nextProffesion[600], name[600], temp, *success, nConst[100];

    success = fgets(nextLine, 1000, fp);

    index = 0;

    memset(nextProffesion, 0, sizeof(nextProffesion));
    memset(name, 0, sizeof(name));
    memset(nConst, 0, sizeof(nConst));

    while(success != NULL){

        success = fgets(nextLine, 1000, fp);

        if(success != NULL){

            temp = nextLine[0];

            i = 0;
            j = 0;
            tabCount = 0;
            startReading = 0;

            while((temp != '\n') && (temp != '\0')){

                if(temp == '\t'){

                    tabCount++;
                    j = 0;

                }else{

                    if(tabCount == 0){

                        startReading = 3;

                    }else if(tabCount == 1){

                        startReading = 2;

                    }else if(tabCount == 2){

                        startReading = 0;

                    }else if(tabCount == 4){

                        startReading = 1;
                        

                    }else if(tabCount == 5){

                        startReading = 0;

                    }

                    if(startReading == 1){

                        nextProffesion[j] = temp;
                        j++;

                    }else if(startReading == 2){

                        name[j] = temp;
                        j++;

                    }else if(startReading == 3){

                        nConst[j] = temp;
                        j++;

                    }
                }

                i++;
                temp = nextLine[i];

            }
        }

        if((strstr(nextProffesion, "actor")) || (strstr(nextProffesion, "actress"))){

            actorArr[index].primaryName = strdup(name);
            actorArr[index].nconst = strdup(nConst);

            index++;

        }

        memset(nextProffesion, 0, sizeof(nextProffesion));
        memset(name, 0, sizeof(name));
        memset(nConst, 0, sizeof(nConst));

    }

    return actorArr;

}