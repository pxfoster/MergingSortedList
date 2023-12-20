#include "ListManager.h"

ListManager::ListManager()
	: head(nullptr)
{
}

ListManager::~ListManager()
{
	if (head)
	{
		Node* nextNode = head->next;

		while (head)
		{
			delete head;
			head = nextNode;

			if (head)
				nextNode = head->next;
		}

		head = nullptr;
	}
}

void ListManager::addNode(int num)
{
	if (!head)
	{
		head = new Node(num);
	}
	else
	{
		Node* currNode = head;

		while (currNode->next)
		{
			currNode = currNode->next;
		}

		currNode->next = new Node(num);
	}
}

void ListManager::addSorted(int num)
{
	if (!head)
		head = new Node(num);
	else
		addSorted(num, head, nullptr);
}

const Node* ListManager::getList() const
{
	return head;
}

void ListManager::addSorted(int num, Node* currNode, Node* prevNode)
{
	if (num < currNode->num)
	{
		Node* tempNode = currNode;
		currNode = new Node(num);
		currNode->next = tempNode;

		if (head == tempNode)
			head = currNode;
		else
			prevNode->next = currNode;
	}
	else if (!currNode->next)
	{
		currNode->next = new Node(num);
	}
	else
		addSorted(num, currNode->next, currNode);
}
