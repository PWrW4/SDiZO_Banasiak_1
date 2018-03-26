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

		StartCounter();
		for(int i=0;i<dataSize;i++)
		{
			file >> dataToAdd;
			
			dynArray->addEnd(dataToAdd);

		}
		std::cout << "Wczytanie tablicy "<<GetCounter()<<std::endl;

		
		file.close();
	}
	else
	{
		std::cout << "Nie udalo sie otworzyc pliku." << std::endl;
		file.close();
	}

	file.open(dataSizeStr + ".txt", std::ios::in);
	if (file.good() == true)
	{
		file >> dataSize;

		int dataToAdd;



		StartCounter();
		for (int i = 0; i<dataSize; i++)
		{
			file >> dataToAdd;

			kopiecMax->add(dataToAdd);

		}
		std::cout << "Wczytanie kopca " << GetCounter() << std::endl;


		file.close();
	}
	else
	{
		std::cout << "Nie udalo sie otworzyc pliku." << std::endl;
		file.close();
	}

	file.open(dataSizeStr + ".txt", std::ios::in);
	if (file.good() == true)
	{
		file >> dataSize;

		int dataToAdd;

		StartCounter();
		for (int i = 0; i<dataSize; i++)
		{
			file >> dataToAdd;

			dLList->addStart(dataToAdd);

		}
		std::cout << "Wczytanie listy " << GetCounter() << std::endl;

		file.close();
	}
	else
	{
		std::cout << "Nie udalo sie otworzyc pliku." << std::endl;
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
			StartCounter();
			std::cin >> data;
			dynArray->addStart(data);
			std::cout << "czas" << GetCounter() << std::endl;;
			getchar();
			getchar();
			break;
		case '2':
			StartCounter();
			std::cin >> data;
			dynArray->addEnd(data);
			std::cout << "czas" << GetCounter() << std::endl;;
			getchar();
			getchar();
			break;
		case '3':
			StartCounter();
			dynArray->rmStart();
			std::cout << "czas" << GetCounter() << std::endl;;
			getchar();
			getchar();
			break;
		case '4':
			StartCounter();
			dynArray->rmEnd();
			std::cout << "czas" << GetCounter() << std::endl;;
			getchar();
			getchar();
			break;
		case '5':
			StartCounter();
			std::cin >> data;
			std::cout << "Element ktorego szukasz ma indeks: " <<dynArray->searchRetunIndex(data)<<std::endl;		
			std::cout << "czas" << GetCounter() << std::endl;;
			getchar();
			getchar();
			break;
		case '6':
			StartCounter();
			std::cin >> data;
			std::cin >> pos;
			dynArray->addAtPos(data,pos);
			std::cout << "czas" << GetCounter() << std::endl;;
			getchar();
			getchar();
			break;
		case '7':
			StartCounter();
			dynArray->rmAtPos(data);
			std::cout << "czas" << GetCounter() << std::endl;;
			getchar();
			getchar();
			break;
		case '8':
			StartCounter();
			dynArray->display();
			std::cout << "czas" << GetCounter() << std::endl;;
			getchar();
			getchar();
			break;
		case '9':
			StartCounter();
			std::cin >> pos;
			dynArray->displayIndex(pos);
			std::cout << "czas" << GetCounter() << std::endl;;
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
			StartCounter();
			std::cin >> data;
			kopiecMax->add(data);
			std::cout << "czas" << GetCounter() << std::endl;;
			getchar();
			getchar();
			break;
		case '2':
			StartCounter();
			kopiecMax->rm();
			std::cout << "czas" << GetCounter() << std::endl;;
			getchar();
			getchar();
			break;
		case '3':
			StartCounter();
			std::cin >> data;
			std::cout << "Element ktorego szukasz ma indeks: " << kopiecMax->searchRetunIndex(data)<<std::endl;
			std::cout << "czas" << GetCounter() << std::endl;;
			getchar();
			getchar();
			break;
		case '4':
			StartCounter();
			std::cout << "Kopiec sklada sie z " << kopiecMax->count() << "elementow." << std::endl;
			kopiecMax->display("","",0);
			std::cout << "czas" << GetCounter() << std::endl;;
			getchar();
			getchar();
			break;
		case '5':
			StartCounter();
			std::cin >> pos;
			kopiecMax->displayIndex(pos);
			std::cout << "czas" << GetCounter() << std::endl;;
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
			StartCounter();
			dLList->addStart(data);
			std::cout << "czas" << GetCounter() << std::endl;;
			getchar();
			getchar();
			break;
		case '2':
			StartCounter();
			std::cin >> data;
			dLList->addEnd(data);
			std::cout << "czas" << GetCounter() << std::endl;;
			getchar();
			getchar();
			break;
		case '3':
			StartCounter();
			dLList->rmStart();
			std::cout << "czas" << GetCounter() << std::endl;;
			getchar();
			getchar();
			break;
		case '4':
			StartCounter();
			dLList->rmEnd();
			std::cout << "czas" << GetCounter() << std::endl;;
			getchar();
			getchar();
			break;
		case '5':
			StartCounter();
			std::cin >> data;
			dLList->searchRetunIndex(data);
			std::cout << "czas" << GetCounter() << std::endl;;
			getchar();
			getchar();
			break;
		case '6':
			StartCounter();
			std::cin >> data;
			std::cin >> pos;
			dLList->addAtPos(data,pos);
			std::cout << "czas" << GetCounter() << std::endl;;
			getchar();
			getchar();
			break;
		case '7':
			StartCounter();
			std::cin >> pos;
			dLList->rmAtPos(pos);
			std::cout << "czas" << GetCounter() << std::endl;;
			getchar();
			getchar();
			break;
		case '8':
			StartCounter();
			dLList->display();
			std::cout << "czas" << GetCounter() << std::endl;;
			getchar();
			getchar();
			break;
		case '9':
			StartCounter();
			std::cin >> pos;
			dLList->displayAtPos(pos);
			std::cout << "czas" << GetCounter() << std::endl;;
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

void Program::StartCounter()
{
	LARGE_INTEGER li;
	if (!QueryPerformanceFrequency(&li))
		std::cout << "QueryPerformanceFrequency failed!\n";

	PCFreq = double(li.QuadPart) / 1000.0;

	QueryPerformanceCounter(&li);
	CounterStart = li.QuadPart;
}

double Program::GetCounter()
{
	LARGE_INTEGER li;
	QueryPerformanceCounter(&li);
	return double(li.QuadPart - CounterStart) / PCFreq;
}

Program::Program()
{
	MainMenu();
}


Program::~Program()
{
}
