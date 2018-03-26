#include "stdafx.h"
#include "DynArray.h"


void DynArray::addStart(int data_to_add)
{
	size++;
	if (array == nullptr)
	{
		array = new int[size];
		array[0] = data_to_add;
		return;
	}

	int * tmp = new int[size];
	tmp[0] = data_to_add;
	memcpy(tmp + 1, array, (size - 1) * sizeof(int));
	delete[] array;
	array = tmp;
}

void DynArray::addEnd(int data_to_add)
{
	size++;
	if (array == nullptr)
	{
		array = new int[size];
		array[0] = data_to_add;
		return;
	}

	int * tmp = new int[size];
	tmp[size-1] = data_to_add;
	memcpy(tmp, array, (size - 1) * sizeof(int));
	delete[] array;
	array = tmp;
}

void DynArray::addAtPos(int data_to_add, int pos)
{
	if (pos>size-1)
	{
		addEnd(data_to_add);
		return;
	}

	if (pos<0)
	{
		addStart(data_to_add);
		return;
	}

	size++;

	if (array == nullptr)
	{
		array = new int[size];
		array[0] = data_to_add;
		return;
	}

	int * tmp = new int[size];
	tmp[pos] = data_to_add;
	memcpy(tmp, array, pos * sizeof(int));
	memcpy(tmp+pos+1, array+pos, (size - pos-1) * sizeof(int));
	delete[] array;
	array = tmp;
}

void DynArray::rmStart()
{
	if (array == nullptr)
	{
		return;
	}

	size--;

	int * tmp = new int[size];
	memcpy(tmp, array + 1, size * sizeof(int));
	delete[] array;
	array = tmp;
}

void DynArray::rmEnd()
{
	if (array == nullptr)
	{
		return;
	}

	size--;

	int * tmp = new int[size];
	memcpy(tmp, array, size * sizeof(int));
	delete[] array;
	array = tmp;
}

void DynArray::rmAtPos(int pos)
{
	if (pos>size - 1)
	{
		rmEnd();
		return;
	}

	if (pos<0)
	{
		rmStart();
		return;
	}

	if (array == nullptr)
	{
		return;
	}

	size--;

	int * tmp = new int[size];
	memcpy(tmp, array, pos * sizeof(int));
	memcpy(tmp + pos, array + pos + 1, (size - pos) * sizeof(int));
	delete[] array;
	array = tmp;
}

void DynArray::swapByPos(int left, int right)
{
	if (left>size - 1 || right>size - 1)
	{
		std::cout << "Error1 while swaping." << std::endl;
		return;
	}

	if (left<0 || right<0)
	{
		std::cout << "Error2 while swaping." <<std::endl;
		return;
	}

	int tmp = array[left];
	array[left] = array[right];
	array[right] = tmp;
}

int DynArray::searchRetunIndex(int data_to_find)
{
	if (array == nullptr)
	{
		return -1;
	}

	for (int i = 0; i < size; i++)
	{
		if (array[i] == data_to_find)
		{
			return i;
		}
	}

	return -1;
}

void DynArray::searchPrintIndex(int data_to_find)
{
	if (array == nullptr)
	{
		std::cout << "Tablica jest pusta!"<<std::endl;
		return;
	}

	for (int i = 0; i < size; i++)
	{
		if (array[i] == data_to_find)
		{
			std::cout << "Szukany element jest pod indexem "<< i << std::endl;
			return;
		}
	}

	std::cout << "W tablicy nie ma tego elementu" << std::endl;
}

int* DynArray::searchRetunPointer(int data_to_find)
{
	if (array == nullptr)
	{
		return nullptr;
	}

	for (int i = 0; i < size; i++)
	{
		if (array[i]==data_to_find)
		{
			return array+i;
		}
	}

	return nullptr;
}

void DynArray::displayIndex(int v)
{
	if (v!=-1)
	{
		std::cout << "Liczba o indeksie " << v << " to:" << array[v] << std::endl;
	}	
}


void DynArray::display()
{
	countAndDisplay();
	std::cout << "Elementy tablicy dynalicznej: " <<std::endl;
	for (int i = 0; i < size; i++)
	{
		std::cout << array[i]<<std::endl;
	}
}



int DynArray::count()
{
	return size;
}

void DynArray::countAndDisplay()
{
	std::cout << "Rozmiar dynamicznej tablicy: " << size<<std::endl;
}

DynArray::DynArray()
{
}


DynArray::~DynArray()
{
}
