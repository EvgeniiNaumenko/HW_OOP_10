#pragma once
#include <iostream>
using namespace std;

#include "Node.h"

template<class L >
class List
{
	L* _head;
	L* _tail;
	int _nodeIn = 0;

public:
	List();
	List(L*);
	void addToHead(L*);					//■ AddToHead — додавання елемента до голови списку;
	void addToTail(L*);					//■ AddToTail — додавання елемента до хвоста списку;
	void deleteFromHead();				//■ DeleteFromHead — видалення елемента з голови списку;
	void deleteFromTail();				//■ DeleteFromTail — видалення елемента з хвоста списку;
	void deleteAll();					//■ DeleteAll — видалення всіх елементів;
	void show();						//■ Show — виведення всіх елементів списку на екран.
	void addToPosition(L*, int);		//вставлення елемента в задану позицію, 
	void deleteFromPosition(int);		// видалення елемента із заданої позиції,
	int findElement(int);				//  пошук заданого елемента(функція	повертає позицію знайденого елемента в разі успіху або	NULL в разі невдачі),
	void changeElement(int);			//  пошук і заміна заданого елемента (функція повертає кількість замінених елементів в разі	успіху або - 1 у випадку невдачі), 
	void reverse();						// перевертання списку.

};

template<class L>
inline List<L>::List() : _head(nullptr), _tail(nullptr) {}

template<class L>
inline List<L>::List(L* node) : _head(node), _tail(node) 
{
	_nodeIn++;
}

template<class L>
inline void List<L>::addToHead(L* node)
{
	if (_head != nullptr)
	{
		_head->_next = node;
		node->_last = _head;
		_head = node;
		_nodeIn++;
	}
	else
	{
		_head = node;
		_tail = node;
		_nodeIn++;
	}
}

template<class L>
inline void List<L>::addToTail(L* node)
{
	if (_head != nullptr)
	{
		node->_next = _tail;
		_tail->_last = node;
		_tail = node;
		_nodeIn++;
	}
	else
	{
		_head = node;
		_tail = node;
		_nodeIn++;
	}
}

template<class L>
inline void List<L>::deleteFromHead()
{
	if (_head!= nullptr)
	{
		L* node = _head;
		_head = _head->_last;
		_head->_next = nullptr;
		node->_last = nullptr;
		node->_next = nullptr;
		_nodeIn--;
	}
}

template<class L>
inline void List<L>::deleteFromTail()
{
	if (_tail != nullptr)
	{
		L* node = _tail;
		_tail = _tail->_next;
		_tail->_last = nullptr;
		node->_next = nullptr;
		node->_last = nullptr;
		_nodeIn--;
	}
}

template<class L>
inline void List<L>::deleteAll()
{
	_tail = nullptr;
	_head = nullptr;
	_nodeIn = 0;
}

template<class L>
inline void List<L>::show()
{
	if (_tail != nullptr)
	{
		L* node = _tail;
		int count = 1;
		do
		{
			cout << "Pos: " << count << endl;
			node->print();
			node = node->_next;
			count++;
		} while (node != nullptr);
	}
	else
		cout << "List is empty!" << endl;
}

template<class L>
inline void List<L>::addToPosition(L* node, int pos)
{
	if (pos == 1 )
	{
		addToTail(node);
	}
	else if (pos == _nodeIn)
	{
		addToHead(node);
	}
	else if (pos>1 && pos<_nodeIn)
	{
		int count = 1;
		L* newNode = _tail;
		while (newNode != nullptr && pos != count)
		{
			newNode = newNode->_next;
			count++;
		}
		node->_next = newNode;
		node->_last = newNode->_last;
		newNode->_last = node;
		newNode =node->_last;
		newNode->_next = node;
		_nodeIn++;
	}
}

template<class L>
inline void List<L>::deleteFromPosition(int pos)
{
	if (pos == 1)
	{
		deleteFromTail();
	}
	else if (pos == _nodeIn)
	{
		deleteFromHead();
	}
	else if (pos > 1 && pos < _nodeIn)
	{
		int count = 1;
		L* newNode1 = _tail;
		while (newNode1 != nullptr && pos != count)
		{
			newNode1 = newNode1->_next;
			count++;
		}
		L* newNode2 = newNode1->_next;
		newNode2->_last = newNode1->_last;
		newNode1->_next = nullptr;
		newNode1->_last = nullptr;
		newNode1 = newNode2->_last;
		newNode1->_next = newNode2;
		_nodeIn--;
	}
}

template<class L>
inline int List<L>::findElement(int el)
{
	int count = 1;
	L* newNode = _tail;
	while (el != newNode->getNode())
	{
		newNode = newNode->_next;
		if (newNode == nullptr)
		{
			return NULL;
		}
		count++;
	}
	return count;
}

template<class L>
inline void List<L>::changeElement(int pos)
{
	if (pos>0 && pos<=_nodeIn)
	{
		int count = 1;
		L* newNode = _tail;
		while (newNode != nullptr && pos != count)
		{
			newNode = newNode->_next;
			count++;
		}
		newNode->setNode();
	}


}

template<class L>
inline void List<L>::reverse()
{
	L* newNode = _tail;
	_tail = _head;
	_head = newNode;
	while (newNode != nullptr)
	{
		L* temp = newNode->_next;
		newNode->_next = newNode->_last;
		newNode->_last = temp;
		newNode = temp;
	}
}
