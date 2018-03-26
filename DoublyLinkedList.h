#pragma once
#include "Node_DoublyLinkedList.h"

class DoublyLinkedList
{
public:
	Node_DoublyLinkedList * head_list;



	void addStart(int data_to_add);
	void addEnd(int data_to_add);
	void addAtPos(int data_to_add, int pos);

	void rmStart();
	void rmEnd();
	void rmAtPos(int pos);

	int searchRetunIndex(int data_to_find);
	void searchPrintPos(int data_to_find);
	Node_DoublyLinkedList * searchRetunPointer(int data_to_find);

	void display();
	void displayAtPos(int pos);

	int count();
	void countAndShow();

	DoublyLinkedList();
	~DoublyLinkedList();


};
