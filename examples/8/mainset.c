//
//  mainset.c
//
#include <malloc.h>

#include "set.h"

int main()
{
	SETP a, b, c;
    
	a = create();
	b = create();
    
	add(10, b);			// ADD ELEMENT 10 TO SET b
	add(5, b);
    
	add(5, a);			// ADD ELEMENT 5 TO SET a
	add(6, a);
    
	print(a);
	print(b);
    
	c = setunion(a,b);		// TAKE UNION OF a AND b
	print(c);

	free(a);
	free(b);
	free(c);
}
