//
//  listmain.c
//
#include "list.h"

int main()
{
	PP list, node;
    
	initialize(&list);
    
	node = create("mike", 100);
	list = insert(node, list);
	node = create("tom", 1);
	list = append(node, list);
    
	if(! is_empty(list)) {
		print(list);
    }
}


