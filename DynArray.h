#pragma once
 class DynArray
{
public:

	int * array = nullptr;
	int size;


	void addStart(int data_to_add);
	void addEnd(int data_to_add);
	void addAtPos(int data_to_add, int pos);

	void rmStart();
	void rmEnd();
	void rmAtPos(int pos);

	void swapByPos(int left, int right);

	virtual  int searchRetunIndex(int data_to_find);
	virtual void searchPrintIndex(int data_to_find);
	virtual int * searchRetunPointer(int data_to_find);

	virtual void displayIndex(int v);
	virtual void display();
	virtual int count();
	virtual void countAndDisplay();

	DynArray();
	~DynArray();
	 
 };

