//
//   print-args.c
//

#include <stdio.h>

void printArgs(char **a);

int main(int argc, char **argv)
{
    printArgs(argv);
}

void printArgs(char **a)
{
    ++a;		//  Skip program name

    while(*a) {
        printf("%s\n",*a++);
    }
}
