#pragma once
#include "Node.h"

class DoublyLinkedList : Node
{
public:
	DoublyLinkedList * next;
	DoublyLinkedList * prev;



	void add_start(DoublyLinkedList ** head,int data_to_add);
	void add_end(DoublyLinkedList * head, int data_to_add);
	void add_after(DoublyLinkedList * head, int data_to_add, int after_pos);

	void display();
	int count();

	DoublyLinkedList(int _data);


};
