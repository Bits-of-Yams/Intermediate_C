//
//   Exercise 2-2
//
//   NOTE:  This program is intended to be created
//          by compiling and linking two separate files
//          (2-2.c AND getandput.c) 
//

#include <stdio.h>

int  get_max_pos();
void put(int value, int position);
int  get(int position);

int main()
{
     int i, max_pos;

     max_pos = get_max_pos();
     
     for (i = 0; i <= max_pos; i++) {
          put(i, i);
     }
          
     for (i = 0; i <= max_pos; i++) {
          printf("%d ", get(i));
     }
     printf("\n");
}

