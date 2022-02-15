#include "pacjenci.h"

struct pacjenci *poczatek = NULL; /// Wskaznik zerujacy poczatek 2-kierunkowej listy pacjentow.
struct pacjenci *koniec = NULL; /// Wskaznik zerujacy koniec 2-kierunkowej listy pacjentow.

///Funkcja odpowiadajaca za przydzial pamieci oraz wprowadzanie danych, opartych na strukturze 'pacjenci'; malloc() alokuje pamiec wielkosci struktury 'pacjenci' i zwraca wskaznik na poczatek zaalokowanego bloku pamieci. \image html nowyp.png
int nowy_pacjent(int id){

    struct pacjenci *dodaj_wpis = (struct pacjenci *)malloc(sizeof(struct pacjenci)); /// Wskaznik na nowo zaalokowany blok pamieci, w ktorym beda przechowywane dane nowo utworzonego pacjenta.

    if(!dodaj_wpis){
        printf("Blad przydzielenia pamieci !!");
        perror("malloc");
        return EXIT_FAILURE;
    }

    if (dodaj_wpis!=NULL){

        system("cls");

        (dodaj_wpis->id)=id;

        printf("Podaj imie: \n");
        scanf("%s",dodaj_wpis->imie);

        printf("Podaj nazwisko: \n");
        scanf("%s",dodaj_wpis->nazwisko);

        printf("Podaj pesel: \n");
        scanf("%s", dodaj_wpis->pesel);

        while((strlen((dodaj_wpis->pesel))!=11)){
            printf("Podany pesel jest nieprawidlowy!!\n");
            scanf("%s",dodaj_wpis->pesel);
        }

        printf("Podaj date urodzenia(DD/MM/RRRR): \n");
        scanf("%s",dodaj_wpis->data_ur);

        printf("Podaj miejsce zamieszkania: \n");
        scanf("%s", dodaj_wpis->adres);

        printf("Podaj nr domu/mieszkania: \n");
        scanf("%s", dodaj_wpis->nr_dom);

        printf("Podaj email: \n");
        scanf("%s", dodaj_wpis->email);

        printf("Podaj nr telefonu: \n");
        scanf("%s", dodaj_wpis->telefon);

        while((strlen(dodaj_wpis->telefon)!=9)){
                printf("Podany nr telefonu jest nieprawidlowy!!\n");
                scanf("%s",dodaj_wpis->telefon);
        }

        printf("Podaj wage(w kg.): \n");
        scanf("%s", dodaj_wpis->waga);

        printf("Podaj wzrost(w cm.): \n");
        scanf("%s", dodaj_wpis->wzrost);

        printf("Podaj oddzial NFZ: \n");
        scanf("%s", dodaj_wpis->oddzial);
    }

        dodaj_wpis -> nastepny = NULL; /// Wyzerowanie wartosci pola 'nastepny' wskaznika 'dodaj_wpis'

        if(koniec == NULL){
                poczatek = koniec = dodaj_wpis;
          }

          else{
                koniec->nastepny = dodaj_wpis;
                koniec = dodaj_wpis;
            }
            int n;
            printf("\n\nCzy chcesz dodac kolejnego pacjenta?\n[1]Tak.\n[2]Nie.");
            scanf("%d", &n);
            if(n==1){
                id++;
                nowy_pacjent(id);
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

///Funkcja odpowiadajaca za wyswietlenie calej listy pacjentow; jesli 'poczatek' rozni sie od NULL, wtedy wartosc wskaznika 'tmp' przyjmuje wartosc wskaznika 'poczatek'; jesli 'tmp' nie jest NULL-em, to funkcja - dzieki petli while() i przechodzeniu do nastepnych elementow listy - wyswietla wszystkie elementy listy dwukierunkowej po kolei.\image html pp.png
void pokaz_pacjentow(struct pacjenci *tmp){

    system("cls");


        if(poczatek != NULL){
                tmp = poczatek; /// Przypisanie wskaznikowi 'tmp' wartosci wskaznika 'poczatek'.
        }

            else{
                tmp = NULL;
            }

                if(tmp == NULL){
                    printf("\nBaza pacjentow jest pusta!!.\n\n");
                }

                    else  while(tmp != NULL){

                        printf("\n*****************************************************************************************************************************");
                        printf("\nNumer ID: \t\t%d",tmp->id);
                        printf("\nImie i nazwisko: \t%s %s \n",tmp->imie, tmp->nazwisko);
                        printf("PESEL: \t\t\t%s\n",tmp->pesel);
                        printf("Data urodzenia: \t%s\n",tmp->data_ur);
                        printf("Adres zamieszkania: \t%s %s\n",tmp->adres,tmp->nr_dom);
                        printf("E-Mail: \t\t%s\n",tmp->email);
                        printf("Nr telefonu: \t\t+48 %s\n",tmp->telefon);
                        printf("Waga: \t\t\t%s KG \n",tmp->waga);
                        printf("Wzrost: \t\t%s CM \n",tmp->wzrost);
                        printf("Oddzial NFZ: \t\t%s\n",tmp->oddzial);


                    tmp = tmp -> nastepny;

                }
}

///Funkcja odpowiedzialna za wczytanie pacjentow z pliku "Baza_Przychodnia_Pacjenci.txt"; najpierw plik otwierany jest tylko do odczytu.\image html fz.png
void wczytaj_pacjentow(char* nazwa_pliku) {

    FILE* wp;
    wp = fopen(nazwa_pliku, "r");


    if (wp != NULL){


        if((feof(wp)==0) && (fgetc(wp)<2)){


            fclose(wp);
            remove(nazwa_pliku);
          }

         else{

            while(feof(wp) == 0){

          dodaj_wpis = malloc(sizeof (struct pacjenci));

          fscanf(wp, "%d", &dodaj_wpis->id);
          fscanf(wp, "%s", dodaj_wpis->imie);
          fscanf(wp, "%s", dodaj_wpis->nazwisko);
          fscanf(wp, "%s", dodaj_wpis->pesel);
          fscanf(wp, "%s", dodaj_wpis->data_ur);
          fscanf(wp, "%s", dodaj_wpis->adres);
          fscanf(wp, "%s", dodaj_wpis->nr_dom);
          fscanf(wp, "%s", dodaj_wpis->email);
          fscanf(wp, "%s", dodaj_wpis->telefon);
          fscanf(wp, "%s", dodaj_wpis->waga);
          fscanf(wp, "%s", dodaj_wpis->wzrost);
          fscanf(wp, "%s", dodaj_wpis->oddzial);

          dodaj_wpis -> nastepny = NULL;

          if (koniec != NULL){

                koniec->nastepny = dodaj_wpis;
                koniec = dodaj_wpis;

          }

          else{
                koniec = poczatek = dodaj_wpis;
            }
        }
         }
        fclose(wp);
    }

}

///Funkcja zapisujaca pacjentow do pliku; plik otwieramy tylko do zapisu; do wskaznika 'dodaj_wpis' przypisujemy wartosc wskaznika wskazujacego na 'poczatek' listy; po jej elementach poruszamy sie dzieki petli while() i przypisywaniu wskaznikowi 'dodaj_wpis' wartosci wskaznika 'nastepny'.\image html kodzik.png Kod realizowany jest w odpowiednim momencie, automatycznie podczas uzytkowania programu.
void zapisz_do_pliku_pacjentow(char* nazwa_pliku){

    FILE* wp; /// Wskaznik otwarty ponizej tylko do zapisu; zapisuje dane pacjentow do pliku tekstowego.
    wp = fopen(nazwa_pliku, "w");

   dodaj_wpis = poczatek;

        while(dodaj_wpis != NULL) {

            fprintf(wp, "\n\n");
            fprintf(wp, "%d\n", dodaj_wpis->id);
            fprintf(wp, "%s\n", dodaj_wpis->imie);
            fprintf(wp, "%s\n", dodaj_wpis->nazwisko);
            fprintf(wp, "%s\n", dodaj_wpis->pesel);
            fprintf(wp, "%s\n", dodaj_wpis->data_ur);
            fprintf(wp, "%s\n", dodaj_wpis->adres);
            fprintf(wp, "%s\n", dodaj_wpis->nr_dom);
            fprintf(wp, "%s\n", dodaj_wpis->email);
            fprintf(wp, "%s\n", dodaj_wpis->telefon);
            fprintf(wp, "%s\n", dodaj_wpis->waga);
            fprintf(wp, "%s\n", dodaj_wpis->wzrost);
            fprintf(wp, "%s", dodaj_wpis->oddzial);
            dodaj_wpis = dodaj_wpis -> nastepny;
        }

    fclose(wp);
}

/// Funkcja odpowiadajaca za usuwanie konkretnego pacjenta - parametrem wywolania jest tutaj ID pacjenta.\image html pzu.png
struct pacjenci *usuwanie_pacjentow(struct pacjenci *lista3){

    int a; /// Zmienna przechowujaca ID pacjenta, ktory ma zostac usuniety.
    struct pacjenci *poprzedni = NULL;
    struct pacjenci *tmp = lista3;
    tmp = poczatek;
    int b = 0;

        if(tmp == NULL){
            system("cls");
            printf("Baza pacjentow jest pusta !!\n\n");
            return 0;
        }

        printf("Podaj numer ID pacjenta, ktorego chcesz usunac: \n");
        scanf("%d", &a);

        while(koniec->id < a){
                printf("Podano zly numer!!");
                printf("Podaj numer ID pacjenta, ktorego chcesz usunac: \n");
                scanf("%d", &a);
            }


        tmp = poczatek;
        while(tmp!=NULL){
            if(tmp->id == a){
                b++;
            }
            tmp = tmp->nastepny;
        }
        if(b<1){
            printf("Podano zly numer!!");
            usuwanie_pacjentow(lista3);
        }

        tmp = poczatek;
         while(tmp->id != NULL){
                    if(tmp->id == a){
                            system("cls");
                            printf("\n*****************************************************************************************************************************");
                            printf("\nNumer ID pacjenta: \t\t%d",tmp->id);
                            printf("\nImie i nazwisko pacjenta: \t%s %s", tmp->imie,tmp->nazwisko);
                            break;
                    }
                    else{
                        tmp = tmp->nastepny;
                    }
                }

            printf("\n\nCzy tego pacjenta chcesz usunac?\n[1]Tak.\n[2]Nie.\n");
            int u;
            scanf("%d", &u);
            if(u==1){

            }
            else if(u==2){
                usuwanie_pacjentow(lista3);
            }
            else if(u==0 || u>2){
                printf("Wybierz wlasciwy numerek !!");
                usuwanie_pacjentow(lista3);
            }

            int i = 0;
            tmp = poczatek;
            while(tmp != NULL){

                    if(tmp->id == a){
                        tmp = tmp->nastepny;
                        i++;
                    }

                    else {
                        tmp = tmp->nastepny;
                    }
                }

            if(i<1){
                system("cls");
                printf("Nie ma pacjenta o podanym ID!!\n\n");
                usuwanie_pacjentow(lista3);
            }

            tmp = poczatek;


            while(tmp){
                if(tmp->id==a){
                        if(poprzedni==NULL){
                            struct pacjenci *poczatek = tmp->nastepny;
                            free(tmp);
                            return poczatek;
                        }

                        else{
                            poprzedni->nastepny=tmp->nastepny;
                            free(tmp);
                            return lista3;
                        }
                }

                else{
                    poprzedni=tmp;
                    tmp=tmp->nastepny;
                }
            }

    if(poczatek->id == a){
                poczatek = poczatek->nastepny;
            }

return lista3;
}

/// Funkcja umozliwiajaca edycje pacjentow wedlug podanego ID; funkcja pozwala na wprowadzenie kazdej nowej danej z osobna (ID, imie, nazwisko etc).\image html pawel.png
int edycja_pacjentow(){

    if(poczatek == NULL){
            system("cls");
            printf("Baza pacjentow jest pusta !!\n\n");
            return 0;
        }

    dodaj_wpis = poczatek;
    int a,b; /// Zmienna 'a' odpowiada za przechowywanie ID pacjenta, ktorego dane beda podlegaly edycji; zmienna 'b' - za wybor pola do edycji.

            printf("Podaj numer ID pacjenta, ktorego dane chcesz edytowac: ");
            scanf("%d", &a);

            while(koniec->id < a){
                printf("Nie znaleziono pacjenta o podanym ID!!\n\n");
                edycja_pacjentow();
            }

            int i = 0;
            dodaj_wpis = poczatek;
            while(dodaj_wpis != NULL){

                    if(dodaj_wpis->id == a){
                        dodaj_wpis = dodaj_wpis->nastepny;
                        i++;

                    }

                    else {
                        dodaj_wpis = dodaj_wpis->nastepny;
                    }
                }
            if(i<1){
                printf("Nie ma pacjenta o podanym ID!!\n\n");
                edycja_pacjentow();
            }


            system("cls");

            dodaj_wpis = poczatek;

            system("cls");

            while(dodaj_wpis != NULL){
                    if(dodaj_wpis->id == a){
                        printf("\n*****************************************************************************************************************************");
                        printf("\nNumer ID: \t\t%d",dodaj_wpis->id);
                        printf("\nImie i nazwisko: \t%s %s \n",dodaj_wpis->imie, dodaj_wpis->nazwisko);
                        printf("PESEL: \t\t\t%s\n",dodaj_wpis->pesel);
                        printf("Data urodzenia: \t%s\n",dodaj_wpis->data_ur);
                        printf("Adres zamieszkania: \t%s %s\n",dodaj_wpis->adres,dodaj_wpis->nr_dom);
                        printf("E-Mail: \t\t%s\n",dodaj_wpis->email);
                        printf("Nr telefonu: \t\t+48 %s\n",dodaj_wpis->telefon);
                        printf("Waga: \t\t\t%s KG \n",dodaj_wpis->waga);
                        printf("Wzrost: \t\t%s CM \n",dodaj_wpis->wzrost);
                        printf("Oddzial NFZ: \t\t%s\n\n",dodaj_wpis->oddzial);
                        break;
                    }
                    else{
                        dodaj_wpis = dodaj_wpis->nastepny;
                    }
            }

            dodaj_wpis = poczatek;

            printf("Wybierz pole do edycji:\n [1]Imie.\n [2]Nazwisko.\n [3]Pesel.\n [4]Data urodzenia.\n [5]Adres.\n [6]Numer domu.\n [7]Email.\n [8]Telefon.\n [9]Waga.\n [10]Wzrost.\n [11]Oddzial.\n\n [12]MENU.\n");
            scanf("%d", &b);
            while(b > 12 || b == 0){
            printf("Zly numer! Wybierz raz jeszcze!");
            scanf("%d",&b);
        }

        if(poczatek == NULL){
                printf("Err");
                return 0;
        }

            if((poczatek != NULL) && (((poczatek->id) == a)) && ((dodaj_wpis != NULL))){


                if(b==1){
                printf("\nPodaj imie: \n");
                scanf("%s",dodaj_wpis->imie);
                }

                if(b==2){
                printf("Podaj nazwisko: \n");
                scanf("%s",dodaj_wpis->nazwisko);
                }

                if(b==3){
                printf("Podaj pesel: \n");
                scanf("%s", dodaj_wpis->pesel);
                }

                while((strlen(dodaj_wpis->pesel)!=11)){
                    printf("Podany pesel jest nieprawid³owy!!\n");
                    scanf("%s",dodaj_wpis->pesel);
                }

                if(b==4){
                printf("Podaj date urodzenia(DD/MM/RRRR): \n");
                scanf("%s",dodaj_wpis->data_ur);
                }

                if(b==5){
                printf("Podaj miejsce zamieszkania: \n");
                scanf("%s", dodaj_wpis->adres);
                }

                if(b==6){
                printf("Podaj nr domu/mieszkania: \n");
                scanf("%s", dodaj_wpis->nr_dom);
                }

                if(b==7){
                printf("Podaj email: \n");
                scanf("%s", dodaj_wpis->email);
                }

                if(b==8){
                printf("Podaj nr telefonu: \n");
                scanf("%s", dodaj_wpis->telefon);
                }


                while((strlen(dodaj_wpis->telefon)!=9)){
                    printf("Podany nr telefonu jest nieprawidlowy!!\n");
                    scanf("%s",dodaj_wpis->telefon);
                }

                if(b==9){
                printf("Podaj wage(w kg.): \n");
                scanf("%s", dodaj_wpis->waga);
                }

                if(b==10){
                printf("Podaj wzrost(w cm.): \n");
                scanf("%s", dodaj_wpis->wzrost);
                }

                if(b==11){
                printf("Podaj oddzial NFZ: \n");
                scanf("%s", dodaj_wpis->oddzial);
                }

                if(b==12){

                }

                }

            else while((dodaj_wpis!=NULL) && ((dodaj_wpis->id!=a))){

                dodaj_wpis = dodaj_wpis->nastepny;

                if(dodaj_wpis->id ==a){

                system("cls");


                if(b==1){
                printf("\nPodaj imie: \n");
                scanf("%s",dodaj_wpis->imie);
                }

                if(b==2){
                printf("Podaj nazwisko: \n");
                scanf("%s",dodaj_wpis->nazwisko);
                }

                if(b==3){
                printf("Podaj pesel: \n");
                scanf("%s", dodaj_wpis->pesel);

                while((strlen(dodaj_wpis->pesel)!=11)){
                    printf("Podany pesel jest nieprawidlowy!!\n");
                    scanf("%s",dodaj_wpis->pesel);
                    }
                }

                if(b==4){
                printf("Podaj date urodzenia(DD/MM/RRRR): \n");
                scanf("%s",dodaj_wpis->data_ur);
                }

                if(b==5){
                printf("Podaj miejscowosc zamieszkania: \n");
                scanf("%s", dodaj_wpis->adres);
                }

                if(b==6){
                printf("Podaj nr domu/mieszkania: \n");
                scanf("%s", dodaj_wpis->nr_dom);
                }

                if(b==7){
                printf("Podaj email: \n");
                scanf("%s", dodaj_wpis->email);
                }

                if(b==8){
                printf("Podaj nr telefonu: \n");
                scanf("%s", dodaj_wpis->telefon);

                while((strlen(dodaj_wpis->telefon)!=9)){
                    printf("Podany nr telefonu jest nieprawidlowy!!\n");
                    scanf("%s",dodaj_wpis->telefon);
                    }
                }

                if(b==9){
                printf("Podaj wage(w kg.): \n");
                scanf("%s", dodaj_wpis->waga);
                }

                if(b==10){
                printf("Podaj wzrost(w cm.): \n");
                scanf("%s", dodaj_wpis->wzrost);
                }

                if(b==11){
                printf("Podaj oddzial NFZ: \n");
                scanf("%s", dodaj_wpis->oddzial);
                }

                if(b==12){
                    break;
                }


                }
        }
        int g;
        printf("Czy nadal chcesz edytowac? \n[1]Tak.\n[2]Nie.\n");
        scanf("%d", &g);
        if(g==1){
            edycja_pacjentow();
        }
        else if(g==2){
            return 0;
        }
        else while( g == 0 || g > 2){
            printf("Wybierz poprawny numer!\n[1]Tak.\n[2]Nie.");
            scanf("%d", &g);
        }
return 0;
}

///Funkcja pozwalajaca na wyszukiwanie pacjenta wg ID, imienia, nazwiska, numeru PESEL lub Oddzialu NFZ.\image html zacharz.png
int menu_wyszukiwania_pacjentow(){

    if(poczatek == NULL){
            printf("Baza pacjentow jest pusta !!\n\n");
            return 0;
        }
    int id_dzialania; /// Zmienna pozwalajaca wybrac typ szukanej przez nas danej (ID, imie, nazwisko etc).
    void wyswietl_dane_pacjentow(); /// Inicjacja funkcji 'wyswietl_dane_pacjentow()'.

    int id_pacjenta; /// Zmienna typu int, odpowiadajaca za przechowywanie ID szukanego pacjenta.
    char imie_pacjenta[ROZMIAR]; /// Zmienna typu char, przechowujaca imie szukanego pacjenta.
    char nazwisko_pacjenta[ROZMIAR]; /// Zmienna typu char, przechowujaca nazwisko szukanego pacjenta.
    char pesel_pacjenta[ROZMIAR]; /// Zmienna typu char, przechowujaca PESEL szukanego pacjenta.
    char oddzial_pacjenta[ROZMIAR]; /// Zmienna typu char, przechowujaca oddzial szukanego pacjenta.

    int i = 0;

    dodaj_wpis = poczatek; /// Zapisanie wartosci wskaznika 'poczatek' do wskaznika 'dodaj_wpis'.

        printf("Po ktorym polu chcesz wyszukac?\n");
        printf("1.ID\n2.Imie\n3.Nazwisko\n4.PESEL\n5.Oddzial NFZ.\n");
        scanf("%d",&id_dzialania);
        while(id_dzialania > 5 || id_dzialania == 0){
            printf("Zly numer! Wybierz raz jeszcze!");
            scanf("%d",&id_dzialania);
        }

        if(id_dzialania == 1){
            printf("Podaj ID szukanego pacjenta:");
            scanf("%d", &id_pacjenta);

            while(dodaj_wpis != NULL){

                    if(dodaj_wpis->id == id_pacjenta){
                        wyswietl_dane_pacjentow(dodaj_wpis);
                        dodaj_wpis = dodaj_wpis->nastepny;
                        i++;
                    }

                    else {
                        dodaj_wpis = dodaj_wpis->nastepny;
                    }

                }
            }


        if(id_dzialania == 2){
            printf("Podaj imie szukanego pacjenta:");
            scanf("%s", imie_pacjenta);

            while(dodaj_wpis != NULL){

                    if(stricmp(dodaj_wpis->imie, imie_pacjenta)==0){
                        wyswietl_dane_pacjentow(dodaj_wpis);
                        dodaj_wpis = dodaj_wpis->nastepny;
                        i++;

                    }

                    else{
                        dodaj_wpis = dodaj_wpis->nastepny;
                    }
                }
            }


        if(id_dzialania == 3){
            printf("Podaj nazwisko szukanego pacjenta:");
            scanf("%s", nazwisko_pacjenta);

            while(dodaj_wpis != NULL){

                    if(stricmp(dodaj_wpis->nazwisko, nazwisko_pacjenta)==0){
                        wyswietl_dane_pacjentow(dodaj_wpis);
                        dodaj_wpis = dodaj_wpis->nastepny;
                        i++;

                    }

                    else{
                        dodaj_wpis = dodaj_wpis->nastepny;
                    }
                }
            }


        if(id_dzialania == 4){
            printf("Podaj pesel szukanego pacjenta:");
            scanf("%s", pesel_pacjenta);

            while(dodaj_wpis != NULL){

                    if(stricmp(dodaj_wpis->pesel, pesel_pacjenta)==0){
                        wyswietl_dane_pacjentow(dodaj_wpis);
                        dodaj_wpis = dodaj_wpis->nastepny;
                        i++;

                    }

                    else{
                        dodaj_wpis = dodaj_wpis->nastepny;
                    }
                }
            }


        if(id_dzialania == 5){
            printf("Podaj oddzial szukanego pacjenta:");
            scanf("%s", oddzial_pacjenta);

            while(dodaj_wpis != NULL){

                    if(stricmp(dodaj_wpis->oddzial, oddzial_pacjenta)==0){
                        wyswietl_dane_pacjentow(dodaj_wpis);
                        dodaj_wpis = dodaj_wpis->nastepny;
                        i++;

                    }
                    else{
                        dodaj_wpis = dodaj_wpis->nastepny;
                    }
                }
            }

        if(id_dzialania > 5){
            printf("Wybierz wlasciwa liczbe !");
        }

        if(i<1){
            printf("Nie znaleziono uzytkownika o podanych danych.\n");
        }

        printf("\nChcesz wyszukac ponownie?\n[1]Tak.\n[2]Nie.\n.\n");
                        int q;
                        scanf("%d", &q);
                        if(q==1){
                            system("cls");
                            menu_wyszukiwania_pacjentow();
                        }
                        else if(q==2){
                            return 0;
                        }
                        else while( q == 0 || q > 2){
                            printf("Wybierz poprawny numer!\n[1]Tak.\n[2]Nie.");
                            scanf("%d", &q);
                        }
return 0;
}

///Ponizsza funkcja pozwala na wyswietlenie wszystkich szcegolowych danych wybranego pacjenta.\image html wdp.png
void wyswietl_dane_pacjentow(struct pacjenci *dodaj_wpis){

            printf("\n*****************************************************************************************************************************");
            printf("\nNumer ID: \t\t%d",dodaj_wpis->id);
            printf("\nImie i nazwisko: \t%s %s \n",dodaj_wpis->imie, dodaj_wpis->nazwisko);
            printf("PESEL: \t\t\t%s\n",dodaj_wpis->pesel);
            printf("Data urodzenia: \t%s\n",dodaj_wpis->data_ur);
            printf("Adres zamieszkania: \t%s %s\n",dodaj_wpis->adres,dodaj_wpis->nr_dom);
            printf("E-Mail: \t\t%s\n",dodaj_wpis->email);
            printf("Nr telefonu: \t\t+48 %s\n",dodaj_wpis->telefon);
            printf("Waga: \t\t\t%s KG \n",dodaj_wpis->waga);
            printf("Wzrost: \t\t%s CM \n",dodaj_wpis->wzrost);
            printf("Oddzial NFZ: \t\t%s\n",dodaj_wpis->oddzial);
}

/// Funkcja zamieniajaca dane dwoch pacjentow, przekazanych przez argument funkcji jako wskazniki na odpowiednie struktury;\image html sp.png Zamiana danych odbywa sie w odpowiednim miejscu wywolania w kodzie programu.
void swap_pacjenci(struct pacjenci *a, struct pacjenci *b){

    struct pacjenci *temp = (struct pacjenci *)malloc(sizeof(struct pacjenci));

    temp->id = a->id;
    strcpy(temp->imie,a->imie);
    strcpy(temp->nazwisko,a->nazwisko);
    strcpy(temp->pesel,a->pesel);
    strcpy(temp->waga,a->waga);
    strcpy(temp->wzrost,a->wzrost);
    strcpy(temp->oddzial,a->oddzial);

    a->id = b->id;
    strcpy(a->imie,b->imie);
    strcpy(a->nazwisko,b->nazwisko);
    strcpy(a->pesel,b->pesel);
    strcpy(a->waga,b->waga);
    strcpy(a->wzrost,b->wzrost);
    strcpy(a->oddzial,b->oddzial);

    b->id = temp->id;
    strcpy(b->imie,temp->imie);
    strcpy(b->nazwisko,temp->nazwisko);
    strcpy(b->pesel,temp->pesel);
    strcpy(b->waga,temp->waga);
    strcpy(b->wzrost,temp->wzrost);
    strcpy(b->oddzial,temp->oddzial);


}

/// Funkcja odpowiedzialna za dzialanie menu sortowania pacjentow - sortowanie rosnaco i malejaco, wg odpowiednich pol (imie, nazwisko, PESEL etc).\image html sort2.png
int menu_sortowania_pacjentow(struct pacjenci *lista){

        int a,b; /// Zmienne typu int, odpowiadajace: zmienna 'a' za wybor trybu sortowania (rosnaco/malejaco), 'b' - za pole, wg ktorego odbedzie sie sortowanie.
        system("cls");

        if(poczatek == NULL){
            printf("Baza pacjentow jest pusta!! \n\n");
            return 0;
        }

        printf("Jak chcesz posortowac dane? \n[1]Rosnaco. \n[2]Malejaco.\n");
        scanf("%d", &a);

        if(a==1){

        printf("WYBIERZ POLE PO KTORYM CHCESZ POSORTOWAC PACJENTOW:\n [1]Imie,\n [2]Nazwisko,\n [3]Pesel,\n [4]Waga,\n [5]Wzrost,\n [6]Oddzial.\n\n [7]MENU.\n");
        scanf("%d", &b);

        switch(b){

            case 1:
                sort_od_min_pacj(sort_pacjenci_imie);
                pokaz_pacjentow(lista);
                break;
            case 2:
                sort_od_min_pacj(sort_pacjenci_nazwisko);
                pokaz_pacjentow(lista);
                break;
            case 3:
                sort_od_min_pacj(sort_pacjenci_pesel);
                pokaz_pacjentow(lista);
                break;
            case 4:
                sort_od_min_pacj(sort_pacjenci_waga);
                pokaz_pacjentow(lista);
                break;
            case 5:
                sort_od_min_pacj(sort_pacjenci_wzrost);
                pokaz_pacjentow(lista);
                break;
            case 6:
                sort_od_min_pacj(sort_pacjenci_oddzial);
                pokaz_pacjentow(lista);
                break;
            case 7:
                break;
            default:
                break;
        }
    }

    else if (a==2){

        printf("WYBIERZ POLE PO KTORYM CHCESZ POSORTOWAC PACJENTOW:\n [1]Imie,\n [2]Nazwisko,\n [3]Pesel,\n [4]Waga,\n [5]Wzrost,\n [6]Oddzial.\n\n [7]MENU.\n");
        scanf("%d", &b);

        switch(b){

            case 1:
                sort_od_max_pacj(sort_pacjenci_imie);
                pokaz_pacjentow(lista);
                break;
            case 2:
                sort_od_max_pacj(sort_pacjenci_nazwisko);
                pokaz_pacjentow(lista);
                break;
            case 3:
                sort_od_max_pacj(sort_pacjenci_pesel);
                pokaz_pacjentow(lista);
                break;
            case 4:
                sort_od_max_pacj(sort_pacjenci_waga);
                pokaz_pacjentow(lista);
                break;
            case 5:
                sort_od_max_pacj(sort_pacjenci_wzrost);
                pokaz_pacjentow(lista);
                break;
            case 6:
                sort_od_max_pacj(sort_pacjenci_oddzial);
                pokaz_pacjentow(lista);
                break;
            case 7:
                break;
            default:
                break;
        }
    }

    else{
        return 0;
    }
    return 0;
}

/// Sortowanie pacjentow wg imienia:\image html spi.png
int sort_pacjenci_imie(struct pacjenci* a, struct pacjenci* b){

    return stricmp(a->imie,b->imie);
}

/// Sortowanie pacjentow wg nazwiska:\image html spn.png
int sort_pacjenci_nazwisko(struct pacjenci* a, struct pacjenci* b){

    return stricmp(a->nazwisko,b->nazwisko);
}

/// Sortowanie pacjentow wg numeru PESEL:\image html spp.png
int sort_pacjenci_pesel(struct pacjenci* a, struct pacjenci* b){

    return stricmp(a->pesel,b->pesel);
}

/// Sortowanie pacjentow wg wagi:\image html spwa.png
int sort_pacjenci_waga(struct pacjenci* a, struct pacjenci* b){

    return stricmp(a->waga,b->waga);
}

/// Sortowanie pacjentow wg wzrostu:\image html wzrost.png
int sort_pacjenci_wzrost(struct pacjenci* a, struct pacjenci* b){

    return stricmp(a->wzrost,b->wzrost);
}

/// Sortowanie pacjentow wg numeru oddzialu:\image html spo.png
int sort_pacjenci_oddzial(struct pacjenci* a, struct pacjenci* b){

    return stricmp(a->oddzial,b->oddzial);
}

/// Funkcja sortujaca pacjentow rosnaco.\image html srosn.png
void sort_od_min_pacj(int(*porownaj)(struct pacjenci* pierwszy, struct pacjenci* drugi)){

    int swapped; /// Zmienna typu int, okreslajaca, czy dalej ma sie dokonywac zamiana kolejnej pary danych pacjentow.

    struct pacjenci *lptr = NULL; /// Zmienna tymczasowa, niezbedna do przeprowadzenia sortowania babelkowego.
    struct pacjenci *ptr1; /// Zmienna tymczasowa, niezbedna do przeprowadzenia sortowania babelkowego.
    do
    {
        swapped = 0; /// Zmienna typu int, okreslajaca, czy dalej ma sie dokonywac zamiana kolejnej pary danych pacjentow.
        ptr1 = poczatek; /// Wskaznik przechowujacy wartosc wskaznika 'poczatek'.

        while (ptr1->nastepny != lptr)
        {
            if (porownaj(ptr1, ptr1->nastepny) > 0)
            {
                swap_pacjenci(ptr1, ptr1->nastepny);
                swapped = 1;
            }
            ptr1 = ptr1->nastepny;
        }
        lptr = ptr1;
    }
    while (swapped);

}

/// Funkcja sortujaca pacjentow malejaco.\image html smalej.png
void sort_od_max_pacj(int(*porownaj)(struct pacjenci* pierwszy, struct pacjenci* drugi)){

    int swapped; /// Zmienna typu int, okreslajaca, czy dalej ma sie dokonywac zamiana kolejnej pary danych pacjentow.

    struct pacjenci *lptr = NULL;
    struct pacjenci *ptr1;
    do
    {
        swapped = 0;
        ptr1 = poczatek;

        while (ptr1->nastepny != lptr)
        {
            if (porownaj(ptr1, ptr1->nastepny) < 0)
            {
                swap_pacjenci(ptr1, ptr1->nastepny);
                swapped = 1;
            }
            ptr1 = ptr1->nastepny;
        }
        lptr = ptr1;
    }
    while (swapped);

}
