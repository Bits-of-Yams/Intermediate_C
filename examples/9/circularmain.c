//
//  circularmain.c
//
#include <stdio.h>
#include <malloc.h>

#include "list.h"

#define NUMBER  22

int main()
{
    char map[NUMBER + 1];
    int i, count;
    PP list, node, p, prev, save;
    initialize(&list);

    for ( i = 0; i < NUMBER; i++) {
        node = create("tom",i);
        list = append(node,list);
        map[i] = 'X';
    }
    map[NUMBER] = '\0';
    
    p = list;
    for (i = 0; i < NUMBER - 1; i++)
        p = p -> link;
        
    p -> link = list;
    p = list;
    
    for (count = 0; count < NUMBER - 1; count++) {
        for(i = 0; i < 2; i++) {
            prev = p;
            p = p -> link;
        }
        save = p;
        prev -> link = p -> link;

        map[p -> f_number] = '_';
        printf("%s\n",map);
        free(p);
        p = prev -> link;
    }
}


