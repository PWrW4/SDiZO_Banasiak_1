#include "stdafx.h"
#include "KopiecMax.h"


void KopiecMax::add(int data_to_add)
{
	addEnd(data_to_add);
	fixUp(count() - 1);
}

void KopiecMax::rm()
{
	swapByPos(0, count() - 1);
	rmEnd();
	fixDown(0);
}

void KopiecMax::fixDown(int index)
{
	if (getChildLeft(index) == -1 && getChildRight(index) == -1)
	{
		return;
	}

	if (array[index]>array[getChildLeft(index)] && getChildRight(index)==-1)
	{
		swapByPos(index, getChildLeft(index));
		return;
	}

	if (true)
	{
		
	}

	if (array[index]>array[getChildLeft(index)] && array[index]>array[getChildRight(index)])
	{
		return;
	}

	if (array[getChildLeft(index)]>array[getChildRight(index)])
	{
		swapByPos(index, getChildLeft(index));
		fixDown(getChildLeft(index));
	}
	else
	{
		swapByPos(index, getChildRight(index));
		fixDown(getChildRight(index));
	}
}

void KopiecMax::fixUp(int index)
{
	if (array[index]<array[getParent(index)])
	{
		return;
	}
	else
	{
		swapByPos(index, getParent(index));
		fixUp(getParent(index));
	}
}

int KopiecMax::getChildLeft(int index)
{
	if ((index * 2) + 1>=count())
	{
		return -1;
	}
	return (index * 2) + 1;
}

int KopiecMax::getChildRight(int index)
{
	if ((index * 2) + 2 >= count())
	{
		return -1;
	}
	return (index * 2) + 2;
}

int KopiecMax::getParent(int index)
{
	return (index - 1) / 2;
}

int KopiecMax::searchRetunIndex(int data_to_find)
{
	return 0;
}

void KopiecMax::searchPrintIndex(int data_to_find)
{
}

int* KopiecMax::searchRetunPointer(int data_to_find)
{
	return nullptr;
}

void KopiecMax::display()
{
	display();
}

int KopiecMax::count()
{
	return size;
}

void KopiecMax::countAndDisplay()
{
}

KopiecMax::KopiecMax()
{
}


KopiecMax::~KopiecMax()
{
}
