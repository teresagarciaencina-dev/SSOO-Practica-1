#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char *str;
    int *length;
    struct Node *next;
    struct Node *prev;
} Node;

typedef struct {
    Node *first;
    Node *last;
    int total;
} Lines;

Lines *newLines(void) {

    Lines *list = malloc(sizeof(Lines));

    if (list == NULL) {
        return NULL;
    }

    (*list).first = NULL;
    (*list).last=NULL;
    (*list).total = 0;


    return list;
}

Node *newNode(const char *str) {

    Node *node;

    node = malloc(sizeof(Node));

    if (node == NULL) {
        return NULL;
    }

    (*node).str = malloc(strlen(str) + 1);

    if ((*node).str == NULL) {
        free(node);
        return NULL;
    }

    strcpy((*node).str, str);

    (*node).length = strlen(str);

    (*node).next = NULL;
    (*node).prev = NULL;

    return node;
}

int order_insert(Lines *list, const char *str) {

    Node *node;
    Node *aux;

    if (list == NULL || str == NULL) {
        return 0;
    }

    node = newNode(str);
    aux=(*list).first;

    if (node == NULL) {
        return 0;
    }

   while (aux != NULL && strcmp(str, (*aux).str) > 0)
    {
      aux=(*aux).next;  
    }

    if (aux==NULL) {

        
        (*node).next=NULL;
        (*node).prev = (*list).last;
        
        
        if ((*list).last != NULL) {

                (*(*list).last).next = node;
            
            }
            else {

                (*list).first = node;
            }       
            (*list).last=node;
    }
    else if (aux==(*list).first){

        (*node).prev=NULL;
        (*node).next = aux;;
        (*list).first=node;
        (*aux).prev = node;

    }
    else 
    {
        (*node).next = aux;
        (*node).prev = (*aux).prev;
        (*(*aux).prev).next = node;
        (*aux).prev = node;
    }
    
    (*list).total++;
    return 1;
}