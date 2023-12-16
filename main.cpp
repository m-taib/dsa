#include "linked_list.hpp"

int	main()
{
	LinkedList list(13);
	
	list.append(10);
	//list.preappend(3);
	//list.printList();
	//list.reverse();
	
	list.printList();
	list.deleteLast();
	list.printList();
	return (0);
}
