#include "Node.h"

Node::Node()
{
}


Node::~Node()
{
}

vector<shared_ptr<Node>> Node::getChildren()
{
	return children;
}

shared_ptr<Node> Node::addChild(string n)
{
	shared_ptr<Node> newNode(new Node());
	newNode->setName(n);
	children.push_back(newNode);
	return newNode;
}

string Node::getName()
{
	return name;
}

void Node::setName(string n)
{
	name = n;
}
