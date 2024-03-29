#include <string>
#include <iostream>
#include<vector>
#include "Node.h"
using namespace std;

shared_ptr<Node> findNode(shared_ptr<Node> node, string nodeName)
{
	cout << "Visited: " << node->getName() << endl;
	if (node->getName() == nodeName) {
		return node;
	}

	vector<shared_ptr<Node>>::iterator it;

	vector<shared_ptr<Node>> currentNode = node->getChildren();
	if (currentNode.empty()) {
		return nullptr;
	}

	for (it = currentNode.begin(); it != currentNode.end(); it++) {
		shared_ptr<Node> result = findNode(*it, nodeName);
		if (result != nullptr) {
			return result;
		}
	}
	return nullptr;
}


int main() {
	//Build Tree
	shared_ptr<Node> root(new Node());

	root->setName("Start");

	shared_ptr<Node> currentNode = root->addChild("A1");

	currentNode->addChild("D1")->addChild("E1");

	currentNode = currentNode->addChild("A2");

	currentNode->addChild("B1")->addChild("Find Me");

	currentNode->addChild("B2")->addChild("C1");

	shared_ptr<Node> result = findNode(root, "Find Me");

	if (result != nullptr) {
		cout << "Found node: " << result->getName() << endl;
	}
	else {
		cout << "Node not found" << endl;
	}


	cin.get();
	cin.get();
}
