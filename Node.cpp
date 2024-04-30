#include "Node.h"

Node::Node():Node(0){}

Node::Node(int num)
{
	_node = num;
	_next = nullptr;
	_last = nullptr;
}

void Node::operator=(int num)
{
	_node = num;
}

void Node::print()
{
	cout << _node << endl;
}

int Node::getNode()
{
	return _node;
}

void Node::setNode()
{
	cout << "Enter node! " << endl;
	cin >> _node;

}
