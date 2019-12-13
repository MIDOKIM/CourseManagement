#pragma once
#include <vector>
using namespace std;
class Node
{
public:

	Node(string value,Node* parent);
	Node(string value);
	Node* Parent;
	string Value;
	vector<Node*> Childs;
};
class GeneralTree
{
	public:
	vector<Node*> Nodes;
	void AddChild(string value, string parent);
	void AddParent(string value);
	Node* Find(std::string value);
	Node* SearchChilds(string value, Node* node);
	GeneralTree();
	~GeneralTree();
};

