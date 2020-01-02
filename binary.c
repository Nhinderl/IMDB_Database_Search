/**
 * Name: Noah Hinderle
 * Student Number: 1053077
 * Email: nhinderl@uoguelph.ca
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "name.h"
#include "title.h"
#include "principals.h"
#include "common.h"
#include "binary.h"

/*makes the tree of actors based on their nconst values*/
struct name_node *makeNconstTree(int length, struct name_basics *nameArray){

    int i;

    struct name_basics *tempNode;
    struct name_node *nodeToAdd, *head;

    char nConst[100], *tempKey;

    for(i = 0; i < length; i++){

        nodeToAdd = malloc(sizeof(struct name_node));

        tempNode = &(nameArray[i]);

        strcpy(nConst, tempNode -> nconst);

        tempKey = reMap(nConst);

        nodeToAdd -> key = tempKey;

        nodeToAdd -> data = tempNode;

        nodeToAdd -> RChild = NULL;
        nodeToAdd -> LChild = NULL;

        if(i == 0){

            head = nodeToAdd;

        }else{

            writeNconstToTree(head, nodeToAdd);

        }

    }

    return head;

}

/*makes the tree of actors based on their names*/
struct name_node_smaller *makeNameTree(int length, struct name_basics *nameArray){

    int i;

    struct name_basics *tempNode;
    struct name_node_smaller *nodeToAdd, *head;

    char name[300];

    for(i = 0; i < length; i++){

        nodeToAdd = malloc(sizeof(struct name_node_smaller));

        tempNode = &(nameArray[i]);

        strcpy(name, tempNode -> primaryName);

        nodeToAdd -> data = tempNode;

        nodeToAdd -> RChild = NULL;
        nodeToAdd -> LChild = NULL;

        if(i == 0){

            head = nodeToAdd;

        }else{

            writeNameToTree(head, nodeToAdd);

        }

    }

    return head;

}

/*makes the tree of titles based on their tconst values*/
struct title_node *makeTconstTree(int length, struct title_basics *titleArray){

    int i;

    struct title_basics *tempNode;
    struct title_node *nodeToAdd, *head;

    char tConst[100], *tempKey;

    for(i = 0; i < length; i++){

        nodeToAdd = malloc(sizeof(struct title_node));

        tempNode = &(titleArray[i]);

        strcpy(tConst, tempNode -> tconst);

        tempKey = reMap(tConst);

        nodeToAdd -> key = tempKey;

        nodeToAdd -> data = tempNode;

        nodeToAdd -> RChild = NULL;
        nodeToAdd -> LChild = NULL;

        if(i == 0){

            head = nodeToAdd;

        }else{

            writeTconstToTree(head, nodeToAdd);

        }

    }

    return head;

}

/*makes the tree of titles based on their title*/
struct title_node_smaller *makeTitleTree(int length, struct title_basics *titleArray){

    int i;

    struct title_basics *tempNode;
    struct title_node_smaller *nodeToAdd, *head;

    char title[600];

    for(i = 0; i < length; i++){

        nodeToAdd = malloc(sizeof(struct title_node_smaller));

        tempNode = &(titleArray[i]);

        strcpy(title, tempNode -> primaryTitle);

        nodeToAdd -> data = tempNode;

        nodeToAdd -> RChild = NULL;
        nodeToAdd -> LChild = NULL;

        if(i == 0){

            head = nodeToAdd;

        }else{

            writeTitleToTree(head, nodeToAdd);

        }

    }

    return head;

}

/*makes the tree of title principals based on their tconst values*/
struct principal_node *makePrincipalTconstTree(int length, struct title_principals *principalArray){

    int i;

    struct title_principals *tempNode;
    struct principal_node *nodeToAdd, *head;

    char tConst[100], *tempKey;

    for(i = 0; i < length; i++){

        nodeToAdd = malloc(sizeof(struct principal_node));

        tempNode = &(principalArray[i]);

        strcpy(tConst, tempNode -> tconst);

        tempKey = reMap(tConst);

        nodeToAdd -> key = tempKey;

        nodeToAdd -> data = tempNode;

        nodeToAdd -> RChild = NULL;
        nodeToAdd -> LChild = NULL;

        if(i == 0){

            head = nodeToAdd;

        }else{

            writePrincipalTconstToTree(head, nodeToAdd);

        }

    }

    return head;

}

/*makes the tree of title principals based on their nconst values*/
struct principal_node *makePrincipalNconstTree(int length, struct title_principals *principalArray){

    int i;

    struct title_principals *tempNode;
    struct principal_node *nodeToAdd, *head;

    char nConst[100], *tempKey;

    for(i = 0; i < length; i++){

        nodeToAdd = malloc(sizeof(struct principal_node));

        tempNode = &(principalArray[i]);

        strcpy(nConst, tempNode -> nconst);

        tempKey = reMap(nConst);

        nodeToAdd -> key = tempKey;

        nodeToAdd -> data = tempNode;

        nodeToAdd -> RChild = NULL;
        nodeToAdd -> LChild = NULL;

        if(i == 0){

            head = nodeToAdd;

        }else{

            writePrincipalNconstToTree(head, nodeToAdd);

        }

    }

    return head;

}

/*writes the given node to the tree based on its nconst value*/
void writeNconstToTree(struct name_node *next, struct name_node *node){

    if(strcmp(node -> key, next -> key) >= 0){

        if(next -> RChild != NULL){

            writeNconstToTree(next -> RChild, node);

        }else{

            next -> RChild = node;

        }

    }else{

        if(next -> LChild != NULL){

            writeNconstToTree(next -> LChild, node);

        }else{

            next -> LChild = node;

        }

    }

}

/*writes the given node to the tree based on its name*/
void writeNameToTree(struct name_node_smaller *next, struct name_node_smaller *node){

    if(strcmp(node -> data -> primaryName, next -> data -> primaryName) >= 0){

        if(next -> RChild != NULL){

            writeNameToTree(next -> RChild, node);

        }else{

            next -> RChild = node;

        }

    }else{

        if(next -> LChild != NULL){

            writeNameToTree(next -> LChild, node);

        }else{

            next -> LChild = node;

        }

    }

}

/*writes the given node to the tree based on its tconst value*/
void writeTconstToTree(struct title_node *next, struct title_node *node){

    if(strcmp(node -> key, next -> key) >= 0){

        if(next -> RChild != NULL){

            writeTconstToTree(next -> RChild, node);

        }else{

            next -> RChild = node;

        }

    }else{

        if(next -> LChild != NULL){

            writeTconstToTree(next -> LChild, node);

        }else{

            next -> LChild = node;

        }

    }

}

/*writes the given title to the tree based on its name*/
void writeTitleToTree(struct title_node_smaller *next, struct title_node_smaller *node){

    if(strcmp(node -> data -> primaryTitle, next -> data -> primaryTitle) >= 0){

        if(next -> RChild != NULL){

            writeTitleToTree(next -> RChild, node);

        }else{

            next -> RChild = node;

        }

    }else{

        if(next -> LChild != NULL){

            writeTitleToTree(next -> LChild, node);

        }else{

            next -> LChild = node;

        }

    }

}

/*writes the given title principal to the tree based on its tconst value*/
void writePrincipalTconstToTree(struct principal_node *next, struct principal_node *node){

    if(strcmp(node -> key, next -> key) >= 0){

        if(next -> RChild != NULL){

            writePrincipalTconstToTree(next -> RChild, node);

        }else{

            next -> RChild = node;

        }

    }else{

        if(next -> LChild != NULL){

            writePrincipalTconstToTree(next -> LChild, node);

        }else{

            next -> LChild = node;

        }

    }

}

/*writes the given title principal to the tree based on its nconst value*/
void writePrincipalNconstToTree(struct principal_node *next, struct principal_node *node){

    if(strcmp(node -> key, next -> key) >= 0){

        if(next -> RChild != NULL){

            writePrincipalNconstToTree(next -> RChild, node);

        }else{

            next -> RChild = node;

        }

    }else{

        if(next -> LChild != NULL){

            writePrincipalNconstToTree(next -> LChild, node);

        }else{

            next -> LChild = node;

        }

    }

}

/*searches for a name based on its nconst value*/
char *searchByNconst(struct name_node *next, char *nConst){

    int result = strcmp(next -> key, nConst);
    char *ret;

    if(result == 0){

        ret = next -> data -> primaryName;

    }else if(result < 0){

        if(next -> RChild != NULL){

            ret = searchByNconst(next -> RChild, nConst);

        }else{

            ret = NULL;

        }

    }else if(result > 0){

        if(next -> LChild != NULL){
        
            ret = searchByNconst(next -> LChild, nConst);

        }else{

            ret = NULL;

        }

    }

    return ret;

}

/*searches for an nconst value based on the actor's name*/
char *searchByName(struct name_node_smaller *next, char *name){

    int result = strcmp(next -> data -> primaryName, name);
    char *ret;

    if(result == 0){
        
        ret = next -> data -> nconst;

    }else if(result < 0){

        if(next -> RChild != NULL){
        
            ret = searchByName(next -> RChild, name);

        }else{

            ret = NULL;

        }

    }else if(result > 0){

        if(next -> LChild != NULL){
        
            ret = searchByName(next -> LChild, name);

        }else{

            ret = NULL;

        }

    }

    return ret;

}

/*searches for a tconst value based on the title*/
char *searchByTitle(struct title_node_smaller *next, char *title){

    int result = strcmp(next -> data -> primaryTitle, title);
    char *ret;

    if(result == 0){
        
        ret = next -> data -> tconst;

    }else if(result < 0){

        if(next -> RChild != NULL){
        
            ret = searchByTitle(next -> RChild, title);

        }else{

            ret = NULL;

        }

    }else if(result > 0){

        if(next -> LChild != NULL){
        
            ret = searchByTitle(next -> LChild, title);

        }else{

            ret = NULL;

        }

    }

    return ret;

}

/*searches for a title based on its tconst value*/
char *searchByTconst(struct title_node *next, char *tConst){

    int result = strcmp(next -> key, tConst);
    char *ret;

    if(result == 0){

        ret = next -> data -> primaryTitle;

    }else if(result < 0){

        if(next -> RChild != NULL){

            ret = searchByTconst(next -> RChild, tConst);

        }else{

            ret = NULL;

        }

    }else if(result > 0){

        if(next -> LChild != NULL){
        
            ret = searchByTconst(next -> LChild, tConst);

        }else{

            ret = NULL;

        }

    }

    return ret;

}

/*searches for the characters of a movie based on the tconst value*/
struct principal_node *searchByPrincipalTconst(struct principal_node *next, char *principalTconst){

    int result = strcmp(next -> key, principalTconst);
    struct principal_node *ret;

    if(result == 0){

        ret = next;

    }else if(result < 0){

        if(next -> RChild != NULL){

            ret = searchByPrincipalTconst(next -> RChild, principalTconst);

        }else{

            ret = NULL;

        }

    }else if(result > 0){

        if(next -> LChild != NULL){
        
            ret = searchByPrincipalTconst(next -> LChild, principalTconst);

        }else{

            ret = NULL;

        }

    }

    return ret;

}

/*searches for characters based on the nconst value*/
struct principal_node *searchByPrincipalNconst(struct principal_node *next, char *principalNconst){

    int result = strcmp(next -> key, principalNconst);
    struct principal_node *ret;

    if(result == 0){

        ret = next;

    }else if(result < 0){

        if(next -> RChild != NULL){

            ret = searchByPrincipalNconst(next -> RChild, principalNconst);

        }else{

            ret = NULL;

        }

    }else if(result > 0){

        if(next -> LChild != NULL){
        
            ret = searchByPrincipalNconst(next -> LChild, principalNconst);

        }else{

            ret = NULL;

        }

    }

    return ret;

}


