#include "main.h"
#include <random>

int main()
{
	std::srand(time(NULL));

	ListManager manager1;
	ListManager manager2;
	ListManager merged;

	// Set up the lists
	addRandomNums(manager1);
	addRandomNums(manager2);

	// Display the separate lists
	std::cout << "List 1:" << std::endl;
	displayList(manager1.getList());
	std::cout << std::endl << "List 2:" << std::endl;
	displayList(manager2.getList());

	// Merging the two lists and displaying the result
	mergeLists(manager1.getList(), manager2.getList(), merged);
	std::cout << std::endl << "Merged List:" << std::endl;
	displayList(merged.getList());

	return 0;
}

void addRandomNums(ListManager& listManager)
{
	int listSize = (std::rand() % 5) + 5;
	
	for (int i = 0; i < listSize; i++)
	{
		listManager.addSorted(std::rand() % 50);
	}
}

void displayList(const Node* list)
{
	while (list)
	{
		std::cout << list->num << " ";
		list = list->next;
	}
	std::cout << std::endl;
}

void mergeLists(const Node* list1, const Node* list2, ListManager& mergedList)
{
	while (list1 || list2)
	{
		if (list1 && !list2)
		{
			mergedList.addNode(list1->num);
			list1 = list1->next;
		}
		else if ((list1 && list2) && (list1->num < list2->num))
		{
			mergedList.addNode(list1->num);
			list1 = list1->next;
		}
		else if (list2)
		{
			mergedList.addNode(list2->num);
			list2 = list2->next;
		}
	}
}
