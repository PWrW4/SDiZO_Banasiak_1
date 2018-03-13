#pragma once
#include "Node_DoublyLinkedList.h"

class DoublyLinkedList
{
public:
	Node_DoublyLinkedList * head_list;



	void addStart(int data_to_add);
	void addEnd(int data_to_add);
	void addAfter(int data_to_add, int after_value);
	void addAtPos(int data_to_add, int _pos);

	void rmStart();
	void rmEnd();
	void rmAfter();
	void rmAtPos();

	void display();

	int count();
	void countAndDisplay();

	DoublyLinkedList();
	~DoublyLinkedList();


};
