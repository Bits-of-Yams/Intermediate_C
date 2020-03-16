//
//   Exercise 2-1
//

#include "common.h"

//  Find the largest value in a two dimensional array

int largest(int num[][COLS], int amount) 
{
     int large = num[0][0], i, j;
     
     for (i = 0; i < amount; i++) {
          for (j = 0; j < COLS; j++) {
               if (num[i][j] > large ) {
                    large = num[i][j];
               }
          }
     }
                    
     return(large);
}
