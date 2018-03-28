#include "stdafx.h"
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

	if (count() == 1)
	{
		head_list = nullptr;
		return;
	}

	head_list = head_list->next;
	delete head_list->prev;

	if (count()==0)
	{
		head_list = nullptr;
	}
}

void DoublyLinkedList::rmEnd()
{
	//jeśli lista pusta to nic nie rób
	if (head_list == nullptr)
	{
		return;
	}

	if (count() == 1)
	{
		head_list = nullptr;
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

	//jesli zostal 1 element no to go usuwamy
	if (count() == 1)
	{
		head_list = nullptr;
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

int DoublyLinkedList::searchRetunIndex(int data_to_find)
{
	//jeśli lista pusta to nic nie rób
	if (head_list == nullptr)
	{
		return -1;
	}

	int pos = 0;
	Node_DoublyLinkedList * tmp = head_list;

	if (tmp->data == data_to_find)
	{
		return pos;
	}

	while (tmp->next != nullptr)
	{
		pos++;
		if (tmp->next->data == data_to_find)
		{
			return pos;
		}
		tmp = tmp->next;
	}



	return 999999999;
}

void DoublyLinkedList::searchPrintPos(int data_to_find)
{
	//jeśli lista pusta to nic nie rób
	if (head_list == nullptr)
	{
		std::cout << "Lista jest pusta"<<std::endl;
	}

	int pos = 0;
	Node_DoublyLinkedList * tmp = head_list;

	if (tmp->data == data_to_find)
	{
		std::cout << "Pozycja szukanej liczby " << pos << std::endl;
		return;
	}

	while (tmp->next != nullptr)
	{
		pos++;
		if (tmp->next->data == data_to_find)
		{
			std::cout << "Pozycja szukanej liczby " << pos << std::endl;
			return;
		}
		tmp = tmp->next;

	}
	
	std::cout << "Nie znalezione elementu w liscie."<<std::endl;
}

Node_DoublyLinkedList* DoublyLinkedList::searchRetunPointer(int data_to_find)
{
	//jeśli lista pusta to nic nie rób
	if (head_list == nullptr)
	{
		return nullptr;
	}

	int pos = 0;
	Node_DoublyLinkedList * tmp = head_list;

	if (tmp->data == data_to_find)
	{
		return tmp;
	}

	while (tmp->next != nullptr)
	{
		pos++;
		if (tmp->next->data == data_to_find)
		{
			return tmp->next;
		}
		tmp = tmp->next;

	}

	return nullptr;
}

void DoublyLinkedList::display()
{
	std::cout << "Elementy listy dwukierunkowej ("<<count()<<"): "<< std::endl;

	Node_DoublyLinkedList * tmp = head_list;

	while (tmp!=nullptr)
	{
		std::cout << tmp->data<<std::endl;
		tmp = tmp->next;
	}
}

void DoublyLinkedList::displayAtPos(int pos)
{
	//jeśli lista pusta to nic nie rób
	if (head_list == nullptr)
	{
		std::cout << "Lista jest pusta" << std::endl;
	}


	int i = 0;
	Node_DoublyLinkedList * tmp = head_list;
	
	if (pos == 0)
	{
		std::cout << "Liczba na szukanej pozycji to " << tmp->data << std::endl;
		return;
	}

	while (tmp->next != nullptr)
	{
		
		if (i == pos)
		{
			std::cout << "Liczba na szukanej pozycji to " << tmp->data << std::endl;
			return;
		}
		tmp = tmp->next;
		i++;
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

void DoublyLinkedList::countAndShow()
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