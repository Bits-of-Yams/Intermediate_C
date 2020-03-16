//
//  twowaymain.c
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

#include "twoway.h"

int main()
{
    int i;
    PP begin, end, node, list;
    
    begin = (PP) malloc(sizeof(PASS));
    end = (PP) malloc(sizeof(PASS));
    if(begin == NULL || end == NULL) {
        printf("malloc: no room\n");
        exit(1);
    }

    strcpy(begin -> name, "\0");
    strcpy(end -> name, "z");

    begin -> link = end;
    end -> link = NULL;

    begin -> f_number = 100;
    end -> f_number = 200;

    end -> blink = begin;
    begin -> blink = NULL;

    node = create("mike", 100);
    begin = order(node, begin);
    
    node = create("warren", 100);
    begin = order(node, begin);
    
    node = create("allen", 100);
    begin = order(node, begin);
    
    node = create("alice", 100);
    begin = order(node, begin);
    
    node = create("joe", 100);
    begin = order(node, begin);
    
    fprint(begin -> link);
    bprint(end -> blink);
}

