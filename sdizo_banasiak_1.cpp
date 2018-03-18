// sdizo_banasiak_1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "DoublyLinkedList.h"
#include "DynArray.h"
#include "KopiecMax.h"

using namespace std;

int main()
{
	cout << "SDiZO jest super!"<<endl;

	DynArray DArr;
	DoublyLinkedList DLList;
	KopiecMax Kopiec;

	Kopiec.add(1);
	Kopiec.add(3);
	Kopiec.add(2);
	Kopiec.add(5);
	Kopiec.add(4);
	Kopiec.add(7);
	Kopiec.add(9);
	Kopiec.add(8);
	Kopiec.add(6);
	Kopiec.rm();

	Kopiec.display("","",0);

	//DArr
/*	DArr.addEnd(0);
	DArr.addEnd(1);
	DArr.addEnd(2);
	DArr.addEnd(3);
	
	DArr.swapByPos(0,3);

	DArr.display();
	DArr.countAndDisplay();
	DArr.searchPrintIndex(100);*/


	//DLList
/*	DLList.addEnd(10);
	DLList.addEnd(1);
	DLList.addStart(2);
	DLList.addEnd(3);
	DLList.addStart(5);
	DLList.addEnd(6);
	DLList.addStart(4);
	DLList.rmEnd();

	DLList.countAndShow();
	DLList.display();

	DLList.searchPrintPos(3);*/
	
	getchar();
    return 0;
}

