//
//   Exercise 2-1
//

#include <stdio.h>
#include <stdlib.h>
#include "common.h"

//  Get the values for one row

void fill(int num[], int howmany)  
{
     int i;
     char line[20];
     
     for(i = 0; i < howmany; i++)
     {
          printf("   Enter value for Column %d: ", i + 1);
          num[i] = atoi(fgets(line, 20, stdin));
     }
}


