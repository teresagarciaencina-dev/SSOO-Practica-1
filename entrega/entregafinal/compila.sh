#!/bin/bash

gcc -Wall -Wextra -c lista.c -o lista.o
gcc -Wall -Wextra -c libreria.c -o libreria.o

ar rcs liblibreria.a libreria.o lista.o

gcc -Wall -Wextra test.c -L. -llibreria -o test
