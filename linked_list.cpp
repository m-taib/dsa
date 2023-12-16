#include "linked_list.hpp"

Node::Node(int value)
{
	_value = value;
	_next = NULL;
}

LinkedList::LinkedList(int value)
{
	_head = new Node(value);
	_tail = _head;
	_length = 1;	
}

int	LinkedList::getLength()
{
	return (_length);
}

void    LinkedList::append(int value)
{
	_tail->_next = new Node(value);
	_tail = _tail->_next;
	_length++;	
}

void    LinkedList::printHead()
{
	std::cout << _head->_value << std::endl;
}

void    LinkedList::printTail()
{
	std::cout << _tail->_value << std::endl;
}

void	LinkedList::printList()
{
	Node *tmp;

	tmp = _head;

	while (tmp)
	{
		std::cout << tmp->_value << std::endl;
		tmp = tmp->_next;
	}

}

void    LinkedList::deleteLast()
{
	Node *tmp;
	
	if (!_length)
		return ;
	tmp = _head;
	while (tmp->_next)
	{
		_tail = tmp;
		tmp = tmp->_next;
	}
	_tail->_next = NULL;
	delete tmp;
	_length--;
}

void    LinkedList::deleteFirst()
{
	Node *tmp;

	tmp = _head;
	_head = _head->_next;
	delete tmp;
	_length--;
}

void	LinkedList::preappend(int value)
{
	Node *tmp;

	tmp = new Node(value);
	tmp->_next = _head;
	_head = tmp;
}

Node*	LinkedList::getNode(int index)
{
	int	i;
	Node	*tmp;

	i = 0;
	if (index < 0 || index >= _length)
	{
		std::cout << "Invalid index" << std::endl;
		return NULL;
	}
	tmp = _head;
	while (i < index)
	{
		tmp = tmp->_next;
		i++;
	}	
	return tmp;
}

bool	LinkedList::set(int index, int value)
{
	Node*	tmp;

	tmp = getNode(index);
	if (tmp)
	{
		tmp->_value = value;
		return (true);
	}
	return (false);
}

bool	LinkedList::insert(int index, int value)
{
	Node *tmp;
	Node *newnode;
	
	if (index == 0)
		preappend(value);
	else if (index == _length)
		append(value);
	else
	{
		tmp = getNode(index - 1);
		newnode = new Node(value);
		newnode = tmp->_next;
		tmp->_next = newnode;
	}
	return (true);
}

void	LinkedList::deleteNode(int index)
{
	Node	*tmp;

	if (index == 0)
		deleteFirst();
	else if (index == _length - 1)
		deleteLast();
	else
	{
		tmp = getNode(index - 1);
		tmp->_next = tmp->_next->_next;
		tmp = tmp->_next;
		delete tmp;
		_length--;	
	}

}

void	LinkedList::reverse()
{
	Node *tmp;
	Node *after;
	Node *before;
	
	tmp = _head;
	_tail = _head;
	before = NULL;
	while (tmp)
	{
		after = tmp->_next;
		tmp->_next = before;
		before = tmp;
		tmp = after;
	}
	_head = before;
}

LinkedList::~LinkedList()
{
	Node *tmp;

	while (_head)
	{
		tmp = _head;
		_head = _head->_next;
		delete tmp;
	}
}
