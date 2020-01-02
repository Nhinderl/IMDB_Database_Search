/**
 * Name: Noah Hinderle
 * Student Number: 1053077
 * Email: nhinderl@uoguelph.ca
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "name.h"
#include "common.h"
#include "title.h"
#include "principals.h"
#include "binary.h"

int main(int argc, char **argv){

    FILE *fp;
    int actors, titles, principals, searchFlag = 0;

    char nextLine[1024], *tempPtr, *found, *mappedNconst, nConst[100], *mappedTconst, tConst[100], actorName[400], movieTitle[500], *title, temp, dataPath[1024], *tempTitle;

    struct name_basics *actorArray;
    struct title_basics *titleArray;
    struct title_principals *principalArray;
    struct name_node *nconstHead;
    struct name_node_smaller *nameHead;
    struct title_node *tconstHead;
    struct title_node_smaller *titleHead;
    struct principal_node *principalNconstHead, *principalTconstHead, *principalNext;


    /*reads from name.basics file to create array and trees*/
    if(argc > 1){

        strcpy(dataPath, argv[1]);
        strcat(dataPath, "/name.basics.tsv");

        fp = fopen(dataPath, "r");

        if(fp == NULL){

            fprintf(stderr, "failed to open file.\n");
            return 0;

        }

    }else{

        printf("No path specified, terminating program\n\n");
        return 0;

    }

    actors = getNumActors(fp);

    fseek(fp, 0, SEEK_SET);

    actorArray = createActorArray(actors, fp);

    nconstHead = makeNconstTree(actors, actorArray);

    nameHead = makeNameTree(actors, actorArray);

    fclose(fp);
    memset(dataPath, 0, strlen(dataPath));


    /*reads from title.basics file to create array and trees*/

    strcpy(dataPath, argv[1]);
    strcat(dataPath, "/title.basics.tsv");

    fp = fopen(dataPath, "r");

    if(fp == NULL){

        fprintf(stderr, "failed to open file.\n");
        return 0;

    }

    titles = getNumTitles(fp);

    fseek(fp, 0, SEEK_SET);

    titleArray = createTitleArray(titles, fp);

    tconstHead = makeTconstTree(titles, titleArray);

    titleHead = makeTitleTree(titles, titleArray);

    fclose(fp);

    memset(dataPath, 0, strlen(dataPath));


    /*reads from title.principals file to create array and trees*/
    strcpy(dataPath, argv[1]);
    strcat(dataPath, "/title.principals.tsv");

    fp = fopen(dataPath, "r");

    if(fp == NULL){

        fprintf(stderr, "failed to open file.\n");
        return 0;

    }

    principals = getNumPrincipals(fp);

    fseek(fp, 0, SEEK_SET);

    principalArray = createPrincipalArray(principals, fp);

    principalTconstHead = makePrincipalTconstTree(principals, principalArray);

    principalNconstHead = makePrincipalNconstTree(principals, principalArray);

    fclose(fp);

    memset(dataPath, 0, strlen(dataPath));


    /*main code to get user input and print the results*/
    while(1){

        searchFlag = 0;

        while(searchFlag == 0){

            printf("\n> ");
            scanf("%s", nextLine);

            if(strstr(nextLine, "name")){

                searchFlag = 1;
                tempPtr = actorName + 1;
                temp = fgetc(stdin);
                while(temp == ' '){

                    temp = fgetc(stdin);

                }
                actorName[0] = temp;
                scanf("%[^\n]s", tempPtr);


            }else if(strstr(nextLine, "title")){

                searchFlag = 2;
                tempPtr = movieTitle + 1;
                temp = fgetc(stdin);
                while(temp == ' '){

                    temp = fgetc(stdin);

                }
                movieTitle[0] = temp;
                scanf("%[^\n]s", tempPtr);

            }

        }

        memset(nextLine, 0, strlen(nextLine));

        if(actorName != NULL){

            if(searchFlag == 1){

                mappedNconst = searchByName(nameHead, actorName);
                if(mappedNconst){

                    strcpy(nConst, mappedNconst);

                    if(nConst != NULL){

                        mappedNconst = reMap(nConst);
                        principalNext = searchByPrincipalNconst(principalNconstHead, mappedNconst);

                        while(principalNext -> RChild != NULL){

                            strcpy(tConst, principalNext -> data -> tconst);
                            mappedTconst = reMap(tConst);
                            title = searchByTconst(tconstHead, mappedTconst);

                            if(title != NULL){

                                printf("%s : %s\n", title, principalNext -> data -> characters);

                            }

                            principalNext = searchByPrincipalNconst(principalNext -> RChild, mappedNconst);

                        }

                        strcpy(tConst, principalNext -> data -> tconst);
                        mappedTconst = reMap(tConst);
                        tempTitle = malloc(sizeof(char) * 8);
                        title = searchByTconst(tconstHead, mappedTconst);
                        free(tempTitle);

                        if(title != NULL){

                            printf("%s : %s\n", title, principalNext -> data -> characters);

                        }  

                    }
                }else{

                    printf("No records found\n");

                }
                

            }else if(searchFlag == 2){

                mappedTconst = searchByTitle(titleHead, movieTitle);
                if(mappedTconst){

                    strcpy(tConst, mappedTconst);
                    if(tConst != NULL){

                        mappedTconst = reMap(tConst);
                        principalNext = searchByPrincipalTconst(principalTconstHead, mappedTconst);

                        while((principalNext != NULL) && (principalNext -> RChild != NULL)){

                            strcpy(nConst, principalNext -> data -> nconst);
                            mappedNconst = reMap(nConst);
                            found = searchByNconst(nconstHead, mappedNconst);

                            if(found != NULL){

                                printf("%s : %s\n", found, principalNext -> data -> characters);

                            }

                            principalNext = searchByPrincipalTconst(principalNext -> RChild, mappedTconst);

                        }

                    }

                }else{

                    printf("No records found\n");

                }

            }

        }

    }

    return 0;

}

