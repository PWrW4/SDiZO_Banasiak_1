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

	void display();

	int count();
	void countAndDisplay();

	DynArray();
	~DynArray();
};

