#pragma once

#include <iostream>
#include "ListManager.h"

void addRandomNums(ListManager& listManager);
void displayList(const Node* list);
void mergeLists(const Node* list1, const Node* list2, ListManager& mergedList);
