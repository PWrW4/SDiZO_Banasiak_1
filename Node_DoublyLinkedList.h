#pragma once
#include "Node.h"
class Node_DoublyLinkedList :
	public Node
{
public:
	Node_DoublyLinkedList * next;
	Node_DoublyLinkedList * prev;


	Node_DoublyLinkedList(int _data);
	~Node_DoublyLinkedList();
};

