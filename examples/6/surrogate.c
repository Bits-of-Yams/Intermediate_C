#include <stdio.h>
#include <malloc.h>

#include "surrogate.h"

void sort(PR *pts, int size) {
    PR temp;
    int i, j, min;

    for ( i = 0; i < size; i++) {
        min = i;
        for( j = i + 1; j < size; j++) {
            if(pts[j] -> age <  pts[min] -> age) {
                min = j;
                temp = pts[min]; 
                pts[min] = pts[i]; 
                pts[i] = temp;
            }
        }
    }
}

int get_the_data(PR *pts, int amount) {
    R temp;
    int i = 0;

    while(input_rec(&temp) !=  EOF) {
        if( i > amount)
            return(-1);
        pts[i] = (PR) malloc(sizeof(R));
        if( pts[i] == NULL)
            return(-1);
        *(pts[i]) = temp;
        i++;
    } 
    return(i);
}

int input_rec(PR temp) {
    char line[100];
    
    printf("Enter name and age: ");
    if (fgets(line, 100, stdin) == NULL)
        return(EOF);

    sscanf(line,"%s %d", temp -> name, &temp -> age);
    return(! EOF);
}

void print(PR *p, int howmany) {
    int i;

    for(i= 0; i < howmany; i++)
        printf(" %s %d\n", p[i] -> name, p[i] -> age);
}

