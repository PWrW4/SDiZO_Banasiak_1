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

void DynArray::display()
{
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
