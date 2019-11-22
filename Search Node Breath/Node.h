#pragma once
#include <string>
#include <vector>
using namespace std;
class Node
{
public:
	Node();
	virtual ~Node();

	vector<shared_ptr<Node>> getChildren();
	shared_ptr<Node> addChild(string n);

	string getName();
	void setName(string n);

private:
	vector<shared_ptr<Node>> children;

	string name;
};

