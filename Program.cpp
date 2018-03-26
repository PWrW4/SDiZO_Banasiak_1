#include "stdafx.h"
#include "Program.h"
#include <windows.h>
#include <fstream>
#include <vector>
#include <algorithm>

void Program::MainMenu()
{
	char ch;
	do
	{
		clearConsole();
		std::cout << MenuSTR;
		ch = getchar();

		switch (ch)
		{
		case '1':
			GenerateData();
			break;
		case '2':
			LoadData();
			break;
		case '3':
			AutoTestAndBenchmark();
			break;
		case '4':
			ManualCMDs();
			break;
		default:
			if (ch != 'q' && ch != 'Q' && ch != '0' && ch != '1' && ch != '2'&& ch != '3'&& ch != '4')
			{
			std::cout << "Nieznana komenda :( , nacisnij enter by kontynulowac"<<std::endl;
			getchar();
			getchar();
			}
			break;
		}
	} while (ch != 'q' && ch != 'Q' && ch != '0');

}

void Program::GenerateData()
{
	int dataSize = 0;
	clearConsole();
	std::cout << "Ile liczb typu int ma zawierac plik z danymi:"<<std::endl;
	std::cin >> dataSize;

	std::ofstream file;

	file.open((std::to_string(dataSize) + ".txt"), std::ios::out);
	if (file.good()==true)
	{
		file << dataSize << std::endl;

		std::vector<int> dataToWrite;

		for (int i = 0; i < dataSize; i++) dataToWrite.push_back(i);

		std::random_shuffle(dataToWrite.begin(), dataToWrite.end());

		for (int i = 0; i < dataSize; i++) file << dataToWrite[i] << std::endl;

		file.close();
		std::cout << "Nacisnij enter by powrocic do menu" << std::endl;
	}
	else
	{
		std::cout << "Nie udalo sie otworzyc pliku, nacisnij enter by powrocic do menu" << std::endl;
		file.close();
	}
	getchar();
	getchar();
}

void Program::LoadData()
{
	int dataSize = 0;
	std::string dataSizeStr;
	clearConsole();
	std::cout << "Podaj nazwe pliku" << std::endl;
	std::cin >> dataSizeStr;

	std::ifstream file;

	delete dynArray;
	delete kopiecMax;
	delete dLList;

	dynArray = new DynArray();;
	kopiecMax = new KopiecMax();
	dLList = new DoublyLinkedList();

	file.open(dataSizeStr + ".txt", std::ios::in);
	if (file.good() == true)
	{
		file >> dataSize;
		
		int dataToAdd;

		for(int i=0;i<dataSize;i++)
		{
			file >> dataToAdd;
			
			dynArray->addEnd(dataToAdd);
			kopiecMax->add(dataToAdd);
			dLList->addEnd(dataToAdd);
		}

		file.close();
		std::cout << "Nacisnij enter by powrocic do menu" << std::endl;
	}
	else
	{
		std::cout << "Nie udalo sie otworzyc pliku, nacisnij enter by powrocic do menu" << std::endl;
		file.close();
	}

	std::cout << "Nacisnij enter by powrocic do menu" << std::endl;
	getchar();
	getchar();
}

void Program::AutoTestAndBenchmark()
{
	std::cout << "Nacisnij enter by powrocic do menu" << std::endl;
	getchar();
	getchar();
}

void Program::ManualCMDs()
{
	char ch;
	do
	{
		clearConsole();
		std::cout << ManualSTR;
		ch = getchar();

		switch (ch)
		{
		case '1':
			DynArrayMenu();
			break;
		case '2':
			KopiecMenu();
			break;
		case '3':
			ListaMenu();
			break;
		default:
			if (ch != 'q' && ch != 'Q' && ch != '0' && ch != '1' && ch != '2'&& ch != '3')
			{
				std::cout << "Nieznana komenda :( , nacisnij enter by kontynulowac" << std::endl;
				getchar();
				getchar();
			}
			break;
		}
	} while (ch != 'q' && ch != 'Q' && ch != '0');
}

void Program::DynArrayMenu()
{
	int data;
	int pos;
	char ch;
	do
	{
		clearConsole();
		std::cout << ArraySTR;
		ch = getchar();


		switch (ch)
		{
		case '1':
			std::cin >> data;
			dynArray->addStart(data);
			getchar();
			getchar();
			break;
		case '2':
			std::cin >> data;
			dynArray->addEnd(data);
			getchar();
			getchar();
			break;
		case '3':
			dynArray->rmStart();
			getchar();
			getchar();
			break;
		case '4':
			dynArray->rmEnd();
			getchar();
			getchar();
			break;
		case '5':
			std::cin >> data;
			dynArray->searchRetunIndex(data);
			getchar();
			getchar();
			break;
		case '6':
			std::cin >> data;
			std::cin >> pos;
			dynArray->addAtPos(data,pos);
			getchar();
			getchar();
			break;
		case '7':
			dynArray->rmAtPos(data);
			getchar();
			getchar();
			break;
		case '8':
			dynArray->display();
			getchar();
			getchar();
			break;
		case '9':
			std::cin >> pos;
			dynArray->displayIndex(pos);
			getchar();
			getchar();
			break;
		default:
			if (ch != 'q' && ch != 'Q' && ch != '0' && ch != '1' && ch != '2'&& ch != '3'&& ch != '4'&& ch != '5'&& ch != '6'&& ch != '7'&& ch != '8'&& ch != '9')
			{
				std::cout << "Nieznana komenda :( , nacisnij enter by kontynulowac" << std::endl;
				getchar();
				getchar();
			}
			break;
		}
	} while (ch != 'q' && ch != 'Q' && ch != '0');
}

void Program::KopiecMenu()
{
	int data;
	int pos;
	char ch;
	do
	{
		clearConsole();
		std::cout << KopiecSTR;
		ch = getchar();


		switch (ch)
		{
		case '1':
			std::cin >> data;
			kopiecMax->add(data);
			getchar();
			getchar();
			break;
		case '2':
			kopiecMax->rm();
			getchar();
			getchar();
			break;
		case '3':
			std::cin >> data;
			kopiecMax->searchRetunIndex(data);
			getchar();
			getchar();
			break;
		case '4':
			std::cout << "Kopiec sklada sie z " << kopiecMax->count() << "elementow." << std::endl;
			kopiecMax->display("","",0);
			getchar();
			getchar();
			break;
		case '5':
			std::cin >> pos;
			kopiecMax->displayIndex(pos);
			getchar();
			getchar();
			break;
		default:
			if (ch != 'q' && ch != 'Q' && ch != '0' && ch != '1' && ch != '2'&& ch != '3'&& ch != '4'&& ch != '5')
			{
				std::cout << "Nieznana komenda :( , nacisnij enter by kontynulowac" << std::endl;
				getchar();
				getchar();
			}
			break;
		}
	} while (ch != 'q' && ch != 'Q' && ch != '0');
}

void Program::ListaMenu()
{
	int data;
	int pos;
	char ch;
	do
	{
		clearConsole();
		std::cout << ListSTR;
		ch = getchar();


		switch (ch)
		{
		case '1':
			std::cin >> data;
			dLList->addStart(data);
			getchar();
			getchar();
			break;
		case '2':
			std::cin >> data;
			dLList->addEnd(data);
			getchar();
			getchar();
			break;
		case '3':
			dLList->rmStart();
			getchar();
			getchar();
			break;
		case '4':
			dLList->rmEnd();
			getchar();
			getchar();
			break;
		case '5':
			std::cin >> data;
			dLList->searchRetunIndex(data);
			getchar();
			getchar();
			break;
		case '6':
			std::cin >> data;
			std::cin >> pos;
			dLList->addAtPos(data,pos);
			getchar();
			getchar();
			break;
		case '7':
			std::cin >> pos;
			dLList->rmAtPos(pos);
			getchar();
			getchar();
			break;
		case '8':
			dLList->display();
			getchar();
			getchar();
			break;
		case '9':
			std::cin >> pos;
			dLList->displayAtPos(pos);
			getchar();
			getchar();
			break;
		default:
			if (ch != 'q' && ch != 'Q' && ch != '0' && ch != '1' && ch != '2'&& ch != '3'&& ch != '4'&& ch != '5'&& ch != '6'&& ch != '7'&& ch != '8'&& ch != '9')
			{
				std::cout << "Nieznana komenda :( , nacisnij enter by kontynulowac" << std::endl;
				getchar();
				getchar();
			}
			break;
		}
	} while (ch != 'q' && ch != 'Q' && ch != '0');
}


void Program::clearConsole()
{
	system("cls");
}

Program::Program()
{
	MainMenu();
}


Program::~Program()
{
}
