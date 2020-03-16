//
//   Exercise 2-1
//

#include <stdio.h>
#include "common.h"

int main()                        
{
     int numbers[ROW][COLS], i, answer;
     
     for (i = 0; i < ROW; i++) {
          printf("Entering for Row %d ", i + 1);
          fill(numbers[i], COLS);
          display(numbers[i], COLS);
     }
     
     answer = largest(numbers, ROW);
     printf("Largest is %d\n", answer);
}

