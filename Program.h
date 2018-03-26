#pragma once
#include <string>
#include "DynArray.h"
#include "KopiecMax.h"
#include "DoublyLinkedList.h"

class Program
{
private:
	std::string MenuSTR = "SDiZO - Wojciech Wojcik \n \n1.Generate data \n2.Load data \n3.Auto Test i benchmark \n4.Manualne komendy \nAby wyjsc nacisnij 0 lub q lub Q\n";
	std::string ManualSTR = "SDiZO - Wojciech Wojcik \n \n1.Tablica dynamiczna \n2.Kopiec typu max \n3.Lista dwukierunkowa \nAby wyjsc do glownego menu nacisnij 0 lub q lub Q\n";
	std::string ArraySTR = "SDiZO - Wojciech Wojcik \n \n \nTablica Dynamiczna:  \n1.Dodaj na poczatek \n2.Dodaj na koniec \n3.Usun z poczatku \n4.Usun z konca \n5.Szukaj elementu \n6.Dodaj w dane miejsce \n7.Usun danego miejsca \n8.Wyswietl \n9.Wyswietl element o indeksie \nAby wyjsc do glownego menu nacisnij 0 lub q lub Q\n";
	std::string ListSTR = "SDiZO - Wojciech Wojcik \n \n \nLista Dwukierunkowa:  \n1.Dodaj na poczatek \n2.Dodaj na koniec \n3.Usun z poczatku \n4.Usun z konca \n5.Szukaj elementu \n6.Dodaj w dane miejsce \n7.Usun danego miejsca \n8.Wyswietl \n9.Wyswietl element o indeksie \nAby wyjsc do glownego menu nacisnij 0 lub q lub Q\n";
	std::string KopiecSTR = "SDiZO - Wojciech Wojcik \n \n \nKopiec typu max:  \n1.Dodaj \n2.Usun \n3.Szukaj elementu \n4.Wyswietl \n5.Wyswietl element o indeksie \nAby wyjsc do glownego menu nacisnij 0 lub q lub Q\n";

	DynArray * dynArray;
	KopiecMax * kopiecMax;
	DoublyLinkedList * dLList;

	void MainMenu();

	void GenerateData();

	void LoadData();

	void AutoTestAndBenchmark();

	void ManualCMDs();

	void DynArrayMenu();
	void KopiecMenu();
	void ListaMenu();

	void clearConsole();
public:

	double PCFreq = 0.0;
	__int64 CounterStart = 0;

	void StartCounter();
	double GetCounter();

	Program();
	~Program();
};

