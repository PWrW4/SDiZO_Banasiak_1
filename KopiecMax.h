#pragma once
#include "DynArray.h"
class KopiecMax :
	private DynArray
{
public:

	void add(int data_to_add);
	void rm(int data_to_add);

	void fixDown(int index);
	void fixUp(int index);

	int getChildLeft(int index);
	int getChildRight(int index);
	int getParent(int index);

	int searchRetunIndex(int data_to_find) override;
	void searchPrintIndex(int data_to_find) override;
	int * searchRetunPointer(int data_to_find) override;

	void display() override;
	int count() override;
	void countAndDisplay() override;



	KopiecMax();
	~KopiecMax();
};

