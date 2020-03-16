//
//  Starter file for Exercise 8-3
//

#define SIZE 100

struct set {
	int array[SIZE];
	int howmany;
};

typedef struct set SET, *SETP;

SETP create(void);
void add(int, SETP);
void print(SETP);
SETP setunion(SETP, SETP);
SETP setintersection(SETP, SETP);
int ismember( int element, SETP p);

