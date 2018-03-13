#include "stdafx.h"
#include "Node_DoublyLinkedList.h"


Node_DoublyLinkedList::Node_DoublyLinkedList(int _data): Node(_data)
{
	prev = nullptr;
	next = nullptr;
}


Node_DoublyLinkedList::~Node_DoublyLinkedList()
{
}
