#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

    char line[256];

    while (aux1 > 0 && fgets(line, sizeof(line), stdin) != NULL){

        fputs(line, stdout);

        aux1 = aux1++;

    }

    return 0;

} 


int tail (int n){

     int aux1 = testV (n);

     char line[256];

     Tail_Lines *tail = newLine(aux1);

    while (fgets(line, sizeof(line), stdin) != NULL){

       insert(tail, line);

    }

    print(tail);

    delete(tail);

    return 0;

}


int longlines(int n){


}

















































