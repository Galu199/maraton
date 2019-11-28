/*

Maratoñczycy bior¹ udzia³ w ró¿nych zawodach. Po zakoñczeniu tworzona jest lista rankingowa w
nastêpuj¹cej postaci: w pierwszej linii jest nazwa maratoru, w drugiej data (w formacie: rrrr-mm-dd), w
kolejnych s¹ wyniki zawodników:

<kolejnoœæ na mecie>, <nazwisko>, <nr zawodnika w zawodach>, <czas (w formacie: gg:mm:ss)>

Przyk³adowy plik ma postaæ:

Maraton bostonski
2012-09-04
2, Jaworek, 1432, 04:34:12
1, Bukowy, 434, 03:54:45
3, Krol, 243, 04:37:32

Plików z wynikami zawodów mo¿e byæ dowolna liczba. Po wykonaniu programu uzyskujemy pliki wynikowe
zawieraj¹ce wyniki zawodników. Ka¿dy plik zawiera wyniki tylko jednego maratoñczyka. Nazwa pliku
jest to¿sama z nazwiskiem maratoñczyka. W pliku tym podane jest nazwisko i wyniki, które uzyska³ w
zawodach. Wyniki te s¹ przedstawione w nastêpuj¹cy sposób:

<data> <nazwa> <maratonu> <czas>

Wyniki s¹ posortowane wg daty. Przyk³adowy plik dla Jaworka:

Jaworek
2011-05-03 Maraton Swiateczny 04:01:43
2011-09-14 Bieg Rzeznika 04:13:32
2012-05-03 Do przodu! 04:02:43

Program uruchamiany jest z linii poleceñ z wykorzystaniem nastêpuj¹cego prze³¹cznika:
-i pliki wejœciowe z protoko³ami zawodów

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