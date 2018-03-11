#include "stdafx.h"
#include "DoublyLinkedList.h"

 void DoublyLinkedList::add_start(DoublyLinkedList ** head, int data_to_add)
{
	DoublyLinkedList * temp = new DoublyLinkedList(data_to_add);
	temp->prev = this->prev;
	prev->next = this;
 	prev = temp;
	temp->next = this;
	* head = temp;
}

void DoublyLinkedList::add_end(DoublyLinkedList * head, int data_to_add)
{
}

void DoublyLinkedList::add_after(DoublyLinkedList * head, int data_to_add, int after_pos)
{
}

void DoublyLinkedList::display()
{
	DoublyLinkedList * nextElement = this;
	do
	{
		std::cout << nextElement->data<<std::endl;		
		nextElement = nextElement->next;
	} while (this != nextElement);
}

int DoublyLinkedList::count()
{
	int i = 0;
	DoublyLinkedList * nextElement = this;

	do
	{
		i++;
		nextElement = nextElement->next;
	} while (this == nextElement);

	return i;
}

DoublyLinkedList::DoublyLinkedList(int _data) : Node(_data), next(this), prev(this)
{
}

