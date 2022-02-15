/**
\mainpage
<center>
<h2><b>Politechnika Świętokrzyska w Kielcach</b></h2>
<h3>Wydział Elektrotechniki, Automatyki i Informatyki</h3>
<br>
<h2>Tematem naszego projektu jest Przychodnia lekarska.</h2>
<p><u>Oto przykładowe screeny z działania naszego programu:</u></p>
<p>Menu glowne:</p>
\image html menu_glowne.png
<br><p> Pokazanie danych Lekarzy (przed sortowaniem i po - wg. nazwiska):</p>
\image html posort_lekarze_przed.png
<br><br>
\image html posort_lekarze_po.png

<br>
<p>Przebieg edycji danych w wizycie:</p>
\image html edit1.png

<br>
<p>

</center>

<h4><b>Projekt wykonali: </b> Dominik Łataś, Piotr Wojtasiński oraz Paweł Zacharz (1ID16A).</h4>
*/


#include "pacjenci.h"
#include "lekarze.h"
#include "wizyty.h"

int odczyt_dni(int rok, int miesiac, int dzien);


/// Funkcja glowna main() naszego programu.
int main(void){

    /// Zmienne wskaznikowe
    struct pacjenci *lista = NULL;
    struct lekarze *lista1 = NULL;
    struct pacjenci *lista3 = NULL;
    struct pacjenci *tmp = (struct pacjenci *)malloc(sizeof(struct pacjenci));


    SYSTEMTIME st;
    GetLocalTime(&st);

    /// Zmienne pozwalajace na pobieranie wartosci aktualnej daty i godziny.
    int dzien = st.wDay;
    int miesiac = st.wMonth;
    int rok = st.wYear;
    int godzina = st.wHour;
    int minuta = st.wMinute;


    if(dzien < 10){
        printf("0%d.", dzien);
    }
    else{
        printf("%d.", dzien);
    }

    if(miesiac < 10){
        printf("0%d.", miesiac);
    }
    else{
        printf("%d.", miesiac);
    }
    printf("%d", rok);


    if(godzina < 10){
        printf("\nGodzina 0%d:", godzina);
    }
    else{
        printf("\nGodzina %d:", godzina);
    }

    if(minuta < 10){
        printf("0%d", minuta);
    }
    else{
        printf("%d\n", minuta);
    }

    /// Funkcje pobierajace date oraz wczytujace 'baze danych' z plikow tekstowych.
    printf("\nDzis jest ");
    odczyt_dni(rok, miesiac, dzien);
    printf("\n");
    wczytaj_pacjentow("Baza_Przychodnia_Pacjenci.txt");
    wczytaj_lekarzy("Baza_Przychodnia_Lekarze.txt");
    wczytaj_wizyty("Baza_Rejestracja.txt");
    zmiana_statusu(rok, miesiac, dzien, godzina, minuta);
    zapisz_do_pliku_wizyty("Baza_Rejestracja.txt");

    int a,b, id, id1, id2; /// Zmienne pozwalajace na: 'a' i 'b' - poruszanie sie po menu glownym; id, 'id1' i 'id2' - odpowiadaja za ID pacjenta, lekarza oraz wizyty (zwiekszane lub zmniejszane stosownie do posiadanaj wartosci ID)ę wyro.

    if(koniec != NULL){
        id=koniec->id;
        id+=1;
    }
    else{
        id=1;
    }

    if(koniec1 != NULL){
        id1=koniec1->id;
        id1+=1;
    }
    else{
        id1=1;
    }

    if(koniec2 != NULL){
        id2=koniec2->id;
        id2+=1;
    }
    else{
        id2=1;
    }

    /// Petla while(), dzieki ktorej mozemy korzystac z naszego menu tak dlugo, jak tego potrzebujemy.
    while(1){

        printf("==============================================================================================================================\n");
        printf("\t\t\t\t\t\t      PRZYCHODNIA\n");
        printf("==============================================================================================================================\n");
        printf("\n1. FUNKCJE DLA PACJENTOW.\n");
        printf("2. FUNKCJE DLA LEKARZY.\n");
        printf("3. FUNKCJE DLA WIZYT.\n\n");
        printf("0. WYJSCIE\n");
        scanf("%d",&a);

        if(a==1){

            system("cls");
            printf("==============================================================================================================================\n");
            printf("\t\t\t\t\t\t      PRZYCHODNIA\n");
            printf("==============================================================================================================================\n");
            printf("\n1. DODAJ PACJENTA.\n");
            printf("2. WYSWIETL LISTE PACJENTOW.\n");
            printf("3. USUN PACJENTA Z LISTY.\n");
            printf("4. EDYTUJ DANE PACJENTA.\n");
            printf("5. WYSZUKAJ PACJENTA.\n");
            printf("6. SORTOWANIE PO WYBRANYM POLU.\n\n");
            printf("7. MENU GLOWNE.\n");
            printf("0. WYJSCIE\n");
            scanf("%d",&b);

            switch(b){

                case 1:
                    nowy_pacjent(id);
                    id++;
                    zapisz_do_pliku_pacjentow("Baza_Przychodnia_Pacjenci.txt");
                    system("cls");
                    break;
                case 2:
                    pokaz_pacjentow(tmp);
                    break;
                case 3:
                    usuwanie_pacjentow(lista3);
                    zapisz_do_pliku_pacjentow("Baza_Przychodnia_Pacjenci.txt");
                    break;
                case 4:
                    system("cls");
                    edycja_pacjentow();
                    zapisz_do_pliku_pacjentow("Baza_Przychodnia_Pacjenci.txt");
                    break;
                case 5:
                    system("cls");
                    menu_wyszukiwania_pacjentow();
                    break;
                case 6:
                    menu_sortowania_pacjentow(lista);
                    break;
                case 7:
                    system("cls");
                    break;
                case 0:
                    system("cls");
                    printf("==============================================================================================================================\n");
                    printf("\n\t\t\t\t\t     DZIEKUJEMY ZA SKORZYSTANIE Z PROGRAMU!\n\n");
                    printf("==============================================================================================================================\n");
                    exit(0);
                default:
                    system("cls");
                    printf("Wybierz prawidlowy numer!\n\n");
                    break;
            }
        }

        else if(a==2){

            system("cls");
            printf("==============================================================================================================================\n");
            printf("\t\t\t\t\t\t      PRZYCHODNIA\n");
            printf("==============================================================================================================================\n");
            printf("1. DODAJ LEKARZA.\n");
            printf("2. WYSWIETL LISTE LEKARZY.\n");
            printf("3. USUN LEKARZA Z LISTY.\n");
            printf("4. EDYTUJ DANE LEKARZA.\n\n");
            printf("5. WYSZUKAJ LEKARZA.\n");
            printf("6. SORTOWANIE PO WYBRANYM POLU.\n\n");
            printf("7. MENU GLOWNE.\n");
            printf("0. WYJSCIE\n");
            scanf("%d",&b);

            switch(b){

                 case 1:
                    nowy_lekarz(id1);
                    id1++;
                    zapisz_do_pliku_lekarzy("Baza_Przychodnia_Lekarze.txt");
                    system("cls");
                    break;
                case 2:
                    pokaz_lekarzy();
                    break;
                case 3:
                    usuwanie_lekarzy(lista1);
                    zapisz_do_pliku_lekarzy("Baza_Przychodnia_Lekarze.txt");
                    break;
                case 4:
                    system("cls");
                    edycja_lekarzy();
                    zapisz_do_pliku_lekarzy("Baza_Przychodnia_Lekarze.txt");
                    break;
                case 5:
                    system("cls");
                    menu_wyszukiwania_lekarzy();
                    break;
                case 6:
                    menu_sortowania_lekarzy(lista1);
                    break;
                case 7:
                    system("cls");
                    break;
                case 0:
                   system("cls");
                    printf("==============================================================================================================================\n");
                    printf("\n\t\t\t\t\t     DZIEKUJEMY ZA SKORZYSTANIE Z PROGRAMU!\n\n");
                    printf("==============================================================================================================================\n");
                    exit(0);
                default:
                    system("cls");
                    printf("Wybierz prawidlowy numer!\n\n");
                    break;
            }
        }

        else if(a==3){

            system("cls");
            printf("==============================================================================================================================\n");
            printf("\t\t\t\t\t\t      PRZYCHODNIA\n");
            printf("==============================================================================================================================\n");
            printf("1. ZAREJESTRUJ PACJENTA NA WIZYTE.\n");
            printf("2. WYSWIETL WIZYTY DANEGO PACJENTA.\n");
            printf("3. WYSWIETL WIZYTY DANEGO LEKARZA.\n");
            printf("4. WYSWIETL WSZYSTKIE WIZYTY.\n");
            printf("5. EDYTUJ DANE WIZYTY. \n");
            scanf("%d",&b);

            switch(b){

                case 1:
                    system("cls");
                    nowa_wizyta(id, id1, id2, rok, miesiac, dzien, godzina, minuta);
                    id2++;
                    zapisz_do_pliku_wizyty("Baza_Rejestracja.txt");
                    break;
                case 2:
                    system("cls");
                    pokaz_wizyty_pacjenta(id);
                    break;
                case 3:
                    system("cls");
                    pokaz_wizyty_lekarza(id1);
                    break;
                case 4:
                    pokaz_wizyty_ograniczone();
                    break;
                case 5:
                    system("cls");
                    edycja_wizyt(id2, rok, miesiac, dzien, godzina, minuta);
                    zapisz_do_pliku_wizyty("Baza_Rejestracja.txt");
                    break;
                default:
                    system("cls");
                    printf("Wybierz prawidlowy numer!\n\n");
                    break;
            }
        }

        else if(a==0){

            system("cls");
            printf("==============================================================================================================================\n");
            printf("\n\t\t\t\t\t     DZIEKUJEMY ZA SKORZYSTANIE Z PROGRAMU!\n\n");
            printf("==============================================================================================================================\n");
            exit(0);
        }

        else while(a>3){

            system("cls");
            printf("Wybierz prawidlowy numer!\n\n");
            main();
        }
    }
}

/// Funkcja odpowiedzialna za odczyt dokladnych dat; jesli data jest nieprawidlowo podana, wystapi blad.\image html data.png
int odczyt_dni(int rok, int miesiac, int dzien){

    int liczba_dni_miesiaca[]={31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; /// Tablica liczb typu int, przechowujaca dlugosc poszczegolnych miesiecy.
    char *nazwa_dnia[]={"Niedziela", "Poniedzialek", "Wtorek", "Sroda", "Czwartek", "Piatek", "Sobota"}; /// Tablica znakow, przechowujaca nazwy dni tygodnia.
    int i;


    if (rok % 4 == 0 && (rok % 100 != 0 || rok % 400 == 0))
        liczba_dni_miesiaca[1] = 29;

    if (rok < 1900 || miesiac < 1 || miesiac > 12 || dzien < 1 || dzien > liczba_dni_miesiaca[miesiac - 1]) {
        printf("Podano zla date!.\n");
        return 0;
    }

    for (i = 1900; i < rok; i++)
        if (i % 4 == 0 && (i % 100 != 0 || i % 400 == 0))
            dzien += 366;
        else
            dzien += 365;

    for (i = 0; i < miesiac - 1; i++)
        dzien += liczba_dni_miesiaca[i];

    printf("%s", nazwa_dnia[dzien% 7]);

    return 0;
}


