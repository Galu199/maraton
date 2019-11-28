/*

Marato�czycy bior� udzia� w r�nych zawodach. Po zako�czeniu tworzona jest lista rankingowa w
nast�puj�cej postaci: w pierwszej linii jest nazwa maratoru, w drugiej data (w formacie: rrrr-mm-dd), w
kolejnych s� wyniki zawodnik�w:

<kolejno�� na mecie>, <nazwisko>, <nr zawodnika w zawodach>, <czas (w formacie: gg:mm:ss)>

Przyk�adowy plik ma posta�:

Maraton bostonski
2012-09-04
2, Jaworek, 1432, 04:34:12
1, Bukowy, 434, 03:54:45
3, Krol, 243, 04:37:32

Plik�w z wynikami zawod�w mo�e by� dowolna liczba. Po wykonaniu programu uzyskujemy pliki wynikowe
zawieraj�ce wyniki zawodnik�w. Ka�dy plik zawiera wyniki tylko jednego marato�czyka. Nazwa pliku
jest to�sama z nazwiskiem marato�czyka. W pliku tym podane jest nazwisko i wyniki, kt�re uzyska� w
zawodach. Wyniki te s� przedstawione w nast�puj�cy spos�b:

<data> <nazwa> <maratonu> <czas>

Wyniki s� posortowane wg daty. Przyk�adowy plik dla Jaworka:

Jaworek
2011-05-03 Maraton Swiateczny 04:01:43
2011-09-14 Bieg Rzeznika 04:13:32
2012-05-03 Do przodu! 04:02:43

Program uruchamiany jest z linii polece� z wykorzystaniem nast�puj�cego prze��cznika:
-i pliki wej�ciowe z protoko�ami zawod�w

*/

#include <iostream>
#include <string>
/*
#include <sstream>
#include <vector>
#include <climits>
#include <random>
#include <chrono>
#include <iomanip>
*/
#include "funkcje.h";

int main(int argc, char** argv) {
	
	/*
	std::cout << argc << std::endl;
	std::cout << argv <<" "<< (argv[0]) << " " << sizeof(argv[0]) << " " << std::endl << std::endl;
	for(int i=0;i<argc;i++)
		std::cout << argv[i] << std::endl;
	*/
	/*
	if (argc > 2) { 
		std::cout << true << std::endl;
		if (strcmp(argv[1], "-i") == 0) {
			std::cout << true << std::endl; 
		}
		else {
			std::cout << false << std::endl; 
		}
	}
	else{
		std::cout << false << std::endl; 
	}
	*/

	if (argc > 2 && strcmp(argv[1], "-i") == 0) {
		std::string* nazwy_plikow;
		int ilosc_plikow = 0;

		nazwy_plikow = new std::string[argc - 2];
		for (int i = 2; i < argc; i++) {
			nazwy_plikow[i - 2] = argv[i];
			ilosc_plikow++;
		}
		for (int i = 0; i < ilosc_plikow; i++) {
			std::cout <<"Plik: "<< nazwy_plikow[i] <<std::endl;
		}

		delete[] nazwy_plikow;
		nazwy_plikow = nullptr;
	}
	else {
		std::cerr << "Brak plikow wejsciowych, prosze podac pliki z przelacznikiem -i oraz nazwami plikow"<<std::endl;
		return 1;
	}

	return 0;
}