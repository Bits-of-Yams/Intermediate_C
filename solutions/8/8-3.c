//
//  Exercise 8-3
//
#include <stdlib.h>

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
int ismember(int element, SETP p);

SETP setintersection(SETP a, SETP b)
{
	SETP c;
	SETP pt;
	int i;

	c = create();
    
	if (a -> howmany  <  b -> howmany) {
		for (i = 0; i < a -> howmany; i++) {
			if (ismember( a -> array[i], b)) {
				add(a -> array[i], c);
            }
        }
	} else {
		for (i = 0; i < b -> howmany; i++) {
			if (ismember( b -> array[i], a)) {
				add(b -> array[i], c);
            }
        }
	}
    
	return(c);
}

int ismember( int element, SETP p)
{
	int i;

	for (i = 0; i < p -> howmany; i++) {
		if (p -> array[i] == element) {
			return(1);
        }
    }
    
	return(0);
}
