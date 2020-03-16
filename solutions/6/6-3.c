//
//   Exercise 6-3
//
#include <stdio.h>
#include <string.h>

#define MAXLINE 100

char **lookup(char **argv, int argc, char *string);

int main(int argc, char **argv)
{
     char **hold, **pc;
     char line[MAXLINE];
     
     printf("Enter a string: ");
     fgets(line, MAXLINE, stdin);
     line[strlen(line) - 1] = '\0';		// Strip off the newline

     hold = argv;
     
     pc = lookup(argv, argc - 1, line);
     if (pc != NULL) {
         printf("'%s' was argument number %ld\n", line, pc - hold);
     } else {
         printf("'%s' was not an argument\n", line);
     }
}

char **lookup(char **argv, int argc, char *string)
{
     int i;
     
     for (i = 1; i <= argc ; i++) {
          if(strcmp(string,*++argv) == 0) {
              return(argv);
          }
     }
               
     return(NULL);
}
