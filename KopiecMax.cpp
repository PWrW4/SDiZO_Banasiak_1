#include "stdafx.h"
#include "KopiecMax.h"


void KopiecMax::add(int data_to_add)
{
}

void KopiecMax::rm(int data_to_add)
{
}

void KopiecMax::fixDown(int index)
{
}

void KopiecMax::fixUp(int index)
{
}

int KopiecMax::getChildLeft(int index)
{
	return (index * 2) + 1;
}

int KopiecMax::getChildRight(int index)
{
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
