#define NAMESIZE 20

struct passenger {
	char name[NAMESIZE];
	int f_number;
	struct passenger *link;
	struct passenger *blink;
};

typedef struct passenger PASS, *PP;
typedef int BOOLEAN;

BOOLEAN is_empty(PP);    //   IS THE LIST EMPTY?
PP order(PP, PP);        //   ADD IN ORDER
PP create(char *, int);  //   CREATE AND FILL ELEMENT
void fprint(PP);         //   PRINT THE LIST FORWARD
void bprint(PP);         //   PRINT THE LIST BACKWARD

