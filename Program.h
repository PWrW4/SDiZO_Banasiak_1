#pragma once
#include <string>
#include "DynArray.h"
#include "KopiecMax.h"
#include "DoublyLinkedList.h"

class Program
{
private:
	std::string MenuSTR = "SDiZO - Wojciech Wojcik \n \n1.Generate data \n2.Load data \n3.Auto Test i benchmark \n4.Manualne komendy \nAby wyjsc do glownego menu nacisnij 0 lub q lub Q\n";

	DynArray dynArray;
	KopiecMax kopiecMax;
	DoublyLinkedList dLList;

	void MainMenu();

	void GenerateData();

	void LoadData();

	void AutoTestAndBenchmark();

	void ManualCMDs();

	void clearConsole();
public:
	Program();
	~Program();
};

