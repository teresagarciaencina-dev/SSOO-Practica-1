#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"
#define SIZE_BUFFER 1024



int testV (int n){

        if ( n > 0 ) 
        {
            return n; 
        }

        else 
        {
            return 10;  
        } 
            
}


int head (int n){

    int aux1 = testV (n);

    char line[SIZE_BUFFER];

    while (aux1 > 0 && fgets(line, sizeof(line), stdin) != NULL){

        fputs(line, stdout);

        aux1--;

    }

    return 0;

} 


int tail(int n) {

    char line[SIZE_BUFFER];
    Lines *list;

     n = testV(n);

    if (n <= 0) {
        return 2;
    }

    list = newLines();

    if (list == NULL) {
        return 1;
    }

    while (fgets(line, sizeof(line), stdin) != NULL) {

        if (insert(list, line) != 0) {
            deleteLines(list);
            return 1;
        }

        if ((*list).total > n) {
            deleteFirst(list);
        }
    }

    printLines(list);

    deleteLines(list);

    return 0;
}


int longlines(int n){

    int valid_n = testV(n);


    Lines *list = newLines();
    if (list == NULL) {
        return -1;
    }

    char buffer[SIZE_BUFFER];

    while (fgets(buffer, sizeof(buffer), stdin) != NULL) {
        if (order_insert(list, buffer, valid_n) != 0) {
            deleteLines(list);
            return 1;
        }
    }

    printLines(list);

    deleteLines(list);

    return 0;

}

















































