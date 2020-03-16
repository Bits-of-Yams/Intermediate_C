//
//  Starter file for Exercise 9-1
//

#define NAMESIZE 20

struct passenger {
    char name[NAMESIZE];
    int f_number;
    struct passenger *link;
};

typedef struct passenger PASS, *PP;
typedef int BOOLEAN;

void initialize(PP *);   //   INITIALIZE THE LIST
BOOLEAN is_empty(PP);    //   IS THE LIST EMPTY?
PP insert(PP, PP);       //   ADD TO FRONT OF LIST
PP append(PP, PP);       //   ADD TO END OF LIST
PP create(char *, int);  //   CREATE AND FILL ELEMENT
void print(PP);          //   PRINT THE LIST
