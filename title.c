/**
 * Name: Noah Hinderle
 * Student Number: 1053077
 * Email: nhinderl@uoguelph.ca
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "title.h"
#include "common.h"

/*creates the array of all of the titles in the file*/
struct title_basics *createTitleArray(int numStructs, FILE *fp){

    int tabCount, i, j, startReading, index;

    struct title_basics *titleArr = malloc(sizeof(struct title_basics) * (numStructs + 1));

    char nextLine[1024], nextTitleType[600], isAdult[600], temp, *success, tConst[100], title[600];

    success = fgets(nextLine, 1000, fp);

    index = 0;

    memset(nextTitleType, 0, sizeof(nextTitleType));
    memset(isAdult, 0, sizeof(isAdult));
    memset(tConst, 0, sizeof(tConst));
    memset(title, 0, sizeof(title));

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

                        startReading = 4;

                    }else if(tabCount == 3){

                        startReading = 0;

                    }else if(tabCount == 4){

                        startReading = 1; 

                    }else if(tabCount == 5){

                        startReading = 0;

                    }

                    if(startReading == 1){

                        isAdult[j] = temp;
                        j++;

                    }else if(startReading == 2){

                        nextTitleType[j] = temp;
                        j++;

                    }else if(startReading == 3){

                        tConst[j] = temp;
                        j++;

                    }else if(startReading == 4){

                        title[j] = temp;
                        j++;

                    }
                }

                i++;
                temp = nextLine[i];

            }
        }

        if((strcmp(nextTitleType, "movie") == 0) && (strcmp(isAdult, "0") == 0)){

            titleArr[index].primaryTitle = strdup(title);
            titleArr[index].tconst = strdup(tConst);

            index++;

        }

        memset(nextTitleType, 0, sizeof(nextTitleType));
        memset(isAdult, 0, sizeof(isAdult));
        memset(tConst, 0, sizeof(tConst));
        memset(title, 0, sizeof(title));

    }

    return titleArr;

}