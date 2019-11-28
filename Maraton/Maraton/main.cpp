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
#include <fstream>
#include <sstream>
/*
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
		int ilosc_plikow = 0;
		std::string* nazwy_plikow;
		nazwy_plikow = new std::string[argc - 2];

		for (int i = 2; i < argc; i++) {
			nazwy_plikow[i - 2] = argv[i];
			ilosc_plikow++;
		}

		for (int i = 0; i < ilosc_plikow; i++) {
			//std::clog <<"Plik: "<< nazwy_plikow[i] <<std::endl;
			std::ifstream plik(nazwy_plikow[i]);
			std::string linia;

			if (plik) {
				//std::clog << "plik zostal otwarty" << std::endl;

				int i = 0;
				std::string nazwa_turnieju = "";
				std::string data = "";
				int kolejnosc_na_mecie = 0;
				std::string nazwisko = "";
				int numer_zawodnika_w_zawodach = 0;
				std::string czas = "";
				char przecinek = ',';

				while ( getline(plik,linia) ) {
					//std::clog << "pobrano linijke z pliku" << std::endl;
					std::istringstream slinia(linia);
					std::istringstream sczas(czas);
					//<kolejnoœæ na mecie>, <nazwisko>, <nr zawodnika w zawodach>, <czas (w formacie: gg:mm:ss)>
					if (slinia >> kolejnosc_na_mecie >> przecinek >> nazwisko >> numer_zawodnika_w_zawodach >> przecinek >> czas) {
						//std::clog << "znaleziono wartosc" << std::endl;
						i++;
						//dokoncz czas;
						std::cout << "linia " << i << ": " << kolejnosc_na_mecie << " " << nazwisko << " " << numer_zawodnika_w_zawodach << " " << czas << std::endl;
					}
					else {
						switch (i) {
						case 0:
							i++;
							if (slinia >> nazwa_turnieju) {
								//std::clog << "znaleziono tytul" << std::endl;
							} else{ /*clog<<"twój plik :"<<~~~~<<"nie zawiera nazwy tujnieju"<<endl;*/ }
						break;
						case 1:
							i++;
							if (slinia >> data) {
								//std::clog << "znaleziono date" << std::endl;
							} else { /*plik nie zawiera daty*/ }
						break;
						default:
							i++;
						break;
						}
					}
				}
			}
			else {
				//std::clog << "plik nie zostal otwarty" << std::endl;
			}
			
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