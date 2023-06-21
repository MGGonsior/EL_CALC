/*
KALKULATOR DLA ELEKTRONIKÓW/INFORMATYKÓW

Podstawowe cele i zadania:

Celem projektu jest stworzenie aplikacji – kalkulatora wykonującego kilka podstawowych działań dla elektroników, czyli z możliwością przełączenia się na systemy: bin, oct, hex, albo float.
Aplikacja składa się zasadniczo z dwóch modułów:
- sytemu klas, hierarchii, design patterns realizujących działania kalkulatora (jak najbardziej niezależne od platformy i języka)
- interfejsu użytkownika (prosty dialog pod Windows lub Linux)
Należy zwrócić szczególną uwagę na przejrzystość projektu oraz możliwość zastosowania poznanych technik projektowania i programowania obiektowego.

Platforma:

Visual C++, Windows / gcc, Linux

Autor: Mateusz Gasiorowski
Student AGH 
Wydzial: WIET
Kierunek: Elektronika

Data ostatniej modyfikacji: 21.06.2023
*/

#include "Kalkulator_dla_elektronikow_MG.h"
#include <iostream>
#include <cerrno>
#include "Console.h"


using namespace std;

int main()
{
	RunConsole();
}
