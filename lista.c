#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char *str;
    int length;
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

    if (str == NULL) {
    return NULL;
    }

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

int deleteLast(Lines *list) {

    Node *aux;

    if (list == NULL || (*list).last == NULL) {
        return 1;
    }

    aux = (*list).last;

    (*list).last = (*aux).prev;

    if ((*list).last != NULL) {

        (*(*list).last).next = NULL;

    }
    else {

        (*list).first = NULL;

    }

    free((*aux).str);
    free(aux);

    (*list).total--;

    return 0;
}

int order_insert(Lines *list, const char *str, const int limit) {

    Node *node;
    Node *aux;
    int length;

    if (list == NULL || str == NULL) {
        return 1;
    }

     length = strlen(str);


    if ((*list).total >= limit) {

        if (length <= (*(*list).last).length) {
            return 0;
        }
    }

        if ((*list).total >= limit) {
        deleteLast(list);
    }

    node = newNode(str);
    aux=(*list).first;

    if (node == NULL) {
        return 1;
    }

   while (aux != NULL && length < (*aux).length)
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
    return 0;
}

int insert(Lines *list, const char *str) {

    Node *node;

    if (list == NULL || str == NULL) {
        return 1;
    }

    node = newNode(str);

    if (node == NULL) {
        return 1;
    }

    (*node).prev = (*list).last;

    if ((*list).last != NULL) {

        (*(*list).last).next = node;

    }
    else {

        (*list).first = node;

    }

    (*list).last = node;

    (*list).total++;

    return 0;
}



void deleteLines(Lines *list) {

    Node *aux;

    if (list == NULL) {
        return;
    }

    while ((*list).first != NULL) {

        aux = (*list).first;

        (*list).first = (*(*list).first).next;

        free((*aux).str);

        free(aux);

    }

    (*list).last = NULL;
    (*list).total = 0;

    free(list);
}

int deleteFirst(Lines *list) {

    Node *aux;

    if (list == NULL || (*list).first == NULL) {
        return 1;
    }

    aux = (*list).first;
    (*list).first = (*aux).next;

    if ((*list).first != NULL) {
        (*(*list).first).prev = NULL;
    }
    else {
        (*list).last = NULL;
    }

    free((*aux).str);
    free(aux);

    (*list).total--;

    return 0;
}

int printLines(Lines *list) {

    Node *aux;

    if (list == NULL) {
        return 1;
    }

    aux = (*list).first;

    while (aux != NULL) {
        printf("%s", (*aux).str);
        aux = (*aux).next;
    }
    return 0;
}