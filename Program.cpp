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
		std::cin.get(ch);

		switch (ch)
		{
		case '1':
			GenerateData();
			break;
		case '2':
			LoadData();
			break;
		case '3':
			break;
		case '4':
			break;
		default:
			/*			if (!(ch != 'q' && ch != 'Q' && ch != '0' && ch != '1' && ch != '2'))
			{
			std::cout << "Nieznana komenda :("<<std::endl;
			Sleep(1000);
			clearConsole();
			}*/
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
	std::cin.get();
	std::cin.get();
}

void Program::LoadData()
{
	int dataSize = 0;
	std::string dataSizeStr = 0;
	clearConsole();
	std::cout << "Podaj nazwe pliku" << std::endl;
	std::cin >> dataSize;

	std::ifstream file;

	file.open(dataSize + ".txt", std::ios::in);
	if (file.good() == true)
	{
		file >> dataSize;

		for

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

	std::cout << "Nacisnij enter by powrocic do menu" << std::endl;
	std::cin.get();
	std::cin.get();
}

void Program::AutoTestAndBenchmark()
{
	std::cout << "Nacisnij enter by powrocic do menu" << std::endl;
	std::cin.get();
	std::cin.get();
}

void Program::ManualCMDs()
{

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
