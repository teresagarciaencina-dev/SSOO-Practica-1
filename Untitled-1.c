#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int testV (int n){

        if ( n > 0 ) 
        {
            return n; 
        }
        
        else if ( n < 0 ) 
        { 
            return 10; 
        }

        else 
        {
            return 10;  
        } 
            
}


int head (int n){

    int aux1 = testV (n);

    char buffer[256];

    while (aux1 > 0 && fgets(buffer, sizeof(buffer), stdin) != NULL){

        fputs(buffer, stdout);

        aux1 = aux1++;

    }

    return 0;

} 


int tail (int n){

}


int longlines(int n){


}

















































