﻿#include "stdafx.h"
#include "DoublyLinkedList.h"


void DoublyLinkedList::addStart(int data_to_add)
{
	Node_DoublyLinkedList * newElement = new Node_DoublyLinkedList(data_to_add);

	if (head_list==nullptr)
	{
		head_list = newElement;
		return;
	}

	head_list->prev = newElement;
	newElement->next = head_list;
	head_list = newElement;
}

void DoublyLinkedList::addEnd(int data_to_add)
{
	Node_DoublyLinkedList * newElement = new Node_DoublyLinkedList(data_to_add);

	if (head_list == nullptr)
	{
		head_list = newElement;
		return;
	}

	Node_DoublyLinkedList * tmp = head_list;

	while (tmp->next!=nullptr)
	{
		tmp = tmp->next;
	}

	tmp->next = newElement;
	newElement->prev = tmp;
}


void DoublyLinkedList::addAtPos(int data_to_add, int pos)
{
	Node_DoublyLinkedList * newElement = new Node_DoublyLinkedList(data_to_add);

	//jeśli lista pusta to dodaj element
	if (head_list == nullptr)
	{
		head_list = newElement;
		return;
	}

	if (pos <= 0)
	{
		addStart(data_to_add);
		return;
	}

	Node_DoublyLinkedList * tmp = head_list;

	while (tmp->next!=nullptr)
	{
		if (pos == 0)
		{
			newElement->prev = tmp->prev;
			tmp->prev->next = newElement;
			newElement->next = tmp;
			tmp->prev = newElement;
			return;
		}
		tmp = tmp->next;
		pos--;
	}

	//Jeśli index za duży, to dodaj na koniec
	tmp->next = newElement;
	newElement->prev = tmp;
}

void DoublyLinkedList::rmStart()
{
	//jeśli lista pusta to nic nie rób
	if (head_list==nullptr)
	{
		return;
	}

	head_list = head_list->next;
	delete head_list->prev;
}

void DoublyLinkedList::rmEnd()
{
	//jeśli lista pusta to nic nie rób
	if (head_list == nullptr)
	{
		return;
	}

	Node_DoublyLinkedList * tmp = head_list;

	//zmajdź ostatni element
	while (tmp->next != nullptr)
	{
		tmp = tmp->next;
	}

	tmp->prev->next = nullptr;
	delete tmp;
}


void DoublyLinkedList::rmAtPos(int pos)
{
	//jeśli lista pusta to nic nie rób
	if (head_list == nullptr)
	{
		return;
	}

	// jeśli index mniejszy od 0 to usuń 1 element
	if (pos <= 0)
	{
		rmStart();
		return;
	}

	Node_DoublyLinkedList * tmp = head_list;

	//znajdź element i sprawdzaj czy jeszcze istnieje następny, a potem go usuń
	while (tmp->next != nullptr)
	{
		if (pos == 0)
		{
			tmp->prev->next = tmp->next;
			tmp->next->prev = tmp->prev;
			delete tmp;
			return;
		}
		tmp = tmp->next;
		pos--;
	}

	//Jeśli index za duży, to usuń końcowy
	tmp->prev->next = nullptr;
	delete tmp;
}

void DoublyLinkedList::display()
{
	std::cout << "Elementy listy dwustronnej: "<< std::endl;

	Node_DoublyLinkedList * tmp = head_list;

	while (tmp!=nullptr)
	{
		std::cout << tmp->data<<std::endl;
		tmp = tmp->next;
	}
}

int DoublyLinkedList::count()
{
	int i=0;
	Node_DoublyLinkedList * tmp = head_list;
	while (tmp != nullptr)
	{
		i++;
		tmp = tmp->next;
	}
	return i;
}

void DoublyLinkedList::countAndDisplay()
{
	int i = 0;
	Node_DoublyLinkedList * tmp = head_list;
	while (tmp != nullptr)
	{
		i++;
		tmp = tmp->next;
	}
	std::cout<< "Liczba elementów: " << i << std::endl;
}

DoublyLinkedList::~DoublyLinkedList()
{
}

DoublyLinkedList::DoublyLinkedList()
{
}



/*void DoublyLinkedList::addAfter(int data_to_add, int after_value)
{
	Node_DoublyLinkedList * newElement = new Node_DoublyLinkedList(data_to_add);

	//jeśli lista pusta to dodaj element
	if (head_list == nullptr)
	{
		head_list = newElement;
		return;
	}

	Node_DoublyLinkedList * tmp = head_list;

	//literacja i szukanie elementu po której wartości dodać i dodanie
	while (tmp->next != nullptr)
	{
		if (tmp->data == after_value)
		{
			newElement->prev = tmp;
			newElement->next = tmp->next;
			tmp->next = newElement;

			//jeśli po tmp nie ma nic wtedy nie ustawiamy w następnym elemencie wskaźnika prev
			if (newElement->next != nullptr)
			{
				newElement->next->prev = newElement;
			}
			return;
		}
		tmp = tmp->next;
	}

	//Jeśli nie ma tej liczby, to dodaj na koniec
	tmp->next = newElement;
	newElement->prev = tmp;
}*/