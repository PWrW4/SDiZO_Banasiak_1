#include "stdafx.h"
#include "KopiecMax.h"
#include <string>


void KopiecMax::add(int data_to_add)
{
	if (array==nullptr)
	{
		addEnd(data_to_add);
		return;
	}
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
	if (getParent(index)==-1)
	{
		return;
	}

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
	if (index==0)
	{
		return -1;
	}
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

void KopiecMax::display(std::string sp, std::string sn, int v)
{
	//DynArray::display();

	//algorytm zaczerpnięty z http://eduinf.waw.pl/inf/alg/001_search/0113.php

	std::string cr, cl, cp;
	cr = cl = cp = "  ";
	cr[0] = 218; cr[1] = 196;
	cl[0] = 192; cl[1] = 196;
	cp[0] = 179;
	std::string s;

	
		if (v < count())
		{
			s = sp;
			if (sn == cr) s[s.length() - 2] = ' ';
			display(s + cp, cr, 2 * v + 2);

			s = s.substr(0, sp.length() - 2);

			std::cout << s << sn << array[v] << std::endl;

			s = sp;
			if (sn == cl) s[s.length() - 2] = ' ';
			display(s + cp, cl, 2 * v + 1);
		}
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
