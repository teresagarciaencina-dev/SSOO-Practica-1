#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cola.h"

Tail_Lines *newLine(int aux1) {
    Tail_Lines *tail;
    int aux2;

    if (aux1 <= 0) {
        return NULL;
    }

    tail = malloc(sizeof(Tail_Lines));
    if (tail == NULL) {
        return NULL;
    }

    tail->size = aux1; 
    tail->indx = 0;
    tail->total = 0;
    tail->node = malloc(aux1 * sizeof(char *));

    if (tail->node == NULL) {
        free(tail);
        return NULL;
    }

    for (aux2 = 0; aux2 < aux1; aux2++) {
        tail->node[aux2] = NULL;
    }

    return tail;
}

void insert(Tail_Lines *tail, const char *aux1) {

    if (tail == NULL ) { 

        return;
    }

    if else (aux1 == NULL){

        return;

    }

    int aux2;


    aux2 = tail->indx;

    if (tail->node[aux2] != NULL) {

        free(tail->node[aux2]);

    }

    tail->node[aux2] = malloc((strlen(aux1) + 1) * sizeof(char));
    if (tail->node[aux2] != NULL) {
        strcpy(tail->node[aux2], aux1);
    }

    tail->indx = (tail->indx + 1) % tail->size;
    tail->total++;
}

bool is_empty(Tail_Lines *tail){

    if (tail == NULL) {
        return true;
    }
    else {
        return false;
    }
}

void delete(Tail_Lines *tail) {

    int aux1;

    if (tail == NULL || is_empty(tail)) { 
        return;
    }

    for (aux1 = 0; aux1 < tail->size; aux1++) {
        if (tail->node[aux1] != NULL) {
            free(tail->node[aux1]);
        }
    }

    free(tail->node);
    free(tail);
}

void print(Tail_Lines *tail) {

    int aux1;
    int first;
    int total1;
    int indx1;

    if (tail == NULL || is_empty(tail)) {
        return;
    }

   
    if (tail->total < tail->size) {
        
        total1 = tail->total;
        first = 0;
    } else {
        
        total1 = tail->size;
        first = tail->indx;
    }

    for (aux1 = 0; aux1 < total1; aux1++) {
        indx1 = (first + aux1) % tail->size;
        if (tail->node[indx1] != NULL) {
            fputs(tail->node[indx1], stdout);
        }
    }
}

