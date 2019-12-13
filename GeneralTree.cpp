#include "GeneralTree.h"
#include<string>
using namespace std;

Node::Node(string value, Node* parent)
{
	this->Value = value;
	this->Parent = parent;
}

Node::Node(string value)
{
	this->Value = value;
	this->Parent = nullptr;
}

void GeneralTree::AddChild(string value,string parenttext)
{
	Node* parent = Find(parenttext);
	if (parent == nullptr)
		AddParent(parenttext);
	parent = Find(parenttext);
	parent->Childs.push_back(new Node(value,parent));
}

void GeneralTree::AddParent(string value)
{
	
	Node* parent = Find(value);
	if (parent == nullptr)

	{		
		parent = new Node(value);
		Nodes.push_back(parent);
	}
	
}

Node* GeneralTree::Find(std::string value)
{
	for (auto n : Nodes)
	{
		if (n->Value == value)
			return n;
		auto child = SearchChilds(value,n);
		if (child!= nullptr)
			return child;
	}
	return nullptr;
}
Node* GeneralTree::SearchChilds(string value,Node* node)
{
	if (node->Childs.empty())
		return nullptr;
	Node* result = nullptr;
	for (auto child : node->Childs)
	{
		if (child->Value == value)
		{
			result = child;
			break;
		}
	}
	if (result == nullptr)
	{
		for (auto child : node->Childs)
		{
			result = SearchChilds(value,child);
			if (result != nullptr)
				break;
		}
	}
	return result;
		
}
GeneralTree::GeneralTree()
{
}


GeneralTree::~GeneralTree()
{
}
