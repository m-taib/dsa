#pragma once

#include <iostream>

class Node
{
	public :
		Node(int value);
		int	_value;
		Node 	*_next;
	private :
		Node();
};

class LinkedList
{
	public :
		LinkedList(int value);
		~LinkedList();

		int	getLength();
		void	append(int value);
		void	preappend(int value);
		void	printList();
		void	printHead();
		void	printTail();
		void	deleteLast();
		void	deleteFirst();
		Node*   getNode(int index);
		bool    set(int index, int value);
		bool    insert(int index, int value);
		void    deleteNode(int index);
		void 	reverse();
	private :
		Node* 	_head;
		Node* 	_tail;
		int 	_length;

		LinkedList();
};
