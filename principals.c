/**
 * Name: Noah Hinderle
 * Student Number: 1053077
 * Email: nhinderl@uoguelph.ca
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "principals.h"
#include "common.h"

/*creates the array of all of the title principals in the file*/
struct title_principals *createPrincipalArray(int numStructs, FILE *fp){

    int tabCount, i, j, startReading, index;

    struct title_principals *principalArr = malloc(sizeof(struct title_principals) * (numStructs + 1));

    char nextLine[1024], category[300], characters[400], temp, *success, nConst[100], tConst[100];

    success = fgets(nextLine, 1000, fp);

    index = 0;

    memset(nConst, 0, sizeof(nConst));
    memset(characters, 0, sizeof(characters));
    memset(tConst, 0, sizeof(tConst));
    memset(category, 0, sizeof(category));

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

                        startReading = 0;

                    }else if(tabCount == 2){

                        startReading = 2;

                    }else if(tabCount == 3){

                        startReading = 4;

                    }else if(tabCount == 4){
                        
                        startReading = 0;

                    }else if(tabCount == 5){

                        startReading = 1;

                    }

                    if(startReading == 1){

                        characters[j] = temp;
                        j++;

                    }else if(startReading == 2){

                        nConst[j] = temp;
                        j++;

                    }else if(startReading == 3){

                        tConst[j] = temp;
                        j++;

                    }else if (startReading == 4){

                        category[j] = temp;
                        j++;

                    }
                }

                i++;
                temp = nextLine[i];

            }
        }

        if((strcmp(category, "actor") == 0) || (strcmp(category, "actress") == 0)){

            principalArr[index].tconst = strdup(tConst);
            principalArr[index].nconst = strdup(nConst);
            principalArr[index].characters = strdup(characters);

            index++;

        }

        memset(nConst, 0, sizeof(nConst));
        memset(characters, 0, sizeof(characters));
        memset(tConst, 0, sizeof(tConst));
        memset(category, 0, sizeof(category));

    }

    return principalArr;

}
