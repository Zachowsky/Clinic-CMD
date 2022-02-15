#include "pacjenci.h"
#include "lekarze.h"
#include "wizyty.h"


struct wizyty *poczatek2 = NULL;
struct wizyty *koniec2 = NULL;

/// Funkcja odpowiedzialna za inicjowanie nowej wizyty; jest rekurencyjna i jako parametry pobiera ID pacjenta, lekarza i wizyty oraz dokladny czas planowania takiej wizyty; pozwala ona na dokladne ustalenie szczegolow wizyty pacjenta u wybranego lekarza; funkcja posaida szereg zabezpieczen przed niewlasciwymi danymi.\image html nwiz.png
int nowa_wizyta(int id, int id1, int id2, int rok, int miesiac, int dzien, int godzina, int minuta){

    struct pacjenci *tmp; /// Wskaznik struktury 'pacjenci', niezbedny do zainicjowania nowej wizyty; odpowiada za przechowywanie wskaznika do poczatku listy pacjentow.
    tmp = poczatek; /// Przypisanie do wskaznika 'tmp' wartosci wskaznika 'poczatek'.

    struct lekarze *temp; /// Zmienna tymczasowa, przechowujaca wskaznik na poczatek listy lekarzy.
    temp = poczatek1;

    struct wizyty *teemp; /// Zmienna tymczasowa, przechowujaca wskaznik na poczatek listy wizyt.
    teemp = poczatek2;

    int z;
    int odczyt_dni(); /// Inicjacja funkcji zwracajacej wartosc typu int; odpowiada ona za pozniej zadeklarowany odczyt dni.

    if(tmp == NULL){
            system("cls");
            printf("Baza pacjentow jest pusta !!\n\n");
            return 0;
        }

        if(temp == NULL){
            system("cls");
            printf("Baza lekarzy jest pusta !!\n\n");
            return 0;
        }
 dodaj_wpis2 = malloc(sizeof (struct wizyty)); /// Alokacja bloku pamieci dla wskaznika, ktory posluzy do przechowywania danych zwiazanych z wizytami.

    if(!dodaj_wpis2){
        printf("Nie dziala.");
        perror("malloc");
        return EXIT_FAILURE;
    }

    if (dodaj_wpis2!=NULL){


        dodaj_wpis2->id = id2;

        printf("Podaj ID pacjenta: ");
        scanf("%d",&dodaj_wpis2->id_pacjenta);

        while(dodaj_wpis2 != NULL){

                while(dodaj_wpis2->id_pacjenta >= id || dodaj_wpis2->id_pacjenta == 0){

                        system("cls");
                        printf("Podane ID jest zle, podaj prawidlowe: ");
                        scanf("%d",&dodaj_wpis2->id_pacjenta);

                }

                    while(tmp->id != dodaj_wpis2->id_pacjenta){
                        if(tmp->id == dodaj_wpis2->id_pacjenta){
                            tmp = tmp;
                        }
                        else while(tmp->id != dodaj_wpis2->id_pacjenta){
                            tmp = tmp->nastepny;
                            if(tmp->id == dodaj_wpis2->id_pacjenta){
                            tmp = tmp;
                        }
                        break;
                        }
                        if(koniec->id == tmp->id && tmp->id != dodaj_wpis2->id_pacjenta) {
                            printf("Nie ma pacjenta o podanym ID, podaj inne: ");
                            scanf("%d",&dodaj_wpis2->id_pacjenta);
                            tmp = poczatek;
                        }
                    }

                    if(dodaj_wpis2->id_pacjenta == tmp->id){

                    printf("\n*****************************************************************************************************************************");
                    printf("\nNumer ID pacjenta: \t\t%d",dodaj_wpis2->id_pacjenta);
                    printf("\nImie i nazwisko pacjenta: \t%s %s", tmp->imie,tmp->nazwisko);

                    printf("\n\nCzy tego pacjenta chcesz umowic na wizyte? \n[1]Tak.\n[2]Nie.\n");
                    scanf("%d", &z);
                    if(z==1){
                        break;
                    }
                    else if(z==2){
                        system("cls");
                        printf("Podaj ID pacjenta: ");
                        scanf("%d",&dodaj_wpis2->id_pacjenta);
                        tmp = poczatek;
                    }
                    else while(z==0 || z>2){
                        printf("Wybierz poprawny numer!\n[1]Tak.\n[2]Nie.");
                        scanf("%d", &z);
                    }
                }
        }


        printf("\nPodaj ID lekarza: \n");
        scanf("%d",&dodaj_wpis2->id_lekarza);

        while(dodaj_wpis2 != NULL){

                while(dodaj_wpis2->id_lekarza >= id1 || dodaj_wpis2->id_lekarza == 0){

                        system("cls");
                        printf("Podane ID jest zle, podaj prawidlowe: ");
                        scanf("%d",&dodaj_wpis2->id_lekarza);

                }

                    while(temp->id != dodaj_wpis2->id_lekarza){
                        if(temp->id == dodaj_wpis2->id_lekarza){
                            temp = temp;
                        }
                        else while(temp->id != dodaj_wpis2->id_lekarza){
                            temp = temp->nastepny1;
                            if(temp->id == dodaj_wpis2->id_lekarza){
                            temp = temp;
                        }
                        break;
                        }
                        if(koniec->id == temp->id && temp->id != dodaj_wpis2->id_lekarza) {
                            printf("Nie ma lekarza o podanym ID, podaj inne: ");
                            scanf("%d",&dodaj_wpis2->id_lekarza);
                            temp = poczatek1;
                        }
                    }

                    if(dodaj_wpis2->id_lekarza == temp->id){

                    printf("\n*****************************************************************************************************************************");
                    printf("\nNumer ID lekarza: \t\t%d",dodaj_wpis2->id_lekarza);
                    printf("\nImie i nazwisko lekarza: \t%s %s", temp->imie,temp->nazwisko);
                    printf("\nDni pracy: \t\t\t");
                        if(temp->dni_pracy[0] == '1'){
                            printf("Poniedzialek,");
                        }
                        if(temp->dni_pracy[1] == '1'){
                            printf("Wtorek,");
                        }
                        if(temp->dni_pracy[2] == '1'){
                            printf("Sroda,");
                        }
                        if(temp->dni_pracy[3] == '1'){
                            printf("Czwartek,");
                        }
                        if(temp->dni_pracy[4] == '1'){
                            printf("Piatek,");
                        }
                        if(temp->dni_pracy[5] == '1'){
                            printf("Sobota,");
                        }
                        if(temp->dni_pracy[6] == '1'){
                            printf("Niedziela,");
                        }
                    printf("\nGodziny pracy lekarza: \t\t%d:00 - %d:00", temp->godzina_pocz, temp->godzina_kon);

                    printf("\n\nCzy do tego lekarza chcesz umowic  wizyte? \n[1]Tak.\n[2]Nie.\n");
                    scanf("%d", &z);
                    if(z==1){
                        break;
                    }
                    else if(z==2){
                        system("cls");
                        printf("Podaj ID lekarza: ");
                        scanf("%d",&dodaj_wpis2->id_lekarza);
                        temp = poczatek1;
                    }
                    else while(z==0 || z>2){
                        printf("Wybierz poprawny numer!\n[1]Tak.\n[2]Nie.");
                        scanf("%d", &z);
                    }
                }
        }

        printf("Podaj rok wizyty: \n");
        scanf("%d", &dodaj_wpis2->rok);

        while(dodaj_wpis2->rok < rok){
            printf("Podaj rok wizyty ponownie (nie moze byc mniejszy niz aktualny): ");
            scanf("%d", &dodaj_wpis2->rok);
        }

        printf("Podaj miesiac wizyty: \n");
        scanf("%d", &dodaj_wpis2->miesiac);

        if(dodaj_wpis2->rok == rok){
            while(dodaj_wpis2->miesiac < miesiac || dodaj_wpis2->miesiac > 12){
                printf("Podaj miesiac wizyty ponownie: ");
                scanf("%d", &dodaj_wpis2->miesiac);
            }
        }
        else if(dodaj_wpis2->rok > rok){
            dodaj_wpis2->miesiac = dodaj_wpis2->miesiac;
        }

        printf("Podaj dzien wizyty: \n");
        scanf("%d", &dodaj_wpis2->dzien);

        if(dodaj_wpis2->rok == rok){
            if(dodaj_wpis2->miesiac == miesiac){
                while(dodaj_wpis2->dzien < dzien || dodaj_wpis2->dzien > 31){
                    printf("Podaj dzien wizyty ponownie: ");
                    scanf("%d", &dodaj_wpis2->dzien);
                }
            }
            else if(dodaj_wpis2->miesiac > miesiac){
                    while(dodaj_wpis2->dzien > 31){
                    printf("Podaj dzien wizyty ponownie: ");
                    scanf("%d", &dodaj_wpis2->dzien);
                }
                dodaj_wpis2->dzien = dodaj_wpis2->dzien;
            }
        }
        else if(dodaj_wpis2->rok > rok){
                while(dodaj_wpis2->dzien > 31){
                    printf("Podaj dzien wizyty ponownie: ");
                    scanf("%d", &dodaj_wpis2->dzien);
                }
            dodaj_wpis2->dzien = dodaj_wpis2->dzien;
        }
        int da;/// Zmienna przechowujaca dzien.

        int o=1; /// Zmienna przechowujaca


        while(o>0){

            printf("\nDzien wizyty to: ");

                da = dodaj_wpis2->dzien;

                int liczba_dni_miesiaca[]={31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
                char *nazwa_dnia[]={"Niedziela", "Poniedzialek", "Wtorek", "Sroda", "Czwartek", "Piatek", "Sobota"};
                int q;
                o = 0;


                if (dodaj_wpis2->rok % 4 == 0 && (dodaj_wpis2->rok % 100 != 0 || dodaj_wpis2->rok % 400 == 0))
                    liczba_dni_miesiaca[1] = 29;

                if (dodaj_wpis2->rok < 1900 || dodaj_wpis2->miesiac < 1 || dodaj_wpis2->miesiac > 12 || da < 1 || da > liczba_dni_miesiaca[dodaj_wpis2->miesiac - 1]) {
                    printf("Podano zla date!.\n");
                    return 0;
                }

                for (q = 1900; q < dodaj_wpis2->rok; q++)
                    if (q % 4 == 0 && (q % 100 != 0 || q % 400 == 0))
                        da += 366;
                    else
                        da += 365;

                for (q = 0; q < dodaj_wpis2->miesiac - 1; q++)
                da += liczba_dni_miesiaca[q];

                printf("%s", nazwa_dnia[da% 7]);
                char dzien_wizyty[ROZMIAR];
                strcpy(dzien_wizyty, nazwa_dnia[da% 7]);

                printf("\n\n");

                    if((temp->dni_pracy[0] == '0' && strcmp(dzien_wizyty, "Poniedzialek")==0) || (temp->dni_pracy[1] == '0' && strcmp(dzien_wizyty, "Wtorek")==0) || (temp->dni_pracy[2] == '0' && strcmp(dzien_wizyty, "Sroda")==0) || (temp->dni_pracy[3] == '0' && strcmp(dzien_wizyty, "Czwartek")==0) || (temp->dni_pracy[4] == '0' && strcmp(dzien_wizyty, "Piatek")==0) || (temp->dni_pracy[5] == '0' && strcmp(dzien_wizyty, "Sobota")==0) || (temp->dni_pracy[6] == '0' && strcmp(dzien_wizyty, "Niedziela")==0)){
                        o++;
                        printf("Nie mozesz umowic wizyty na ten dzien !!");

                            printf("Podaj dzien wizyty ponownie: ");
                            scanf("%d", &dodaj_wpis2->dzien);

                        da = da;
                    }
        }


        printf("\nPodaj godzine wizyty: \n");
        scanf("%d", &dodaj_wpis2->godzina);
        while((dodaj_wpis2->godzina < temp->godzina_pocz || dodaj_wpis2->godzina >= temp->godzina_kon)){
            printf("Ten lekarz teraz nie pracuje! Podaj prawidlowa godzine!");
            scanf("%d", &dodaj_wpis2->godzina);
        }
        int i = 0;
        if(dodaj_wpis2->rok == rok){
            if(dodaj_wpis2->miesiac == miesiac){
               if(dodaj_wpis2->dzien == dzien){
                    while(dodaj_wpis2->godzina < godzina || dodaj_wpis2->godzina > temp->godzina_kon){
                        printf("Podaj godzine wizyty ponownie: ");
                        scanf("%d", &dodaj_wpis2->godzina);
                        i++;
                        if(i>5){
                            printf("Stworz wizyte ponownie z innymi danymi!!");
                            sleep(100);
                            nowa_wizyta(id, id1, id2, rok, miesiac, dzien, godzina, minuta);
                        }
                    }
                }
                    else if(dodaj_wpis2->dzien > dzien){
                        dodaj_wpis2->dzien = dodaj_wpis2->dzien;
                    }
                }
            else if(dodaj_wpis2->miesiac > miesiac){
                    dodaj_wpis2->miesiac = dodaj_wpis2->miesiac;
            }
        }
        else if(dodaj_wpis2->rok > rok){
            dodaj_wpis2->dzien = dodaj_wpis2->dzien;
        }
        while(dodaj_wpis2->godzina > 23){
            printf("Podaj prawidlowa godzine!");
            scanf("%d", &dodaj_wpis2->godzina);
        }

        printf("Podaj minute wizyty: \n");
        scanf("%d", &dodaj_wpis2->minuta);

        if(dodaj_wpis2->rok == rok){
            if(dodaj_wpis2->miesiac == miesiac){
               if(dodaj_wpis2->dzien == dzien){
                    if(dodaj_wpis2->godzina == godzina){
                        while(dodaj_wpis2->minuta < minuta){
                            printf("Podaj minute wizyty ponownie (nie moze byc mniejsza niz aktualna): ");
                            scanf("%d", &dodaj_wpis2->minuta);
                            }
                    }
                    else if(dodaj_wpis2->godzina > godzina){
                        dodaj_wpis2->godzina = dodaj_wpis2->godzina;
                    }
                }
                    else if(dodaj_wpis2->dzien > dzien){
                        dodaj_wpis2->dzien = dodaj_wpis2->dzien;
                    }
                }
            else if(dodaj_wpis2->miesiac > miesiac){
                    dodaj_wpis2->miesiac = dodaj_wpis2->miesiac;
            }
        }
        else if(dodaj_wpis2->rok > rok){
            dodaj_wpis2->dzien = dodaj_wpis2->dzien;
        }
        while(dodaj_wpis2->minuta > 59){
            printf("Podaj prawidlowa minute!");
            scanf("%d", &dodaj_wpis2->minuta);
        }




        printf("Podaj czas trwania wizyty w minutach: \n");
        scanf("%d", &dodaj_wpis2->czas_trwania);

        while(dodaj_wpis2->czas_trwania > 60){
            printf("Wizyta moze trwac maksymalnie 60 minut. Wprowadz czas trwania ponownie: ");
            scanf("%d", &dodaj_wpis2->czas_trwania);
        }

        strcpy(dodaj_wpis2->status_wizyty , "Zaplanowana");



        dodaj_wpis2->godzina_zakonczenia_wizyty = dodaj_wpis2->godzina;
        dodaj_wpis2->minuta_zakonczenia_wizyty = dodaj_wpis2->minuta;

        dodaj_wpis2->minuta_zakonczenia_wizyty = (dodaj_wpis2->minuta) + (dodaj_wpis2->czas_trwania);

        if(dodaj_wpis2->minuta_zakonczenia_wizyty >= 60){

            dodaj_wpis2->godzina_zakonczenia_wizyty += 1;
            dodaj_wpis2->minuta_zakonczenia_wizyty = (dodaj_wpis2->minuta + dodaj_wpis2->czas_trwania) - 60;
        }

        while(dodaj_wpis2->godzina_zakonczenia_wizyty > temp->godzina_kon){
            printf("\n\nLekarz nie pracuje do tej godziny. Wybierz inna !\n");
            printf("Podaj godzine wizyty: ");
            scanf("%d", &dodaj_wpis2->godzina);
            printf("Podaj minute wizyty: ");
            scanf("%d", &dodaj_wpis2->minuta);
            printf("Podaj czas trwania wizyty: ");
            scanf("%d", &dodaj_wpis2->czas_trwania);

            dodaj_wpis2->godzina_zakonczenia_wizyty = dodaj_wpis2->godzina;
            dodaj_wpis2->minuta_zakonczenia_wizyty = dodaj_wpis2->minuta;

            dodaj_wpis2->minuta_zakonczenia_wizyty = (dodaj_wpis2->minuta) + (dodaj_wpis2->czas_trwania);

            if(dodaj_wpis2->minuta_zakonczenia_wizyty >= 60){

                dodaj_wpis2->godzina_zakonczenia_wizyty += 1;
                dodaj_wpis2->minuta_zakonczenia_wizyty = (dodaj_wpis2->minuta + dodaj_wpis2->czas_trwania) - 60;
            }
        }

        teemp = poczatek2;
            int t;
            while(teemp != NULL){
                 if(dodaj_wpis2->rok == teemp->rok && dodaj_wpis2->id_lekarza == teemp->id_lekarza){
                    if(dodaj_wpis2->miesiac == teemp->miesiac){
                       if(dodaj_wpis2->dzien == teemp->dzien){
                            if((dodaj_wpis2->godzina == teemp->godzina) || (dodaj_wpis2->godzina < teemp->godzina && dodaj_wpis2->godzina_zakonczenia_wizyty == teemp->godzina && dodaj_wpis2->minuta_zakonczenia_wizyty > teemp->minuta) || (dodaj_wpis2->godzina == teemp->godzina && dodaj_wpis2->godzina_zakonczenia_wizyty > teemp->godzina_zakonczenia_wizyty && dodaj_wpis2->minuta < teemp->minuta)){
                                if((dodaj_wpis2->minuta >= teemp->minuta && dodaj_wpis2->minuta_zakonczenia_wizyty<teemp->minuta_zakonczenia_wizyty) || (dodaj_wpis2->minuta <= teemp->minuta && dodaj_wpis2->minuta_zakonczenia_wizyty>teemp->minuta)){
                                    for( t=0; t<=1; t++){
                                        printf("Wybrany lekarz ma juz wtedy wizyte, zacznij od nowa!!\n\n");
                                        nowa_wizyta(id, id1, id2, rok, miesiac, dzien, godzina, minuta);
                                        return 0;
                                    }
                                }
                                else{
                                    break;
                                }
                            }
                            else{
                                break;
                            }
                        }
                        else{
                            break;
                        }
                    }
                    else{
                        break;
                    }
                }
                else{
                    teemp = teemp->nastepny2;
                }
            }
            teemp = poczatek2;
            int f;
            while(teemp != NULL){
                 if(dodaj_wpis2->rok == teemp->rok && dodaj_wpis2->id_pacjenta == teemp->id_pacjenta){
                    if(dodaj_wpis2->miesiac == teemp->miesiac){
                       if(dodaj_wpis2->dzien == teemp->dzien){
                            if((dodaj_wpis2->godzina == teemp->godzina) || (dodaj_wpis2->godzina < teemp->godzina && dodaj_wpis2->godzina_zakonczenia_wizyty == teemp->godzina && dodaj_wpis2->minuta_zakonczenia_wizyty > teemp->minuta) || (dodaj_wpis2->godzina == teemp->godzina && dodaj_wpis2->godzina_zakonczenia_wizyty > teemp->godzina_zakonczenia_wizyty && dodaj_wpis2->minuta < teemp->minuta)){
                                if((dodaj_wpis2->minuta >= teemp->minuta && dodaj_wpis2->minuta_zakonczenia_wizyty<teemp->minuta_zakonczenia_wizyty) || (dodaj_wpis2->minuta <= teemp->minuta && dodaj_wpis2->minuta_zakonczenia_wizyty>teemp->minuta)){
                                    for( f=0; f<=1; f++){
                                        printf("Wybrany pacjent ma juz wtedy wizyte, zacznij od nowa!!\n\n");
                                        nowa_wizyta(id, id1, id2, rok, miesiac, dzien, godzina, minuta);
                                        return 0;
                                    }
                                }
                                else{
                                    break;
                                }
                            }
                            else{
                                break;
                            }
                        }
                        else{
                            break;
                        }
                    }
                    else{
                        break;
                    }
                }
                else{
                    teemp = teemp->nastepny2;
                }
            }



        }
        dodaj_wpis2 -> nastepny2 = NULL;

        if(koniec2 == NULL){
            poczatek2 = koniec2 = dodaj_wpis2;
          }

        else{
            koniec2->nastepny2 = dodaj_wpis2;
            koniec2 = dodaj_wpis2;
        }

            int n;
            printf("\n\nCzy chcesz umowic kolejna wizyte?\n[1]Tak.\n[2]Nie.");
            scanf("%d", &n);
            if(n==1){
                id2++;
                nowa_wizyta(id, id1, id2, rok, miesiac, dzien, godzina, minuta);
            }
            else if(n==2){
                return 0;
            }
            else while( n == 0 || n > 2){
                printf("Wybierz poprawny numer!\n[1]Tak.\n[2]Nie.");
                scanf("%d", &n);
            }
return 0;
}

/// Funkcja wczytujaca wizyty z pliku "Baza_Rejestracja.txt"; dziala analogicznie do 2 poprzednich funkcji, wczytujacych dane z pliku.\image html kod3.png
void wczytaj_wizyty(char* nazwa_pliku) {

    FILE *wppp;
    wppp = fopen(nazwa_pliku, "r");


    if (wppp != NULL){


        if((feof(wppp)==0) && (fgetc(wppp)<2)){


            fclose(wppp);
            remove(nazwa_pliku);
          }


        else{

            while(feof(wppp) == 0){
              dodaj_wpis2 = malloc(sizeof (struct wizyty));

              fscanf(wppp, "%d", &dodaj_wpis2->id);
              fscanf(wppp, "%d", &dodaj_wpis2->id_pacjenta);
              fscanf(wppp, "%d", &dodaj_wpis2->id_lekarza);
              fscanf(wppp, "%d", &dodaj_wpis2->rok);
              fscanf(wppp, "%d", &dodaj_wpis2->miesiac);
              fscanf(wppp, "%d", &dodaj_wpis2->dzien);
              fscanf(wppp, "%d", &dodaj_wpis2->godzina);
              fscanf(wppp, "%d", &dodaj_wpis2->minuta);
              fscanf(wppp, "%d", &dodaj_wpis2->czas_trwania);
              fscanf(wppp, "%d", &dodaj_wpis2->godzina_zakonczenia_wizyty);
              fscanf(wppp, "%d", &dodaj_wpis2->minuta_zakonczenia_wizyty);
              fscanf(wppp, "%s", dodaj_wpis2->status_wizyty);

              dodaj_wpis2 -> nastepny2 = NULL;

              if (koniec2 != NULL){

                    koniec2->nastepny2 = dodaj_wpis2;
                    koniec2 = dodaj_wpis2;
              }

              else{
                    koniec2 = poczatek2 = dodaj_wpis2;
                }
            }
        }
            fclose(wppp);
    }
}

///Funkcja zapisujaca wszystkie wizyty do pliku tekstowego, dzialajaca analogicznie do wczesniejszych funkcji, zapisujacych dane do pliku.\image html image1.png
void zapisz_do_pliku_wizyty(char* nazwa_pliku){

    FILE* wppp;
    wppp = fopen(nazwa_pliku, "w");

    dodaj_wpis2 = poczatek2;

        while(dodaj_wpis2 != NULL) {

            fprintf(wppp, "\n\n");
            fprintf(wppp, "%d\n", dodaj_wpis2->id);
            fprintf(wppp, "%d\n", dodaj_wpis2->id_pacjenta);
            fprintf(wppp, "%d\n", dodaj_wpis2->id_lekarza);
            fprintf(wppp, "%d\n", dodaj_wpis2->rok);
            fprintf(wppp, "%d\n", dodaj_wpis2->miesiac);
            fprintf(wppp, "%d\n", dodaj_wpis2->dzien);
            fprintf(wppp, "%d\n", dodaj_wpis2->godzina);
            fprintf(wppp, "%d\n", dodaj_wpis2->minuta);
            fprintf(wppp, "%d\n", dodaj_wpis2->czas_trwania);
            fprintf(wppp, "%d\n", dodaj_wpis2->godzina_zakonczenia_wizyty);
            fprintf(wppp, "%d\n", dodaj_wpis2->minuta_zakonczenia_wizyty);
            fprintf(wppp, "%s", dodaj_wpis2->status_wizyty);
            dodaj_wpis2 = dodaj_wpis2 -> nastepny2;

        }
    fclose(wppp);
}

/// Funkcja pokazuje wizyty, jednak w sposob ograniczony.\image html ogr2.png
void pokaz_wizyty_ograniczone(){

    if(poczatek2 == NULL){
            system("cls");
            printf("Baza danych jest pusta !!\n\n");
            return ;
        }

    system("cls");

    char odbyta[] = "Odbyta"; /// Tablica przechowujaca slowo "Odbyta" - niezbedne do pozniejszego ustalania wizyt w programie.
    char zaplanowana[] = "Zaplanowana"; /// Tablica przechowujaca slowo "Zaplanowana" - niezbedne do pozniejszego ustalania wizyt w programie.
    char odwolana[] = "Odwolana"; /// Tablica przechowujaca slowo "Odwolana" - niezbedne do pozniejszego ustalania wizyt w programie.

    int rok, miesiac, dzien; /// Zmienne przechowujace rok, miesiac i dzien.
    int pokaz_wizyty(); /// Inicjacja funkcji 'pokaz_wizyty()'.
    int wyswietl_wizyty_po_id1(); /// Inicjacja pozniej utworzonej funkcji 'wyswietl_wizyty_po_id1()'.
    int i = 0; /// Zmienna potrzebna do wykonywania pêtli sprawdzaj¹cej, czy mozna umowic sie na wizyte danego dnia.


    printf("Czy chcesz ograniczyc wyniki wyszukiwania do konkretnego statusu lub dnia?\n[1]Tak - status.\n[2]Tak - dzien.\n[3]Nie.\n");
    int wybor; /// Zmienna ta pozwala na wybor, czy chcemy ograniczyc wyniki wyszukiwania do konkretnego statusu lub dnia, czy tez nie.
    scanf("%d", &wybor);

    if(wybor == 1){
        printf("\nDo jakiego statusu chcesz ograniczyc?\n[1]Wizyta odbyta.\n[2]Wizyta zaplanowana.\n[3]Wizyta odwolana.\n");
        int status; /// Zmienna pozwalajaca na wybor, czy dana wizyta ma byc odbyta, zaplanowana, czy tez odwolana.
        scanf("%d", &status);


            if(status == 1){
                dodaj_wpis2 = poczatek2;

                while(dodaj_wpis2 != NULL){

                        if(stricmp(dodaj_wpis2->status_wizyty, odbyta)==0){
                            wyswietl_wizyty_po_id1();
                            dodaj_wpis2 = dodaj_wpis2->nastepny2;
                            i++;
                        }
                        else{
                            dodaj_wpis2 = dodaj_wpis2->nastepny2;
                        }
                    }
                }


            if(status == 2){
                dodaj_wpis2 = poczatek2;

                while(dodaj_wpis2 != NULL){

                        if(stricmp(dodaj_wpis2->status_wizyty, zaplanowana)==0){
                            wyswietl_wizyty_po_id1();
                            dodaj_wpis2 = dodaj_wpis2->nastepny2;
                            i++;
                        }
                        else{
                            dodaj_wpis2 = dodaj_wpis2->nastepny2;
                        }
                    }
                }



            if(status == 3){
                dodaj_wpis2 = poczatek2;

                while(dodaj_wpis2 != NULL){

                        if(stricmp(dodaj_wpis2->status_wizyty, odwolana)==0){
                            wyswietl_wizyty_po_id1();
                            dodaj_wpis2 = dodaj_wpis2->nastepny2;
                            i++;
                        }
                        else{
                            dodaj_wpis2 = dodaj_wpis2->nastepny2;
                        }
                    }
                }
    }


    if(wybor == 2){
        printf("\nDo jakiego dnia chcesz ograniczyc?\n");
        printf("Podaj rok wizyty: ");
        scanf("%d", &rok);
        printf("Podaj miesiac wizyty: ");
        scanf("%d", &miesiac);
        printf("Podaj dzien wizyty: ");
        scanf("%d", &dzien);

        dodaj_wpis2 = poczatek2;

        while(dodaj_wpis2!= NULL){

            if(dodaj_wpis2->rok == rok && dodaj_wpis2->miesiac == miesiac && dodaj_wpis2->dzien == dzien){

                i++;
                wyswietl_wizyty_po_id1(dodaj_wpis2);
                dodaj_wpis2 = dodaj_wpis2->nastepny2;
            }
            else{
                dodaj_wpis2 = dodaj_wpis2->nastepny2;
            }
        }
    }


    else if (wybor==3){
        dodaj_wpis2 = poczatek2;
        pokaz_wizyty(dodaj_wpis2);
        i++;
    }

    if(i==0){
            printf("Brak tak spersonalizowanych wizyt!!\n");
        }

    int n; /// Zmienna pozwalajaca okreslic, czy chcemy wyszukiwac kolejna wizyte.
            printf("\n\nCzy chcesz wyszukac kolejna wizyte?\n[1]Tak.\n[2]Nie.");
            scanf("%d", &n);
            if(n==1){
                pokaz_wizyty_ograniczone();
            }
            else if(n==2){
                return ;
            }
            else while( n == 0 || n > 2){
                printf("Wybierz poprawny numer!\n[1]Tak.\n[2]Nie.");
                scanf("%d", &n);
            }
return ;
}

/// Funkcja wyswietlajaca wszystkie zainicjowane wizyty na ekranie; obejmuje wszystkie wizyty wraz ze szczegolami; pobiera niezbedne dane ze struktur z pacjentami i lekarzami.\image html pwiz.png
int pokaz_wizyty(){

    system("cls");

    if(poczatek2 == NULL){
            system("cls");
            printf("Baza danych jest pusta !!\n\n");
            return 0;
        }
        int odczyt_dni();

    struct pacjenci *tmp; /// Zmienne wskaznikowe ('*tmp' i '*temp') pozwalajace na sprawne operowanie na danych pacjentow oraz lekarzy.
    tmp = poczatek;

    struct lekarze *temp;
    temp = poczatek1;

        if(poczatek2 != NULL){
                dodaj_wpis2 = poczatek2;
        }

            else{
                dodaj_wpis2 = NULL;
            }



                if(dodaj_wpis2 == NULL){
                    printf("\nBaza pacjentow jest pusta!!.\n\n");
                }

                    else  while(dodaj_wpis2 != NULL){

                            while(tmp->id != dodaj_wpis2->id_pacjenta){
                                if(tmp->id == dodaj_wpis2->id_pacjenta){
                                    tmp = tmp;
                                }
                                else{
                                    tmp = tmp->nastepny;
                                }
                            }

                            while(temp->id != dodaj_wpis2->id_lekarza){
                                if(temp->id == dodaj_wpis2->id_lekarza){
                                    temp = temp;
                                }
                                else{
                                    temp = temp->nastepny1;
                                }
                            }

                            if(dodaj_wpis2->id_pacjenta == tmp->id && dodaj_wpis2->id_lekarza == temp->id){

                            printf("\n*****************************************************************************************************************************");
                            printf("\nNumer ID wizyty: \t\t%d",dodaj_wpis2->id);
                            printf("\nNumer ID pacjenta: \t\t%d",dodaj_wpis2->id_pacjenta);
                            printf("\nImie i nazwisko pacjenta: \t%s %s", tmp->imie,tmp->nazwisko);
                            printf("\nNumer ID lekarza: \t\t%d",dodaj_wpis2->id_lekarza);
                            printf("\nImie i nazwisko lekarza: \t%s %s", temp->imie,temp->nazwisko);
                            printf("\nGodziny pracy lekarza: \t\t%d:00-%d:00", temp->godzina_pocz, temp->godzina_kon);
                            printf("\nData wizyty: \t\t\t%d.%d.%d", dodaj_wpis2->dzien, dodaj_wpis2->miesiac, dodaj_wpis2->rok);
                            printf("\nDzien wizyty to: \t\t");
                            odczyt_dni(dodaj_wpis2->rok, dodaj_wpis2->miesiac, dodaj_wpis2->dzien);
                            printf("\nGodzina wizyty: \t\t%d:%d", dodaj_wpis2->godzina, dodaj_wpis2->minuta);
                            printf("\nCzas trwania wizyty: \t\t%d", dodaj_wpis2->czas_trwania);
                            printf("\nGodzina zakonczenia wizyty: \t%d:%d", dodaj_wpis2->godzina_zakonczenia_wizyty, dodaj_wpis2->minuta_zakonczenia_wizyty);
                            printf("\nStatus wizyty: \t\t\t%s\n", dodaj_wpis2->status_wizyty);
                            dodaj_wpis2 = dodaj_wpis2 -> nastepny2;
                            temp=poczatek1;
                            tmp=poczatek;
                        }
                    }
                    return 0;
}

/// Funkcja pozwalajaca na szczegolowa edycje danych zawartych w wizytach; pozwala na odwolanie lub zmiane terminu wizyty wraz z doborem wszystkich szczegolowych parametrow (zwiazanych z czasem trwania wizyty, jej poczatkiem, koncem etc).\image html ewiz.png
int edycja_wizyt(int id2, int rok, int miesiac, int dzien, int godzina, int minuta){

    struct pacjenci *tmp; /// Zmienne wskaznikowe ('*tmp', '*temp' i '*teemp'), pozwalajace na sprawne operowanie na danych pacjentow oraz lekarzy.
    tmp = poczatek;

    struct lekarze *temp;
    temp = poczatek1;

    struct wizyty *teemp;
    teemp = poczatek2;

    system("cls");

    if(poczatek2 == NULL){
            system("cls");
            printf("Baza danych jest pusta !!\n\n");
            return 0;
        }

    int wyswietl_wizyty_po_id1(); /// Inicjacja funkcji 'wyswietl_wizyty_po_id1()', zwracajacej wartosc typu int.
    int odczyt_dni(); /// Inicjacja funkcji 'odczyt_dni()', zwracajacej wartosc typu int.
    int id_szukane; /// Zmienna przechowujaca ID, wedlug ktorego potem bedziemy edytowac wybrane pola.
    int b;
    int i = 0; /// Zmienna niezbedna do wykonywania pêtli sprawdzaj¹cej, czy mozna umowic sie na wizyte danego dnia.
    printf("Podaj ID wizyty, ktorej dane chcesz edytowac: ");
    scanf("%d", &id_szukane);

    dodaj_wpis2 = poczatek2;

    int z = 0; /// Zmienna niezbedna do wykonywania pêtli sprawdzaj¹cej, czy mozna umowic sie na wizyte danego dnia.
            dodaj_wpis2 = poczatek2;
            while(dodaj_wpis2 != NULL){

                    if(dodaj_wpis2->id == id_szukane){
                        dodaj_wpis2 = dodaj_wpis2->nastepny2;
                        z++;

                    }

                    else {
                        dodaj_wpis2 = dodaj_wpis2->nastepny2;
                    }
                }
            if(z<1){
                printf("Nie ma wizyty o podanym ID!!\n\n");
                edycja_wizyt(id2, rok, miesiac, dzien, godzina, minuta);
            }

            dodaj_wpis2 = poczatek2;


    while(dodaj_wpis2 != NULL){


            while(id_szukane >= id2 || id_szukane == 0){

                        system("cls");
                        printf("Podane ID jest zle, podaj prawidlowe: ");
                        scanf("%d",&id_szukane);
                }

            while(tmp->id != dodaj_wpis2->id_pacjenta){
                        if(tmp->id == dodaj_wpis2->id_pacjenta){
                            tmp = tmp;
                        }
                        else{
                            tmp = tmp->nastepny;
                        }

                    }

            while(temp->id != dodaj_wpis2->id_lekarza){
                        if(temp->id == dodaj_wpis2->id_lekarza){
                            temp = temp;
                        }
                        else{
                            temp = temp->nastepny1;
                        }

                    }
                    temp = poczatek1;
                    tmp = poczatek;


        if(dodaj_wpis2->id == id_szukane){
            i++;
            wyswietl_wizyty_po_id1(dodaj_wpis2);
            break;
        }
        else{
            dodaj_wpis2 = dodaj_wpis2->nastepny2;
        }


    }


    printf("\n\nCo chcesz zrobic?\n[1]Odwolaj wizyte.\n[2]Zmien termin wizyty.\n");
    scanf("%d", &b);

    char s1[]="Zaplanowana";

    if(poczatek == NULL){
                printf("Err");
                return 0;
        }


        if(b==1){

                if(stricmp(dodaj_wpis2->status_wizyty, s1)==0){

                        strcpy(dodaj_wpis2->status_wizyty , "Odwolana");
                }
            else{
                printf("Tej wizyty nie mozesz odwolac !!");
        }
    }

    else{


        if(stricmp(dodaj_wpis2->status_wizyty, s1)==0){

        printf("Podaj rok wizyty: \n");
        scanf("%d", &dodaj_wpis2->rok);

        while(dodaj_wpis2->rok < rok){
            printf("Podaj rok wizyty ponownie (nie moze byc mniejszy niz aktualny): ");
            scanf("%d", &dodaj_wpis2->rok);
        }

        printf("Podaj miesiac wizyty: \n");
        scanf("%d", &dodaj_wpis2->miesiac);

        if(dodaj_wpis2->rok == rok){
            while(dodaj_wpis2->miesiac < miesiac || dodaj_wpis2->miesiac > 12){
                printf("Podaj miesiac wizyty ponownie: ");
                scanf("%d", &dodaj_wpis2->miesiac);
            }
        }
        else if(dodaj_wpis2->rok > rok){
            dodaj_wpis2->miesiac = dodaj_wpis2->miesiac;
        }

        printf("Podaj dzien wizyty: \n");
        scanf("%d", &dodaj_wpis2->dzien);

        if(dodaj_wpis2->rok == rok){
            if(dodaj_wpis2->miesiac == miesiac){
                while(dodaj_wpis2->dzien < dzien || dodaj_wpis2->dzien > 31){
                    printf("Podaj dzien wizyty ponownie: ");
                    scanf("%d", &dodaj_wpis2->dzien);
                }
            }
            else if(dodaj_wpis2->miesiac > miesiac){
                    while(dodaj_wpis2->dzien > 31){
                    printf("Podaj dzien wizyty ponownie: ");
                    scanf("%d", &dodaj_wpis2->dzien);
                }
                dodaj_wpis2->dzien = dodaj_wpis2->dzien;
            }
        }
        else if(dodaj_wpis2->rok > rok){
                while(dodaj_wpis2->dzien > 31){
                    printf("Podaj dzien wizyty ponownie: ");
                    scanf("%d", &dodaj_wpis2->dzien);
                }
            dodaj_wpis2->dzien = dodaj_wpis2->dzien;
        }
int da; /// Zmienna odpowiedzialna za przechowywanie wartosci dnia.

        int o=1; /// Zmienna niezbedna do wykonywania pêtli sprawdzaj¹cej, czy mozna sie umowic na wizyte danego dnia


        while(o>0){

            printf("\nDzien wizyty to: ");

                da = dodaj_wpis2->dzien;

                int liczba_dni_miesiaca[]={31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
                char *nazwa_dnia[]={"Niedziela", "Poniedzialek", "Wtorek", "Sroda", "Czwartek", "Piatek", "Sobota"};
                int q;
                o = 0;


                if (dodaj_wpis2->rok % 4 == 0 && (dodaj_wpis2->rok % 100 != 0 || dodaj_wpis2->rok % 400 == 0))
                    liczba_dni_miesiaca[1] = 29;

                if (dodaj_wpis2->rok < 1900 || dodaj_wpis2->miesiac < 1 || dodaj_wpis2->miesiac > 12 || da < 1 || da > liczba_dni_miesiaca[dodaj_wpis2->miesiac - 1]) {
                    printf("Podano zla date!.\n");
                    return 0;
                }

                for (q = 1900; q < dodaj_wpis2->rok; q++)
                    if (q % 4 == 0 && (q % 100 != 0 || q % 400 == 0))
                        da += 366;
                    else
                        da += 365;

                for (q = 0; q < dodaj_wpis2->miesiac - 1; q++)
                da += liczba_dni_miesiaca[q];

                printf("%s", nazwa_dnia[da% 7]);
                char dzien_wizyty[ROZMIAR];
                strcpy(dzien_wizyty, nazwa_dnia[da% 7]);

                printf("\n\n");

                    if((temp->dni_pracy[0] == '0' && strcmp(dzien_wizyty, "Poniedzialek")==0) || (temp->dni_pracy[1] == '0' && strcmp(dzien_wizyty, "Wtorek")==0) || (temp->dni_pracy[2] == '0' && strcmp(dzien_wizyty, "Sroda")==0) || (temp->dni_pracy[3] == '0' && strcmp(dzien_wizyty, "Czwartek")==0) || (temp->dni_pracy[4] == '0' && strcmp(dzien_wizyty, "Piatek")==0) || (temp->dni_pracy[5] == '0' && strcmp(dzien_wizyty, "Sobota")==0) || (temp->dni_pracy[6] == '0' && strcmp(dzien_wizyty, "Niedziela")==0)){
                        o++;
                        printf("Nie mozesz umowic wizyty na ten dzien !!");

                            printf("Podaj dzien wizyty ponownie: ");
                            scanf("%d", &dodaj_wpis2->dzien);

                        da = da;
                    }
        }

        printf("Podaj godzine wizyty: \n");
        scanf("%d", &dodaj_wpis2->godzina);
        while(dodaj_wpis2->godzina < temp->godzina_pocz || dodaj_wpis2->godzina >= temp->godzina_kon){
            printf("Ten lekarz teraz nie pracuje! Podaj prawidlowa godzine!");
            scanf("%d", &dodaj_wpis2->godzina);
        }

        if(dodaj_wpis2->rok == rok){
            if(dodaj_wpis2->miesiac == miesiac){
               if(dodaj_wpis2->dzien == dzien){
                    while(dodaj_wpis2->godzina < godzina){
                        printf("Podaj godzine wizyty ponownie (nie moze byc mniejsza niz aktualna): ");
                        scanf("%d", &dodaj_wpis2->godzina);
                    }
                }
                    else if(dodaj_wpis2->dzien > dzien){
                        dodaj_wpis2->dzien = dodaj_wpis2->dzien;
                    }
                }
            else if(dodaj_wpis2->miesiac > miesiac){
                    dodaj_wpis2->miesiac = dodaj_wpis2->miesiac;
            }
        }
        else if(dodaj_wpis2->rok > rok){
            dodaj_wpis2->dzien = dodaj_wpis2->dzien;
        }
        while(dodaj_wpis2->godzina > 23){
            printf("Podaj prawidlowa godzine!");
            scanf("%d", &dodaj_wpis2->godzina);
        }

        printf("Podaj minute wizyty: \n");
        scanf("%d", &dodaj_wpis2->minuta);

        if(dodaj_wpis2->rok == rok){
            if(dodaj_wpis2->miesiac == miesiac){
               if(dodaj_wpis2->dzien == dzien){
                    if(dodaj_wpis2->godzina == godzina){
                        while(dodaj_wpis2->minuta < minuta){
                            printf("Podaj minute wizyty ponownie (nie moze byc mniejsza niz aktualna): ");
                            scanf("%d", &dodaj_wpis2->minuta);
                            }
                    }
                    else if(dodaj_wpis2->godzina > godzina){
                        dodaj_wpis2->godzina = dodaj_wpis2->godzina;
                    }
                }
                    else if(dodaj_wpis2->dzien > dzien){
                        dodaj_wpis2->dzien = dodaj_wpis2->dzien;
                    }
                }
            else if(dodaj_wpis2->miesiac > miesiac){
                    dodaj_wpis2->miesiac = dodaj_wpis2->miesiac;
            }
        }
        else if(dodaj_wpis2->rok > rok){
            dodaj_wpis2->dzien = dodaj_wpis2->dzien;
        }
        while(dodaj_wpis2->minuta > 59){
            printf("Podaj prawidlowa minute!");
            scanf("%d", &dodaj_wpis2->minuta);
        }




        printf("Podaj czas trwania wizyty w minutach: \n");
        scanf("%d", &dodaj_wpis2->czas_trwania);

        while(dodaj_wpis2->czas_trwania > 60){
            printf("Wizyta moze trwac maksymalnie 60 minut. Wprowadz czas trwania ponownie: ");
            scanf("%d", &dodaj_wpis2->czas_trwania);
        }


        dodaj_wpis2->godzina_zakonczenia_wizyty = dodaj_wpis2->godzina;
        dodaj_wpis2->minuta_zakonczenia_wizyty = dodaj_wpis2->minuta;

        dodaj_wpis2->minuta_zakonczenia_wizyty = (dodaj_wpis2->minuta) + (dodaj_wpis2->czas_trwania);

        if(dodaj_wpis2->minuta_zakonczenia_wizyty >= 60){

            dodaj_wpis2->godzina_zakonczenia_wizyty += 1;
            dodaj_wpis2->minuta_zakonczenia_wizyty = (dodaj_wpis2->minuta + dodaj_wpis2->czas_trwania) - 60;
        }

        while(dodaj_wpis2->godzina_zakonczenia_wizyty > dodaj_wpis2->godzina){
            printf("\n\nLekarz nie pracuje do tej godziny. Wybierz inna !\n");
            printf("Podaj godzine wizyty: ");
            scanf("%d", &dodaj_wpis2->godzina);
            printf("Podaj minute wizyty: ");
            scanf("%d", &dodaj_wpis2->minuta);
            printf("Podaj czas trwania wizyty: ");
            scanf("%d", &dodaj_wpis2->czas_trwania);

            dodaj_wpis2->godzina_zakonczenia_wizyty = dodaj_wpis2->godzina;
            dodaj_wpis2->minuta_zakonczenia_wizyty = dodaj_wpis2->minuta;

            dodaj_wpis2->minuta_zakonczenia_wizyty = (dodaj_wpis2->minuta) + (dodaj_wpis2->czas_trwania);

            if(dodaj_wpis2->minuta_zakonczenia_wizyty >= 60){

                dodaj_wpis2->godzina_zakonczenia_wizyty += 1;
                dodaj_wpis2->minuta_zakonczenia_wizyty = (dodaj_wpis2->minuta + dodaj_wpis2->czas_trwania) - 60;
            }
        }
    }
    if((stricmp(dodaj_wpis2->status_wizyty, s1)!=0)){
        printf("Nie mozna edytowac!");
    }

    teemp = poczatek2;
            int t;
            while(teemp != NULL){
                 if(dodaj_wpis2->rok == teemp->rok && dodaj_wpis2->id_lekarza == teemp->id_lekarza){
                    if(dodaj_wpis2->miesiac == teemp->miesiac){
                       if(dodaj_wpis2->dzien == teemp->dzien){
                            if((dodaj_wpis2->godzina == teemp->godzina) || (dodaj_wpis2->godzina < teemp->godzina && dodaj_wpis2->godzina_zakonczenia_wizyty == teemp->godzina && dodaj_wpis2->minuta_zakonczenia_wizyty > teemp->minuta) || (dodaj_wpis2->godzina == teemp->godzina && dodaj_wpis2->godzina_zakonczenia_wizyty > teemp->godzina_zakonczenia_wizyty && dodaj_wpis2->minuta < teemp->minuta)){
                                if((dodaj_wpis2->minuta >= teemp->minuta && dodaj_wpis2->minuta_zakonczenia_wizyty<teemp->minuta_zakonczenia_wizyty) || (dodaj_wpis2->minuta <= teemp->minuta && dodaj_wpis2->minuta_zakonczenia_wizyty>teemp->minuta)){
                                    for( t=0; t<=1; t++){
                                        printf("Wybrany lekarz ma juz wtedy wizyte, zacznij od nowa!!\n\n");
                                        edycja_wizyt(id2,rok, miesiac, dzien, godzina, minuta);
                                        return 0;
                                    }
                                }
                                else{
                                    break;
                                }
                            }
                            else{
                                break;
                            }
                        }
                        else{
                            break;
                        }
                    }
                    else{
                        break;
                    }
                }
                else{
                    teemp = teemp->nastepny2;
                }
            }

    teemp = poczatek2;
            int f;
            while(teemp != NULL){
                 if(dodaj_wpis2->rok == teemp->rok && dodaj_wpis2->id_pacjenta == teemp->id_pacjenta){
                    if(dodaj_wpis2->miesiac == teemp->miesiac){
                       if(dodaj_wpis2->dzien == teemp->dzien){
                            if((dodaj_wpis2->godzina == teemp->godzina) || (dodaj_wpis2->godzina < teemp->godzina && dodaj_wpis2->godzina_zakonczenia_wizyty == teemp->godzina && dodaj_wpis2->minuta_zakonczenia_wizyty > teemp->minuta) || (dodaj_wpis2->godzina == teemp->godzina && dodaj_wpis2->godzina_zakonczenia_wizyty > teemp->godzina_zakonczenia_wizyty && dodaj_wpis2->minuta < teemp->minuta)){
                                if((dodaj_wpis2->minuta >= teemp->minuta && dodaj_wpis2->minuta_zakonczenia_wizyty<teemp->minuta_zakonczenia_wizyty) || (dodaj_wpis2->minuta <= teemp->minuta && dodaj_wpis2->minuta_zakonczenia_wizyty>teemp->minuta)){
                                    for( f=0; f<=1; f++){
                                        printf("Wybrany pacjent ma juz wtedy wizyte, zacznij od nowa!!\n\n");
                                        edycja_wizyt(id2,rok, miesiac, dzien, godzina, minuta);
                                        return 0;
                                    }
                                }
                                else{
                                    break;
                                }
                            }
                            else{
                                break;
                            }
                        }
                        else{
                            break;
                        }
                    }
                    else{
                        break;
                    }
                }
                else{
                    teemp = teemp->nastepny2;
                }
            }
    }

    if(i==0){
            printf("Brak wizyt o podanym ID!!\n");
        }

        int n;
            printf("\n\nCzy chcesz edyt kolejne wizyty?\n[1]Tak.\n[2]Nie.");
            scanf("%d", &n);
            if(n==1){
                edycja_wizyt(id2,rok, miesiac, dzien, godzina, minuta);
            }
            else if(n==2){
                return 0;
            }
            else while( n == 0 || n > 2){
                printf("Wybierz poprawny numer!\n[1]Tak.\n[2]Nie.");
                scanf("%d", &n);
            }
return 0;
}

/// Funkcja pozwalajaca na wypisywanie wizyt wedlug wpisanego ID. \image html obrazek2.png
int wyswietl_wizyty_po_id1(){

    if(poczatek2 == NULL){
            system("cls");
            printf("Baza danych jest pusta !!\n\n");
            return 0;
        }


    int odczyt_dni();
    struct pacjenci *tmp; /// Zmienne wskaznikowe tymczasowe (tmp, temp i teemp), pozwalajace na sprawne wyswietlanie wizyt wedlug wprowadzonego ID.
    tmp = poczatek;

    struct lekarze *temp;
    temp = poczatek1;

    struct wizyty *teemp;
    teemp = poczatek2;



                        while(teemp->id != dodaj_wpis2->id){
                            if(teemp->id == dodaj_wpis2->id){
                                teemp = teemp;
                            }
                            else{
                                teemp = teemp->nastepny2;
                            }
                        }

                        while(tmp->id != dodaj_wpis2->id_pacjenta){
                            if(tmp->id == dodaj_wpis2->id_pacjenta){
                                tmp = tmp;
                            }
                            else{
                                tmp = tmp->nastepny;
                            }
                        }

                        while(temp->id != dodaj_wpis2->id_lekarza){
                            if(temp->id == dodaj_wpis2->id_lekarza){
                                temp = temp;
                            }
                            else{
                                temp = temp->nastepny1;
                            }
                        }

                printf("\n*****************************************************************************************************************************");
                printf("\nNumer ID wizyty: \t\t%d",dodaj_wpis2->id);
                printf("\nNumer ID pacjenta: \t\t%d",dodaj_wpis2->id_pacjenta);
                printf("\nImie i nazwisko pacjenta: \t%s %s", tmp->imie,tmp->nazwisko);
                printf("\nNumer ID lekarza: \t\t%d",dodaj_wpis2->id_lekarza);
                printf("\nImie i nazwisko lekarza: \t%s %s", temp->imie,temp->nazwisko);
                printf("\nGodziny pracy lekarza: \t\t%d:00-%d:00", temp->godzina_pocz, temp->godzina_kon);
                printf("\nData  wizyty: \t\t\t%d.%d.%d",dodaj_wpis2->dzien, dodaj_wpis2->miesiac, dodaj_wpis2->rok);
                printf("\nDzien wizyty to: \t\t");
                odczyt_dni(dodaj_wpis2->rok, dodaj_wpis2->miesiac, dodaj_wpis2->dzien);
                 printf("\nDni pracy: \t\t\t");
                if(temp->dni_pracy[0] == '1'){
                    printf("Poniedzialek,");
                }
                if(temp->dni_pracy[1] == '1'){
                    printf("Wtorek,");
                }
                if(temp->dni_pracy[2] == '1'){
                    printf("Sroda,");
                }
                if(temp->dni_pracy[3] == '1'){
                    printf("Czwartek,");
                }
                if(temp->dni_pracy[4] == '1'){
                    printf("Piatek,");
                }
                if(temp->dni_pracy[5] == '1'){
                    printf("Sobota,");
                }
                if(temp->dni_pracy[6] == '1'){
                    printf("Niedziela,");
                }
                printf("\nGodzina wizyty: \t\t%d:%d",dodaj_wpis2->godzina, dodaj_wpis2->minuta);
                printf("\nCzas trwania wizyty: \t\t%d",dodaj_wpis2->czas_trwania);
                printf("\nStatus wizyty: \t\t\t%s\n\n", dodaj_wpis2->status_wizyty);
                teemp = poczatek2;
                temp = poczatek1;
                tmp = poczatek;
                return 0;
}

/// Funkcja pokazujaca wizyty danego pacjenta po jego numerze ID (wizyty zaplanowane, odbyte i odwolane); jest to funkcja posiadajaca rekursje.Funkcja pokazujaca wizyty danego pacjenta po jego numerze ID (wizyty zaplanowane, odbyte i odwolane); jest to funkcja posiadajaca rekursje.\image html wp2.png
void pokaz_wizyty_pacjenta(int id){

    system("cls");

    if(poczatek2 == NULL){
            system("cls");
            printf("Baza danych jest pusta !!\n\n");
            return ;
        }

    char odbyta[] = "Odbyta";
    char zaplanowana[] = "Zaplanowana";
    char odwolana[] = "Odwolana";
    int rok, miesiac, dzien;

    int wyswietl_wizyty_po_id();
    int id_szukane;
    int i = 0;
    printf("Podaj ID pacjenta, ktorego wizyty chcesz wyswietlic: ");
    scanf("%d", &id_szukane);

    printf("Czy chcesz ograniczyc wyniki wyszukiwania do konkretnego statusu lub dnia?\n[1]Tak - status.\n[2]Tak - dzien.\n[3]Nie.\n");
    int wybor;
    scanf("%d", &wybor);

    if(wybor == 1){
        printf("\nDo jakiego statusu chcesz ograniczyc?\n[1]Wizyta odbyta.\n[2]Wizyta zaplanowana.\n[3]Wizyta odwolana.\n");
        int status;
        scanf("%d", &status);


            if(status == 1){
                dodaj_wpis2 = poczatek2;

                while(dodaj_wpis2 != NULL){

                    while(id_szukane >= id || id_szukane == 0){

                        system("cls");
                        printf("Podane ID jest zle, podaj prawidlowe: ");
                        scanf("%d",&id_szukane);
                    }

                        if(dodaj_wpis2->id_pacjenta == id_szukane && (stricmp(dodaj_wpis2->status_wizyty, odbyta)==0)){
                            i++;
                            wyswietl_wizyty_po_id(dodaj_wpis2);
                            dodaj_wpis2 = dodaj_wpis2->nastepny2;
                        }
                        else{
                            dodaj_wpis2 = dodaj_wpis2->nastepny2;
                        }
                    }
                }


            if(status == 2){
                dodaj_wpis2 = poczatek2;

                while(dodaj_wpis2 != NULL){

                    while(id_szukane >= id || id_szukane == 0){

                        system("cls");
                        printf("Podane ID jest zle, podaj prawidlowe: ");
                        scanf("%d",&id_szukane);
                    }

                        if(dodaj_wpis2->id_pacjenta == id_szukane && (stricmp(dodaj_wpis2->status_wizyty, zaplanowana)==0)){
                            i++;
                            wyswietl_wizyty_po_id(dodaj_wpis2);
                            dodaj_wpis2 = dodaj_wpis2->nastepny2;
                        }
                        else{
                            dodaj_wpis2 = dodaj_wpis2->nastepny2;
                        }
                    }
                }



            if(status == 3){
                dodaj_wpis2 = poczatek2;

                while(dodaj_wpis2 != NULL){

                    while(id_szukane >= id || id_szukane == 0){

                        system("cls");
                        printf("Podane ID jest zle, podaj prawidlowe: ");
                        scanf("%d",&id_szukane);
                    }

                        if(dodaj_wpis2->id_pacjenta == id_szukane && (stricmp(dodaj_wpis2->status_wizyty, odwolana)==0)){
                            i++;
                            wyswietl_wizyty_po_id(dodaj_wpis2);
                            dodaj_wpis2 = dodaj_wpis2->nastepny2;
                        }
                        else{
                            dodaj_wpis2 = dodaj_wpis2->nastepny2;
                        }
                    }
                }
    }


    if(wybor == 2){
        printf("\nDo jakiego dnia chcesz ograniczyc?\n");
        printf("Podaj rok wizyty: ");
        scanf("%d", &rok);
        printf("Podaj miesiac wizyty: ");
        scanf("%d", &miesiac);
        printf("Podaj dzien wizyty: ");
        scanf("%d", &dzien);

        dodaj_wpis2 = poczatek2;

        while(dodaj_wpis2!= NULL){

            if(dodaj_wpis2->rok == rok && dodaj_wpis2->miesiac == miesiac && dodaj_wpis2->dzien == dzien){

                i++;
                wyswietl_wizyty_po_id(dodaj_wpis2);
                dodaj_wpis2 = dodaj_wpis2->nastepny2;
            }
            else{
                dodaj_wpis2 = dodaj_wpis2->nastepny2;
            }
        }
    }




    if(wybor == 3){
    dodaj_wpis2 = poczatek2;

    while(dodaj_wpis2 != NULL){

            while(id_szukane >= id || id_szukane == 0){

                        system("cls");
                        printf("Podane ID jest zle, podaj prawidlowe: ");
                        scanf("%d",&id_szukane);

                }

        if(dodaj_wpis2->id_pacjenta == id_szukane){
            i++;
            wyswietl_wizyty_po_id(dodaj_wpis2);
            dodaj_wpis2 = dodaj_wpis2->nastepny2;
        }
        else{
            dodaj_wpis2 = dodaj_wpis2->nastepny2;
        }
    }
    }


    if(i==0){
            printf("Brak wizyt pacjenta o podanym ID!!\n");
        }


    int n;
            printf("\n\nCzy chcesz wyszukac kolejne wizyty?\n[1]Tak.\n[2]Nie.");
            scanf("%d", &n);
            if(n==1){
                pokaz_wizyty_pacjenta(id);
            }
            else if(n==2){
                return ;
            }
            else while( n == 0 || n > 2){
                printf("Wybierz poprawny numer!\n[1]Tak.\n[2]Nie.");
                scanf("%d", &n);
            }
return ;
}

/// Funkcja wyswietla wszystkie wizyty danego lekarza wedlug podanego ID; pozwala pokazac wizyty odbyte, zaplanowane i odwolane.\image html wl.png
void pokaz_wizyty_lekarza(int id1){


    system("cls");

    if(poczatek2 == NULL){
            system("cls");
            printf("Baza danych jest pusta !!\n\n");
            return ;
        }

    char odbyta[] = "Odbyta"; /// Tablica znakow przechowujaca slowo "Odbyta" - uzyte pozniej do reprezentacji statusu wizyt.
    char zaplanowana[] = "Zaplanowana"; /// Tablica znakow przechowujaca slowo "Zaplanowana" - uzyte pozniej do reprezentacji statusu wizyt.
    char odwolana[] = "Odwolana"; /// Tablica znakow przechowujaca slowo "Odwolana" - uzyte pozniej do reprezentacji statusu wizyt.

    int rok, miesiac, dzien; /// Zmienne typu int, przechowujace wewnatrz date.
    int wyswietl_wizyty_po_id(); /// Deklaracja funkcji 'wyswietl_wizyty_po_id()'.
    int id_szukane; /// ID, wedlug ktorego bedziemy wyswietlac wizyty.
    int i = 0;

    printf("Podaj ID lekarza, ktorego wizyty chcesz wyswietlic: ");
    scanf("%d", &id_szukane);

    printf("Czy chcesz ograniczyc wyniki wyszukiwania do konkretnego statusu lub dnia?\n[1]Tak - status.\n[2]Tak - dzien.\n[3]Nie.\n");
    int wybor; /// Zmienna typu int, odpowiadajaca za wybor ograniczenia wyswietlania - wg statusu, dnia lub bez ograniczen.
    scanf("%d", &wybor);

    if(wybor == 1){
        printf("\nDo jakiego statusu chcesz ograniczyc?\n[1]Wizyta odbyta.\n[2]Wizyta zaplanowana.\n[3]Wizyta odwolana.\n");
        int status;
        scanf("%d", &status);


            if(status == 1){
                dodaj_wpis2 = poczatek2;

                while(dodaj_wpis2 != NULL){

                    while(id_szukane >= id1 || id_szukane == 0){

                        system("cls");
                        printf("Podane ID jest zle, podaj prawidlowe: ");
                        scanf("%d",&id_szukane);
                    }

                        if(dodaj_wpis2->id_lekarza == id_szukane && (stricmp(dodaj_wpis2->status_wizyty, odbyta)==0)){
                            i++;
                            wyswietl_wizyty_po_id(dodaj_wpis2);
                            dodaj_wpis2 = dodaj_wpis2->nastepny2;
                        }
                        else{
                            dodaj_wpis2 = dodaj_wpis2->nastepny2;
                        }
                    }
                }


            if(status == 2){
                dodaj_wpis2 = poczatek2;

                while(dodaj_wpis2 != NULL){

                    while(id_szukane >= id1 || id_szukane == 0){

                        system("cls");
                        printf("Podane ID jest zle, podaj prawidlowe: ");
                        scanf("%d",&id_szukane);
                    }

                        if(dodaj_wpis2->id_lekarza == id_szukane && (stricmp(dodaj_wpis2->status_wizyty, zaplanowana)==0)){
                            i++;
                            wyswietl_wizyty_po_id(dodaj_wpis2);
                            dodaj_wpis2 = dodaj_wpis2->nastepny2;
                        }
                        else{
                            dodaj_wpis2 = dodaj_wpis2->nastepny2;
                        }
                    }
                }



            if(status == 3){
                dodaj_wpis2 = poczatek2;

                while(dodaj_wpis2 != NULL){

                    while(id_szukane >= id1 || id_szukane == 0){

                        system("cls");
                        printf("Podane ID jest zle, podaj prawidlowe: ");
                        scanf("%d",&id_szukane);
                    }

                        if(dodaj_wpis2->id_lekarza == id_szukane && (stricmp(dodaj_wpis2->status_wizyty, odwolana)==0)){
                            i++;
                            wyswietl_wizyty_po_id(dodaj_wpis2);
                            dodaj_wpis2 = dodaj_wpis2->nastepny2;
                        }
                        else{
                            dodaj_wpis2 = dodaj_wpis2->nastepny2;
                        }
                    }
                }
    }

    if(wybor == 2){
        printf("\nDo jakiego dnia chcesz ograniczyc?\n");
        printf("Podaj rok wizyty: ");
        scanf("%d", &rok);
        printf("Podaj miesiac wizyty: ");
        scanf("%d", &miesiac);
        printf("Podaj dzien wizyty: ");
        scanf("%d", &dzien);

        dodaj_wpis2 = poczatek2;

        while(dodaj_wpis2!= NULL){

            if(dodaj_wpis2->rok == rok && dodaj_wpis2->miesiac == miesiac && dodaj_wpis2->dzien == dzien){

                i++;
                wyswietl_wizyty_po_id1(dodaj_wpis2);
                dodaj_wpis2 = dodaj_wpis2->nastepny2;
            }
            else{
                dodaj_wpis2 = dodaj_wpis2->nastepny2;
            }
        }
    }


    if(wybor == 3){
    dodaj_wpis2 = poczatek2;

    while(dodaj_wpis2 != NULL){

            while(id_szukane >= id1 || id_szukane == 0){

                        system("cls");
                        printf("Podane ID jest zle, podaj prawidlowe: ");
                        scanf("%d",&id_szukane);

                }

        if(dodaj_wpis2->id_lekarza == id_szukane){
            i++;
            wyswietl_wizyty_po_id(dodaj_wpis2);
            dodaj_wpis2 = dodaj_wpis2->nastepny2;
        }
        else{
            dodaj_wpis2 = dodaj_wpis2->nastepny2;
        }
    }
    }

    if(i==0){
        printf("Brak wizyt lekarza o podanym ID!!\n");
    }

        int n;
            printf("\n\nCzy chcesz wyszukac kolejne wizyty?\n[1]Tak.\n[2]Nie.");
            scanf("%d", &n);
            if(n==1){
                pokaz_wizyty_lekarza(id1);
            }
            else if(n==2){
                return ;
            }
            else while( n == 0 || n > 2){
                printf("Wybierz poprawny numer!\n[1]Tak.\n[2]Nie.");
                scanf("%d", &n);
            }
return ;
}

/// Funkcja wyswietlajaca wszystkie wizyty wedlug wprowadzonego ID wizyty, pokazujaca wszystkie szczegolowe dane kazdej z wizyt.\image html obrazek1.png
int wyswietl_wizyty_po_id(){

    if(poczatek2 == NULL){
            system("cls");
            printf("Baza danych jest pusta !!\n\n");
            return 0;
        }

    int odczyt_dni();

    struct pacjenci *tmp;
    tmp = poczatek;

    struct lekarze *temp;
    temp = poczatek1;

                        while(tmp->id != dodaj_wpis2->id_pacjenta){
                            if(tmp->id == dodaj_wpis2->id_pacjenta){
                                tmp = tmp;
                            }
                            else{
                                tmp = tmp->nastepny;
                            }
                        }

                        while(temp->id != dodaj_wpis2->id_lekarza){
                            if(temp->id == dodaj_wpis2->id_lekarza){
                                temp = temp;
                            }
                            else{
                                temp = temp->nastepny1;
                            }
                        }

                printf("\n*****************************************************************************************************************************");
                printf("\nNumer ID wizyty: \t\t%d",dodaj_wpis2->id);
                printf("\nNumer ID pacjenta: \t\t%d",dodaj_wpis2->id_pacjenta);
                printf("\nImie i nazwisko pacjenta: \t%s %s", tmp->imie,tmp->nazwisko);
                printf("\nNumer ID lekarza: \t\t%d",dodaj_wpis2->id_lekarza);
                printf("\nImie i nazwisko lekarza: \t%s %s", temp->imie,temp->nazwisko);
                printf("\nGodziny pracy lekarza: \t\t%d:00-%d:00", temp->godzina_pocz, temp->godzina_kon);
                printf("\nData  wizyty: \t\t\t%d.%d.%d",dodaj_wpis2->dzien, dodaj_wpis2->miesiac, dodaj_wpis2->rok);
                printf("\nDzien wizyty to: \t\t");
                odczyt_dni(dodaj_wpis2->rok, dodaj_wpis2->miesiac, dodaj_wpis2->dzien);
                printf("\nGodzina wizyty: \t\t%d:%d",dodaj_wpis2->godzina, dodaj_wpis2->minuta);
                printf("\nCzas trwania wizyty: \t\t%d",dodaj_wpis2->czas_trwania);
                printf("\nStatus wizyty: \t\t\t%s", dodaj_wpis2->status_wizyty);
                return 0;
}

/// Funkcja pozwalajaca na zmiane statusu wybranej wizyty; obsluguje ona zmiane statusu wizyty na wlasciwy.\image html obrx.png
void zmiana_statusu(int rok, int miesiac, int dzien, int godzina, int minuta){

    int wyswietl_wizyty_po_id1();
    char odbyta[] = "Odbyta";
    char nieodbyta[]="Nie-odbyta";
    int i = 0;
    dodaj_wpis2 = poczatek2;

    while(dodaj_wpis2 != NULL){

            if(dodaj_wpis2->rok < rok && (stricmp(dodaj_wpis2->status_wizyty, odbyta)!= 0) && (stricmp(dodaj_wpis2->status_wizyty, nieodbyta)!= 0)){
                    strcpy(dodaj_wpis2->status_wizyty , "Odbyta");
                    i++;
            }
            else if(dodaj_wpis2->rok == rok && dodaj_wpis2->miesiac < miesiac && (stricmp(dodaj_wpis2->status_wizyty, odbyta)!= 0) && (stricmp(dodaj_wpis2->status_wizyty, nieodbyta)!= 0)){
                strcpy(dodaj_wpis2->status_wizyty , "Odbyta");
                i++;
            }
            else if(dodaj_wpis2->rok == rok && dodaj_wpis2-> miesiac == miesiac && dodaj_wpis2->dzien < dzien && (stricmp(dodaj_wpis2->status_wizyty, odbyta)!= 0) && (stricmp(dodaj_wpis2->status_wizyty, nieodbyta)!= 0)){
                strcpy(dodaj_wpis2->status_wizyty , "Odbyta");
                i++;
            }
            else if(dodaj_wpis2->rok == rok && dodaj_wpis2-> miesiac == miesiac && dodaj_wpis2->dzien == dzien && dodaj_wpis2->godzina_zakonczenia_wizyty < godzina && (stricmp(dodaj_wpis2->status_wizyty, odbyta)!= 0) && (stricmp(dodaj_wpis2->status_wizyty, nieodbyta)!= 0)){
                strcpy(dodaj_wpis2->status_wizyty , "Odbyta");
                i++;
            }
            else if(dodaj_wpis2->rok == rok && dodaj_wpis2-> miesiac == miesiac && dodaj_wpis2->dzien == dzien && dodaj_wpis2->godzina_zakonczenia_wizyty == godzina && dodaj_wpis2->minuta_zakonczenia_wizyty < minuta && (stricmp(dodaj_wpis2->status_wizyty, odbyta)!= 0) && (stricmp(dodaj_wpis2->status_wizyty, nieodbyta)!= 0)){
                strcpy(dodaj_wpis2->status_wizyty , "Odbyta");
                i++;
            }
        if(i>0){
        if(stricmp(dodaj_wpis2->status_wizyty, odbyta)==0){
            wyswietl_wizyty_po_id1();
            printf("\nStatus danej wizyty wskazuje, ze wizyta minela. Czy wizyta sie odbyla?\n[1]Tak.\n[2]Nie.");
            int g;
            scanf("%d", &g);
            if(g==1){
                strcpy(dodaj_wpis2->status_wizyty, odbyta);
            }
            else if(g==2){
                strcpy(dodaj_wpis2->status_wizyty, nieodbyta);
            }

        }
        }

        dodaj_wpis2 = dodaj_wpis2->nastepny2;
    }
}
