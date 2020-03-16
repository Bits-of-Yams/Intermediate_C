//
//   Exercise 2-1
//
//

#include <stdio.h>
#include "common.h"

//  Display the values in one row

void display(int num[], int howmany) 
{
     int i;
     
     for (i = 0; i < howmany; i++) {
          printf("%4d ", num[i]);
     }
     putchar('\n');
}

