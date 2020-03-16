//
//  orderedmain.c
//
#include "ordered.h"

int main()
{
	int i;
	PP list, node;
    
	initialize(&list);
    
 	node = create("mike", 100);
	list = order(node, list);
    
	node = create("zeke", 100);
	list = order(node, list);
    
	node = create("allen", 100);
	list = order(node, list);
    
	node = create("mikey", 100);
	list = order(node, list);
    
	print(list);
}
