// sdizo_banasiak_1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "DoublyLinkedList.h"
#include "DynArray.h"

using namespace std;

int main()
{
	cout << "SDiZO jest super!"<<endl;

	DynArray DArr;
	DoublyLinkedList DLList;


	//DArr
/*	DArr.addEnd(0);
	DArr.addEnd(1);
	DArr.addEnd(2);
	DArr.addEnd(3);
	DArr.addStart(4);
	
	DArr.display();
	DArr.countAndDisplay();
	DArr.searchPrintIndex(100);*/


	//DLList
	DLList.addEnd(10);
	DLList.addEnd(1);
	DLList.addStart(2);
	DLList.addEnd(3);
	DLList.addStart(5);
	DLList.addEnd(6);
	DLList.addStart(4);

	DLList.countAndShow();
	DLList.display();

	DLList.searchPrintPos(5);
	
	getchar();
    return 0;
}

