#include <stdio.h>
#include <string.h>
#include <malloc.h>

#include "twoway.h"

void fprint(PP p)
{
    printf("FORWARD\n");
    while (p -> link != NULL) {
        printf("%s %d\n", p -> name, p -> f_number);
        p = p -> link;
    }
}

void bprint(PP p)
{
    printf("BACKWARD\n");
    while (p -> blink != NULL) {
        printf("%s %d\n", p -> name, p -> f_number);
        p = p -> blink;
    }
}

PP create(char *name, int number)
{
    PP p;
    p = (PP) malloc(sizeof(PASS));
    if( p == NULL ){
         printf("malloc: no more room\n");
         return(NULL);
    }
    p -> f_number = number;
    strcpy(p -> name, name);
    p -> link = NULL;
    p -> blink = NULL;
    return(p);
}

PP order(PP data, PP p)
{
    PP prev;
    PP save = p;
    while(strcmp(data -> name, p -> name) >= 0)  {
        prev = p;
        p = p -> link;
    }
    data -> link =  prev -> link;
    prev -> link = data;
    data -> blink = p -> blink;
    p -> blink = data;
    return(save);
}

