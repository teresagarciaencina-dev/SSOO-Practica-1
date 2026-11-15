#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libreria.h"

int main(int argc, char *argv[]) {

    int n = 10;

    if (argc < 2 || argc > 3) {
        fprintf(stderr, " %s -head|-tail|-longlines [N]\n", argv[0]);
        return 2;
    }

    if (argc == 3) {
        n = atoi(argv[2]);
        if (n <= 0) {
        fprintf(stderr, "entrada invalida\n");
        return 2;}
        
    }

    if (strcmp(argv[1], "-head") == 0) {
        return head(n);
    }

    if (strcmp(argv[1], "-tail") == 0) {
        return tail(n);
    }

    if (strcmp(argv[1], "-longlines") == 0) {
        return longlines(n);
    }

    fprintf(stderr, "Opción no válida\n");
    return 2;
}
