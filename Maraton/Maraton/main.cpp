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
//1. Celem projekt jest przeæwiczenie implementacji i korzystania z dynamicznych struktur danych (np. listy, drzewa) i zarz¹dzania pamiêci¹ w programie. Warunkiem sine qua non jest u¿ycie w programie tych struktur.
//2. U¿ycie bibliotecznych kontenerów (np. vector, list itd.) ani dynamicznie alokowanych tablic nie spe³nia warunku z pkt. 1.
//3. Typu string mo¿na u¿ywaæ wy³¹cznie do przechowywania napisów, np. nazw plików itd. Nie jest dopuszczalne u¿ycie tego typu do przechowywania ci¹gów danych, np. ci¹gu liczb.
//4. Przed implementacj¹ konieczna jest akceptacja struktury danych przez prowadz¹cego zajêcia.
//5. Program powinien byæ podzielony na pliki z deklaracjami (*.h) i definicjami (*.cpp).
//6. Wszystkie funkcje musz¹ byæ skomentowane w doxygenie.

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cstdio>

#include "funkcje.h";

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>


struct zawodnik {
	std::string nazwisko="";
	int rok=0;
	int miesiac=0;
	int dzien=0;
	std::string turniej="";
	int hour=0;
	int min=0;
	int sec=0;
	zawodnik* pNext=nullptr;
};

/*void dodaj_pierwszy_do_listy(
	zawodnik*& pHead,
	std::string nazwisko,
	int rok,
	int miesiac,
	int dzien,
	std::string turniej,
	int hour,
	int min,
	int sec
) {
	pHead->nazwisko = nazwisko;
	pHead->rok = rok;
	pHead->miesiac = miesiac;
	pHead->dzien = dzien;
	pHead->turniej = turniej;
	pHead->hour = hour;
	pHead->min = min;
	pHead->sec = sec;
	pHead->pNext = nullptr;
}*/

void dodaj_na_poczatek_listy(
	zawodnik*& pHead,
	std::string nazwisko,
	int rok,
	int miesiac,
	int dzien,
	std::string turniej,
	int hour,
	int min,
	int sec
) {
	pHead = new zawodnik{ nazwisko,rok,miesiac,dzien,turniej,hour,min,sec,pHead };
}

void wyswietl_liste(zawodnik*& pHead)
{
	// wskaznik na pierszy element listy
	zawodnik* temp = pHead;

	// przewijamy wskazniki na nastepne elementy
	while (temp)
	{
		if(temp->pNext != nullptr)//czy tak mo¿na?
		std::cout
			<< " temp: " << temp
			<< " nazwisko: " << temp->nazwisko
			<< " rok: " << temp->rok
			<< " miesiac: " << temp->miesiac
			<< " dzien: " << temp->dzien
			<< " turniej: " << temp->turniej
			<< " hour: " << temp->hour
			<< " min: " << temp->min
			<< " sec: " << temp->sec
			<< " pNext: " << temp->pNext
			<< std::endl << std::endl;
		temp = temp->pNext;
	}
}


int main(int argc, char** argv) {
	
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

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

		bool semafor_udanego_wczytania_plikow = true;
		int ilosc_plikow = 0;
		std::string* nazwy_plikow;
		zawodnik* lista = new zawodnik;

		nazwy_plikow = new std::string[argc - 2];
		for (int i = 2; i < argc; i++) {
			nazwy_plikow[i - 2] = argv[i];
			ilosc_plikow++;
		}

		for (int i = 0; i < ilosc_plikow; i++) {
			//std::clog <<"Plik: "<< nazwy_plikow[i] <<std::endl;
			std::ifstream plik(nazwy_plikow[i]);
			std::string linia = "";
			std::string nazwisko = "";
			std::string nazwa_turnieju = "";
			std::string data = "";
			int rok = 0;
			int miesiac = 0;
			int dzien = 0;
			std::string czas = "";
			int hour = 0;
			int min = 0;
			int sec = 0;
			int kolejnosc_na_mecie = 0;
			int numer_zawodnika_w_zawodach = 0;
			char znak = 0;

			if (plik) {
				//std::clog << "plik zostal otwarty" << std::endl;
				int nr_lini = 0;

				while ( getline(plik,linia) ) {
					std::istringstream s_linia(linia);
					//std::clog << "pobrano linijke z pliku" << std::endl;
					//	<kolejnoœæ na mecie>, <nazwisko>, <nr zawodnika w zawodach>, <czas (w formacie: gg:mm:ss)>

					switch (nr_lini) {
					case 0:
						nr_lini++;
						if (s_linia >> nazwa_turnieju) {
							//std::clog << "znaleziono tytul" << std::endl;
							nazwa_turnieju = linia;
						}
						else {
							semafor_udanego_wczytania_plikow = false;
							/*clog<<"twój plik :"<< nazwy_plikow[i] <<"nie zawiera nazwy tujnieju"<<endl;*/ 
						}
						break;
					case 1:
						nr_lini++;
						if (s_linia >> data) {
							std::stringstream s_data(data);
							if (s_data >> rok >> znak >> miesiac >> znak >> dzien) {
								if (znak == '-') {/*zapis*/}
								else {
									semafor_udanego_wczytania_plikow = false;
								}
							}
							else {
								semafor_udanego_wczytania_plikow = false;
							}
							//std::clog << "znaleziono date" << std::endl;
						}
						else {
							semafor_udanego_wczytania_plikow = false;
							/*plik nie zawiera daty*/ 
						}
						break;
					default:
						nr_lini++;
						char* tab_linia = new char[linia.length() + 1];
						strcpy(tab_linia, linia.c_str());
						char* bez_przecinka = strtok(tab_linia, " ,");
						std::string form_linia;
						while (bez_przecinka != NULL)
						{
							form_linia += " ";
							form_linia += bez_przecinka;
							bez_przecinka = strtok(NULL, " ,.-");
						}
						std::istringstream s_linia(form_linia);
						if (s_linia >> kolejnosc_na_mecie >> nazwisko >> numer_zawodnika_w_zawodach >> czas) {
							//std::clog << "znaleziono wartosc" << std::endl;
							//std::cout << "linia " << i << ": " << kolejnosc_na_mecie << " " << nazwisko << " " << numer_zawodnika_w_zawodach << " " << czas << std::endl;
							std::istringstream s_czas(czas);
							if (s_czas >> hour >> znak >> min >> znak >> sec) {
								if (znak == ':') {
									/*to jest czas*/
									dodaj_na_poczatek_listy(lista, nazwisko, rok, miesiac, dzien, nazwa_turnieju, hour, min, sec);
								}
								else {
									semafor_udanego_wczytania_plikow = false;
									//error Ÿle podany czas
								}
							}
							else {
								semafor_udanego_wczytania_plikow = false;
							}
						}
						else {
							semafor_udanego_wczytania_plikow = false;
						}
						delete[] tab_linia;
						tab_linia = nullptr;
						delete[] bez_przecinka;
						bez_przecinka = nullptr;
						break;
					}
				}
				plik.close();

			}
			else {
				semafor_udanego_wczytania_plikow = false;
				std::clog << "plik' "<< nazwy_plikow[i] <<"' nie zostal otwarty" << std::endl;
			}
		}
		if (semafor_udanego_wczytania_plikow) {
			std::clog << "wszystkie pliki zostaly poprawnie wczytane" << std::endl;
			wyswietl_liste(lista);
		}
		else {
			std::clog << "W pliku wystapily bledy" << std::endl;
			wyswietl_liste(lista);
		}
		delete[] nazwy_plikow;
		nazwy_plikow = nullptr;
		//delete lista;
	}
	else {
	std::cerr << "Brak plikow wejsciowych, prosze podac pliki z przelacznikiem -i oraz nazwami plikow" << std::endl;
		return 1;
	}

	//system("doxygen zrób co masz zrobiæ");
	return 0;
}
