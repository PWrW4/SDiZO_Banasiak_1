#include "stdafx.h"
#include "Program.h"
#include <windows.h>
#include <fstream>
#include <vector>
#include <algorithm>
#include <ctime>

void Program::MainMenu()
{
	int switchInt;
	do
	{
		clearConsole();
		std::cout << MenuSTR;
		std::cin >> switchInt;

		switch (switchInt)
		{
		case 1:
			std::cout << "Ile liczb typu int ma zawierac plik z danymi: " << std::endl;
			int datasize;
			std::cin >> datasize;
			GenerateData(datasize);
			break;
		case 2:
			std::cout << "Nazwa pliku do wczytania (tylko liczby calkowite): " << std::endl;
			int datasize2;
			std::cin >> datasize2;
			LoadData(datasize2);
			break;
		case 3:
			std::cout << "Podaj rozmiar danych do przetestowania: " << std::endl;
			int dataSize3;
			std::cin >> dataSize3;
			std::cout << "Podaj liczbe powtorzen " << std::endl;
			int forint;
			std::cin >> forint;
			AutoTestAndBenchmark(dataSize3, forint);
			break;
		case 4:
			ManualCMDs();
			break;
		default:
			if (switchInt != 0)
			{
			std::cout << "Nieznana komenda :( , nacisnij enter by kontynulowac"<<std::endl;
			getchar();
			getchar();
			}
			break;
		}
	} while (switchInt != 0);

}

void Program::GenerateData(int dataSize)
{
	clearConsole();
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
	}
	else
	{
		std::cout << "Nie udalo sie otworzyc pliku" << std::endl;
		file.close();
	}
	//	std::cout << "Nacisnij enter by powrocic do menu" << std::endl;
	//	getchar();
	//	getchar();
}

void Program::LoadData(int dataSize)
{
	clearConsole();
	std::ifstream file;

	std::fstream loadTimes;
	loadTimes.open("loadtimes.txt", std::ios::app);
	//rozmiar danych;dynamiczna tablica;kopiec;lista2kierunkowa

	delete dynArray;
	delete kopiecMax;
	delete dLList;

	dynArray = new DynArray();;
	kopiecMax = new KopiecMax();
	dLList = new DoublyLinkedList();

	StartCounter();
	file.open(std::to_string(dataSize) + ".txt", std::ios::in);
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
		loadTimes << dataSize << ";" <<GetCounter()<<";";

		
		file.close();
	}
	else
	{
		std::cout << "Nie udalo sie otworzyc pliku." << std::endl;
		file.close();
	}

	file.open(std::to_string(dataSize) + ".txt", std::ios::in);
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
		loadTimes << GetCounter() << ";";


		file.close();
	}
	else
	{
		std::cout << "Nie udalo sie otworzyc pliku." << std::endl;
		file.close();
	}

	file.open(std::to_string(dataSize) + ".txt", std::ios::in);
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
		loadTimes << GetCounter() << ";";

		file.close();
	}
	else
	{
		std::cout << "Nie udalo sie otworzyc pliku." << std::endl;
		file.close();
	}
	loadTimes << std::endl;
	loadTimes.close();
	//	std::cout << "Nacisnij enter by powrocic do menu" << std::endl;
	//	getchar();
	//	getchar();
}

void Program::AutoTestAndBenchmark(int dataSize, int forint)
{
	std::fstream file;
	for (int i=0; i<forint; i++)
	{
		GenerateData(dataSize);
		LoadData(dataSize);
		std::cout << i << std::endl;

		file.open(("kopiectest.txt"), std::ofstream::app);
		if (file.good() == true)
		{
			//file << "rozmiar kopca;usuniecie;dodanie;wyszukanie;" << std::endl;
			int i = kopiecMax->count();

			file << kopiecMax->count() << ";";

			int a = rand() % (i - 1);

			StartCounter();
			kopiecMax->add(a);
			file << GetCounter() << ";";

			StartCounter();
			kopiecMax->rm();
			file << GetCounter() << ";";

			srand(time(NULL));



			StartCounter();
			kopiecMax->searchRetunIndex(a);
			file << GetCounter() << ";";

			file << std::endl;

			file.close();
		}
		else
		{
			std::cout << "Nie udalo sie otworzyc pliku, nacisnij enter by powrocic do menu" << std::endl;
			file.close();
		}

		file.open(("arraytest.txt"), std::ofstream::app);
		if (file.good() == true)
		{
			//file << "rozmiar tablicy;dodanie na start;usuniecie ze startu;dodanie na koncu;usuniecie z konca;dodanie na pozycji;usuniecie z pozycji;szukanie;" << std::endl;

			int i = dynArray->count();


			file << dynArray->count() << ";";

			StartCounter();
			dynArray->addStart(i);
			file << GetCounter() << ";";

			StartCounter();
			dynArray->rmStart();
			file << GetCounter() << ";";

			StartCounter();
			dynArray->addEnd(i);
			file << GetCounter() << ";";

			StartCounter();
			dynArray->rmEnd();
			file << GetCounter() << ";";

			srand(time(NULL));

			int a = rand() % (i - 1);

			StartCounter();
			dynArray->addAtPos(i, a);
			file << GetCounter() << ";";

			StartCounter();
			dynArray->rmAtPos(a);
			file << GetCounter() << ";";

			StartCounter();
			dynArray->searchRetunIndex(a);
			file << GetCounter() << ";";

			file << std::endl;

			file.close();
		}
		else
		{
			std::cout << "Nie udalo sie otworzyc pliku, nacisnij enter by powrocic do menu" << std::endl;
			file.close();
		}

		file.open(("listtest.txt"), std::ofstream::app);
		if (file.good() == true)
		{
			int i = dLList->count();

			//file << "rozmiar listy;dodanie na start;usuniecie ze startu;dodanie na koncu;usuniecie z konca;dodanie na pozycji;usuniecie z pozycji;szukanie;" << std::endl;


			file << dLList->count() << ";";

			StartCounter();
			dLList->addStart(i);
			file << GetCounter() << ";";

			StartCounter();
			dLList->rmStart();
			file << GetCounter() << ";";

			StartCounter();
			dLList->addEnd(i);
			file << GetCounter() << ";";

			StartCounter();
			dLList->rmEnd();
			file << GetCounter() << ";";

			srand(time(NULL));

			int a = rand() % (i - 1);

			StartCounter();
			dLList->addAtPos(i, a);
			file << GetCounter() << ";";

			StartCounter();
			dLList->rmAtPos(a);
			file << GetCounter() << ";";

			StartCounter();
			dLList->searchRetunIndex(a);
			file << GetCounter() << ";";

			file << std::endl;
			file.close();
		}
		else
		{
			std::cout << "Nie udalo sie otworzyc pliku, nacisnij enter by powrocic do menu" << std::endl;
			file.close();
		}
	}

//	std::cout << "Nacisnij enter by powrocic do menu" << std::endl;
//	getchar();
//	getchar();
}

void Program::ManualCMDs()
{
	int switchInt;
	do
	{
		clearConsole();
		std::cout << ManualSTR;
		std::cin >> switchInt;

		switch (switchInt)
		{
		case 1:
			DynArrayMenu();
			break;
		case 2:
			KopiecMenu();
			break;
		case 3:
			ListaMenu();
			break;
		default:
			if (switchInt != 0)
			{
				std::cout << "Nieznana komenda :( , nacisnij enter by kontynulowac" << std::endl;
			getchar();
			}
			break;
		}
	} while (switchInt != 0);
}

void Program::DynArrayMenu()
{
	int data;
	int pos;
	int switchInt;
	do
	{
		clearConsole();
		std::cout << ArraySTR;
		std::cin >> switchInt;


		switch (switchInt)
		{
		case 1:
			std::cin >> data;
			StartCounter();
			dynArray->addStart(data);
			std::cout << "czas " << GetCounter() << std::endl;;
			getchar();
			getchar();
			break;
		case 2:
			std::cin >> data;
			StartCounter();
			dynArray->addEnd(data);
			std::cout << "czas " << GetCounter() << std::endl;;
			getchar();
			getchar();
			break;
		case 3:
			StartCounter();
			dynArray->rmStart();
			std::cout << "czas " << GetCounter() << std::endl;;
			getchar();
			getchar();
			break;
		case 4:
			StartCounter();
			dynArray->rmEnd();
			std::cout << "czas " << GetCounter() << std::endl;;
			getchar();
			getchar();
			break;
		case 5:
			std::cin >> data;
			StartCounter();
			std::cout << "Element ktorego szukasz ma indeks: " <<dynArray->searchRetunIndex(data)<<std::endl;		
			std::cout << "czas " << GetCounter() << std::endl;;
			getchar();
			getchar();
			break;
		case 6:
			std::cin >> data;
			std::cin >> pos;
			StartCounter();
			dynArray->addAtPos(data,pos);
			std::cout << "czas " << GetCounter() << std::endl;;
			getchar();
			getchar();
			break;
		case 7:
			StartCounter();
			dynArray->rmAtPos(data);
			std::cout << "czas " << GetCounter() << std::endl;;
			getchar();
			getchar();
			break;
		case 8:
			StartCounter();
			dynArray->display();
			std::cout << "czas " << GetCounter() << std::endl;;
			getchar();
			getchar();
			break;
		case 9:
			std::cin >> pos;
			StartCounter();
			dynArray->displayIndex(pos);
			std::cout << "czas " << GetCounter() << std::endl;;
			getchar();
			getchar();
			break;
		default:
			if (switchInt!=0)
			{
				std::cout << "Nieznana komenda :( , nacisnij enter by kontynulowac" << std::endl;
			getchar();
			getchar();
			}
			break;
		}
	} while (switchInt != 0);
}

void Program::KopiecMenu()
{
	int data;
	int pos;
	int switchInt;
	do
	{
		clearConsole();
		std::cout << KopiecSTR;
		std::cin >> switchInt;;


		switch (switchInt)
		{
		case 1:
			std::cin >> data;
			StartCounter();
			kopiecMax->add(data);
			std::cout << "czas " << GetCounter() << std::endl;;
			getchar();
			getchar();
			break;
		case 2:
			StartCounter();
			kopiecMax->rm();
			std::cout << "czas " << GetCounter() << std::endl;;
			getchar();
			getchar();
			break;
		case 3:
			std::cin >> data;
			StartCounter();
			std::cout << "Element ktorego szukasz ma indeks: " << kopiecMax->searchRetunIndex(data)<<std::endl;
			std::cout << "czas " << GetCounter() << std::endl;;
			getchar();
			getchar();
			break;
		case 4:
			StartCounter();
			std::cout << "Kopiec sklada sie z " << kopiecMax->count() << " elementow." << std::endl<<std::endl;
			kopiecMax->display("","",0);
			std::cout <<std::endl<< "czas " << GetCounter() << std::endl;;
			getchar();
			getchar();
			break;
		case 5:
			std::cin >> pos;
			StartCounter();
			kopiecMax->displayIndex(pos);
			std::cout << "czas " << GetCounter() << std::endl;;
			getchar();
			getchar();
			break;
		default:
			if (switchInt != 0)
			{
				std::cout << "Nieznana komenda :( , nacisnij enter by kontynulowac" << std::endl;
			getchar();
			getchar();
			}
			break;
		}
	} while (switchInt != 0);
}

void Program::ListaMenu()
{
	int data;
	int pos;
	int switchInt;
	do
	{
		clearConsole();
		std::cout << ListSTR;
		std::cin >> switchInt;


		switch (switchInt)
		{
		case 1:
			std::cin >> data;
			StartCounter();
			dLList->addStart(data);
			std::cout << "czas " << GetCounter() << std::endl;;
			getchar();
			getchar();
			break;
		case 2:
			std::cin >> data;
			StartCounter();
			dLList->addEnd(data);
			std::cout << "czas " << GetCounter() << std::endl;;
			getchar();
			getchar();
			break;
		case 3:
			StartCounter();
			dLList->rmStart();
			std::cout << "czas " << GetCounter() << std::endl;;
			getchar();
			getchar();
			break;
		case 4:
			StartCounter();
			dLList->rmEnd();
			std::cout << "czas " << GetCounter() << std::endl;;
			getchar();
			getchar();
			break;
		case 5:
			std::cin >> data;
			StartCounter();
			std::cout << "Szukany element ma indeks " <<dLList->searchRetunIndex(data) << std::endl;
			std::cout << "czas " << GetCounter() << std::endl;;
			getchar();
			getchar();
			break;
		case 6:
			std::cin >> data;
			std::cin >> pos;
			StartCounter();
			dLList->addAtPos(data,pos);
			std::cout << "czas " << GetCounter() << std::endl;;
			getchar();
			getchar();
			break;
		case 7:
			std::cin >> pos;
			StartCounter();
			dLList->rmAtPos(pos);
			std::cout << "czas " << GetCounter() << std::endl;;
			getchar();
			getchar();
			break;
		case 8:
			StartCounter();
			dLList->display();
			std::cout << "czas " << GetCounter() << std::endl;;
			getchar();
			getchar();
			break;
		case 9:
			std::cin >> pos;
			StartCounter();
			dLList->displayAtPos(pos);
			std::cout << "czas " << GetCounter() << std::endl;;
			getchar();
			getchar();
			break;
		default:
			if (switchInt!=0)
			{
				std::cout << "Nieznana komenda :( , nacisnij enter by kontynulowac" << std::endl;
			getchar();
			getchar();
			}
			break;
		}
	} while (switchInt != 0);
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
	dynArray = new DynArray();
	kopiecMax = new KopiecMax();
	dLList = new DoublyLinkedList();
	MainMenu();
}


Program::~Program()
{
}
