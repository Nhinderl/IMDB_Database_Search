/**
 * Name: Noah Hinderle
 * Student Number: 1053077
 * Email: nhinderl@uoguelph.ca
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "common.h"

/*gets the number of actors and actresses in the file*/
int getNumActors(FILE *fp){

    int tabCount, i, j, startReading, actorCount = 0;

    char nextLine[1024], nextProffesion[400], temp, *success;

    success = fgets(nextLine, 1000, fp);

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

                }else{

                    if(tabCount == 4){

                        startReading = 1;

                    }else if(tabCount == 5){

                        startReading = 0;

                    }
                    if(startReading == 1){

                        nextProffesion[j] = temp;
                        j++;

                    }

                }

                i++;
                temp = nextLine[i];

            }
        }

        if((strstr(nextProffesion, "actor")) || (strstr(nextProffesion, "actress"))){

            actorCount++;

        }

        memset(nextProffesion, 0, sizeof(nextProffesion));

    }

    return actorCount;

}

/*gets the number of titles in the given categories in the file*/
int getNumTitles(FILE *fp){

    int tabCount, i, j, startReading, titleCount = 0;

    char nextLine[1024], nextTitleType[600], isAdult[600], temp, *success;

    success = fgets(nextLine, 1000, fp);

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

                    if(tabCount == 1){

                        startReading = 1;

                    }else if(tabCount == 2){

                        startReading = 0;

                    }else if(tabCount == 4){

                        startReading = 2;

                    } else if(tabCount == 5){

                        startReading = 0;

                    }

                    if(startReading == 1){

                        nextTitleType[j] = temp;
                        j++;

                    }else if(startReading == 2){

                        isAdult[j] = temp;
                        j++;

                    }

                }

                i++;
                temp = nextLine[i];

            }
        }

        if((strcmp(nextTitleType, "movie") == 0) && (strcmp(isAdult, "0") == 0)){

            titleCount++;

        }

        memset(nextTitleType, 0, sizeof(nextTitleType));
        memset(isAdult, 0, sizeof(isAdult));

    }

    return titleCount;

}

/*gets the number of title principlas in the file*/
int getNumPrincipals(FILE *fp){

    int tabCount, i, j, startReading, principalCount = 0;

    char nextLine[1024], category[500], temp, *success;

    success = fgets(nextLine, 1000, fp);

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

                }else{

                    if(tabCount == 3){

                        startReading = 1;

                    }else if(tabCount == 4){

                        startReading = 0;

                    }
                    if(startReading == 1){

                        category[j] = temp;
                        j++;

                    }

                }

                i++;
                temp = nextLine[i];

            }
        }

        if((strcmp(category, "actor") == 0) || (strcmp(category, "actress") == 0)){

            principalCount++;

        }

        memset(category, 0, sizeof(category));

    }

    return principalCount;

}

/*duplicates the given string and returns a pointer to it*/
char *strdup(char *s){

    char *ret;

    ret = malloc(strlen(s) + 1);
    strcpy(ret, s);
    return ret;

}

/*remaps the given string and returns a pointer to it*/
char *reMap(char *nConst){

    char temp[20], *ret;

    temp[0] = nConst[8];
    temp[1] = nConst[7];
    temp[2] = nConst[6];
    temp[3] = nConst[5];
    temp[4] = nConst[4];
    temp[5] = nConst[3];
    temp[6] = nConst[2];
    temp[7] = nConst[1];
    temp[8] = nConst[0];
    temp[9] = '\0';

    ret = malloc(strlen(temp) + 1);

    strcpy(ret, temp);

    return ret;

}
