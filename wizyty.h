#ifndef wizyty_h
#define wizyty_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>
#include <unistd.h>
#define sleep(x) Sleep(20 * (x))

#define ROZMIAR 50

/// Struktura pozwalajaca na wprowadzanie i przechowywanie danych zwiazanych z wizytami pacjentow.
struct wizyty{

    int id; /// Zmienna typu int, zawierajaca ID danej wizyty.
    int id_pacjenta; /// Zmienna typu int, zawierajaca ID pacjenta.
    int id_lekarza; /// Zmienna typu int, zawierajaca ID lekarza.
    int dzien; /// Zmienna typu int, zawierajaca dzien odbycia danej wizyty.
    int miesiac; /// Zmienna typu int, zawierajaca miesiac odbycia danej wizyty.
    int rok; /// Zmienna typu int, zawierajaca rok odbycia danej wizyty.
    int godzina; /// Zmienna typu int, zawierajaca godzine odbycia danej wizyty.
    int minuta; /// Zmienna typu int, zawierajaca minute odbycia danej wizyty.
    int czas_trwania; /// Zmienna typu int, zawierajaca czas trwania danej wizyty.
    int godzina_zakonczenia_wizyty; /// Zmienna typu int, zawierajaca godzine zakonczenia danej wizyty.
    int minuta_zakonczenia_wizyty; /// Zmienna typu int, okreslajaca minute zakonczenia danej wizyty.
    char status_wizyty[ROZMIAR]; /// Zmienna typu char, okreslajaca status danej wizyty.


    struct wizyty *poprzedni2, *nastepny2; /// Wskazniki pozwalajace na poruszanie sie w obie strony po 2-kierunkowej liscie wizyt.
};

/// Wskazniki pozwalajace na poruszanie sie po elementach 2-kierunkowej listy wizyt.
struct wizyty *dodaj_wpis2;
struct wizyty *poczatek2;
struct wizyty *koniec2;

/// Deklaracje funkcji uzywanych w naszym programie. Opis kazdej z nich jest zawarty w plikach z rozszerzeniem '.c' programu.
int nowa_wizyta(int id, int id1, int id2, int rok, int miesiac, int dzien, int godzina, int minuta);
void wczytaj_wizyty(char* nazwa_pliku);
void zapisz_do_pliku_wizyty(char* nazwa_pliku);
void pokaz_wizyty_ograniczone();
int pokaz_wizyty();
int edycja_wizyt(int id2, int rok, int miesiac, int dzien, int godzina, int minuta);
int wyswietl_wizyty_po_id1();
void pokaz_wizyty_pacjenta(int id);
void pokaz_wizyty_lekarza(int id1);
int wyswietl_wizyty_po_id();
void zmiana_statusu(int rok, int miesiac, int dzien, int godzina, int minuta);


#endif
