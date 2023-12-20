#pragma once

struct Node
{
	Node(int num)
	{
		this->num = num;
		next = nullptr;
	}
	int num;
	Node* next;
};

class ListManager
{
public:
	ListManager();
	~ListManager();

	void addNode(int num);
	void addSorted(int num);
	const Node* getList() const;

private:
	void addSorted(int num, Node* currNode, Node* prevNode);

	Node* head;
};