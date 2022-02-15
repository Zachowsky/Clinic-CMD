#include "lekarze.h"
#include "pacjenci.h"

struct lekarze *poczatek1 = NULL; /// Wyzerowany wskaznik odpowiadajacy za poczatek listy lekarzy.
struct lekarze *koniec1 = NULL; /// Wyzerowany wskaznik odpowiadajacy za koniec listy lekarzy.


/// Funkcja odpowiedzialna za tworzenie nowego wpisu lekarza; najpierw alokowana jest odpowiednia ilosc pamieci, potem obsluga bledow zwiazanych wlasnie z alokacja pamieci dla wskaznika 'dodaj_wpis1', odpowiedzialnego za dane lekarzy; funkcja ta pozwala rowniez na wprowadzenie godzin pracy lekarza. \image html nowyl.png
int nowy_lekarz(int id1){

    dodaj_wpis1 = malloc(sizeof (struct lekarze)); /// Zmienna przechowujaca wskaznik do nowo zaalokowanego bloku pamieci.

    if(!dodaj_wpis1){
        printf("Nie dziala.");
        perror("malloc");
        return EXIT_FAILURE;
    }

    if (dodaj_wpis1!=NULL){

        system("cls");

        dodaj_wpis1-> id=id1;

        printf("\nPodaj imie: \n");
        scanf("%s",dodaj_wpis1->imie);

        printf("Podaj nazwisko: \n");
        scanf("%s",dodaj_wpis1->nazwisko);

        printf("Podaj pesel: \n");
        scanf("%s", dodaj_wpis1->pesel);

        while((strlen(dodaj_wpis1->pesel)!=11)){
            printf("Podany pesel jest nieprawid³owy!!\n");
            scanf("%s",dodaj_wpis1->pesel);
        }


        printf("Podaj nr PWZ: \n");
        scanf("%s",dodaj_wpis1->numer_pwz);

        printf("Podaj tytul zawodowy: \n");
        scanf("%s", dodaj_wpis1->tytul_zawodowy);

        printf("Podaj specjalizacje: \n");
        scanf("%s", dodaj_wpis1->specjalizacja);

        printf("Podaj e-mail: \n");
        scanf("%s", dodaj_wpis1->email);

        printf("Podaj nr telefonu: \n");
        scanf("%s", dodaj_wpis1->telefon);

        while((strlen(dodaj_wpis1->telefon)!=9)){
                printf("Podany nr telefonu jest nieprawidlowy!!\n");
                scanf("%s",dodaj_wpis1->telefon);
            }

        int y = 1;

        strcpy(dodaj_wpis1->dni_pracy, "0000000");

        while(y==1){

            printf("Wybierz dni pracy lekarza: \n[0]Poniedzialek.\n[1]Wtorek.\n[2]Sroda.\n[3]Czwartek.\n[4]Piatek.\n[5]Sobota.\n[6]Niedziela.");
            int wybierz_dzien; /// Zmienna typu int, pozwalajaca wprowadzic dni pracy lekarza.
            scanf("%d", &wybierz_dzien);


                if(wybierz_dzien == 0){
                    if( dodaj_wpis1->dni_pracy[0] == '0'){
                        dodaj_wpis1->dni_pracy[0] = '1';
                    }
                }

                if(wybierz_dzien == 1){
                    if( dodaj_wpis1->dni_pracy[1] == '0'){
                        dodaj_wpis1->dni_pracy[1] = '1';
                    }
                }

                if(wybierz_dzien == 2){
                    if( dodaj_wpis1->dni_pracy[2] == '0'){
                        dodaj_wpis1->dni_pracy[2] = '1';
                    }
                }

                if(wybierz_dzien == 3){
                    if( dodaj_wpis1->dni_pracy[3] == '0'){
                        dodaj_wpis1->dni_pracy[3] = '1';
                    }
                }

                if(wybierz_dzien == 4){
                    if( dodaj_wpis1->dni_pracy[4] == '0'){
                        dodaj_wpis1->dni_pracy[4] = '1';
                    }
                }

                if(wybierz_dzien == 5){
                    if( dodaj_wpis1->dni_pracy[5] == '0'){
                        dodaj_wpis1->dni_pracy[5] = '1';
                    }
                }

                if(wybierz_dzien == 6){
                    if( dodaj_wpis1->dni_pracy[6] == '0'){
                        dodaj_wpis1->dni_pracy[6] = '1';
                    }
                }


            printf("Czy chcesz dodac kolejny dzien?\n[1]Tak.\n[2]Nie.");
            int y; /// Zmienna typu int, odpowiadajaca za to, czy chcemy dodac kolejny dzien do pracy lekarza.
            scanf("%d", &y);
            if(y==1){
                printf("Wybierz dzien ktory chcesz dodac: ");

            }
            else if(y==2){
                break;
            }
            else while(y != 1 && y != 2){
                printf("Podaj prawidlowy numerek !!");
                scanf("%d", &y);
            }
            printf("\n\n\n%s\n\n\n", dodaj_wpis1->dni_pracy);
        }



        printf("Podaj godzine rozpoczecia pracy: \n");
        scanf("%d", &dodaj_wpis1->godzina_pocz);
        while(dodaj_wpis1->godzina_pocz < 6){
            printf("Godzina rozpoczecia pracy nie moze byc mniejsza niz 06:00 !\n");
            scanf("%d", &dodaj_wpis1->godzina_pocz);
        }


        printf("Podaj godzine zakonczenia pracy: \n");
        scanf("%d", &dodaj_wpis1->godzina_kon);
        while(dodaj_wpis1->godzina_kon > 22){
            printf("Godzina zakonczenia pracy nie moze byc wieksza niz 22:00 !\n");
            scanf("%d", &dodaj_wpis1->godzina_kon);
        }
        while(dodaj_wpis1->godzina_pocz == dodaj_wpis1->godzina_kon){
            printf("Godzina rozpoczecia pracy nie moze byc taka sama jak godzina zakonczenia pracy !!\n");
            printf("Podaj godzine rozpoczecia pracy: \n");
            scanf("%d", &dodaj_wpis1->godzina_pocz);
            printf("Podaj godzine zakonczenia pracy: \n");
            scanf("%d", &dodaj_wpis1->godzina_kon);
        }
        while(dodaj_wpis1->godzina_kon < dodaj_wpis1->godzina_pocz){
            printf("Nieprawidlowe godziny pracy, wprowadz ponownie !\n");
            printf("Podaj godzine rozpoczecia: ");
            scanf("%d", &dodaj_wpis1->godzina_pocz);
            printf("Podaj godzine zakonczenia: ");
            scanf("%d", &dodaj_wpis1->godzina_kon);
        }
    }
        dodaj_wpis1 -> nastepny1 = NULL; /// Wyzerowanie zawartosci elementu 'nastepny1' wskaznika 'dodaj_wpis'

        if(koniec1 == NULL){
                poczatek1 = koniec1 = dodaj_wpis1;
          }

        else{
                koniec1->nastepny1 = dodaj_wpis1;
                koniec1 = dodaj_wpis1;
        }

            int n;
            printf("\n\nCzy chcesz dodac kolejnego lekarza?\n[1]Tak.\n[2]Nie.");
            scanf("%d", &n);
            if(n==1){
                id1++;
                nowy_lekarz(id1);

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

/// Funkcja odpowiadajaca za wyswietlanie listy zapisanych lekarzy. Dziala podobnie jak funkcja 'pokaz_pacjentow()'; zastosowalismy tu petle while() i przechodzenie do kazdego kolejnego elementu listy. \image html pol.png
void pokaz_lekarzy(){

    system("cls");

        if(poczatek1 != NULL){
                dodaj_wpis1 = poczatek1;
        }

        else{
            dodaj_wpis1 = NULL;
            }

        if(dodaj_wpis1 == NULL){
                printf("\nBaza lekarzy jest pusta!! \n\n");
        }

        else  while(dodaj_wpis1 != NULL){

                printf("\n*****************************************************************************************************************************");
                printf("\nNumer ID: \t\t%d",dodaj_wpis1->id);
                printf("\nImie i Nazwisko: \t%s %s\n",dodaj_wpis1->imie,dodaj_wpis1->nazwisko);
                printf("PESEL: \t\t\t%s\n",dodaj_wpis1->pesel);
                printf("Nr PWZ: \t\t%s\n",dodaj_wpis1->numer_pwz);
                printf("Tytul zawodowy: \t%s\n",dodaj_wpis1->tytul_zawodowy);
                printf("Specjalizacja: \t\t%s\n",dodaj_wpis1->specjalizacja);
                printf("E-Mail: \t\t%s\n",dodaj_wpis1->email);
                printf("Nr telefonu: \t\t+48 %s\n",dodaj_wpis1->telefon);
                printf("Dni pracy: \t\t");
                if(dodaj_wpis1->dni_pracy[0] == '1'){
                    printf("Poniedzialek,");
                }
                if(dodaj_wpis1->dni_pracy[1] == '1'){
                    printf("Wtorek,");
                }
                if(dodaj_wpis1->dni_pracy[2] == '1'){
                    printf("Sroda,");
                }
                if(dodaj_wpis1->dni_pracy[3] == '1'){
                    printf("Czwartek,");
                }
                if(dodaj_wpis1->dni_pracy[4] == '1'){
                    printf("Piatek,");
                }
                if(dodaj_wpis1->dni_pracy[5] == '1'){
                    printf("Sobota,");
                }
                if(dodaj_wpis1->dni_pracy[6] == '1'){
                    printf("Niedziela,");
                }
                printf("\nGodziny pracy: \t\t%d.00 - %d.00\n",dodaj_wpis1->godzina_pocz, dodaj_wpis1->godzina_kon);

                dodaj_wpis1 = dodaj_wpis1 -> nastepny1;
        }
}

/// Funkcja pozwalajaca na wczytanie listy lekarzy z pliku "Baza_Przychodnia_Lekarze.txt"; wczytanie odbywa sie automatycznie podczas ladowania programu.\image html kod2.png
void wczytaj_lekarzy(char *nazwa_pliku) {

    FILE *wpp; /// Wskaznik na nowo otwarty do odczytu plik "Baza_Przychodnia_Lekarze.txt".
    wpp = fopen(nazwa_pliku, "r");

    if (wpp != NULL){

        if((feof(wpp)==0) && (fgetc(wpp)<2)){


            fclose(wpp);
            remove(nazwa_pliku);
          }


        else{

            while(feof(wpp) == 0){
              dodaj_wpis1 = malloc(sizeof (struct lekarze));

              fscanf(wpp, "%d", &dodaj_wpis1->id);
              fscanf(wpp, "%s", dodaj_wpis1->imie);
              fscanf(wpp, "%s", dodaj_wpis1->nazwisko);
              fscanf(wpp, "%s", dodaj_wpis1->pesel);
              fscanf(wpp, "%s", dodaj_wpis1->numer_pwz);
              fscanf(wpp, "%s", dodaj_wpis1->tytul_zawodowy);
              fscanf(wpp, "%s", dodaj_wpis1->specjalizacja);
              fscanf(wpp, "%s", dodaj_wpis1->email);
              fscanf(wpp, "%s", dodaj_wpis1->telefon);
              fscanf(wpp, "%s", dodaj_wpis1->dni_pracy);
              fscanf(wpp, "%d", &dodaj_wpis1->godzina_pocz);
              fscanf(wpp, "%d", &dodaj_wpis1->godzina_kon);

              dodaj_wpis1 -> nastepny1 = NULL;

              if (koniec1 != NULL){

                    koniec1->nastepny1 = dodaj_wpis1;
                    koniec1 = dodaj_wpis1;
              }

              else{
                    koniec1 = poczatek1 = dodaj_wpis1;
                }
            }
        }
            fclose(wpp);
    }
}

/// Funkcja zapisujaca liste wszystkich lekarzy do pliku "Baza_Przychodnia_Lekarze.txt"; zapis do pliku dokonuje sie w odpowiednim miejscu programu automatycznie.\image html zapis.png
void zapisz_do_pliku_lekarzy(char* nazwa_pliku){

    FILE* wpp; /// Wskaznik na plik otwarty do zapisu ponizej.
    wpp = fopen(nazwa_pliku, "w");

    dodaj_wpis1 = poczatek1;

        while(dodaj_wpis1 != NULL) {

            fprintf(wpp, "\n\n");
            fprintf(wpp, "%d\n", dodaj_wpis1->id);
            fprintf(wpp, "%s\n", dodaj_wpis1->imie);
            fprintf(wpp, "%s\n", dodaj_wpis1->nazwisko);
            fprintf(wpp, "%s\n", dodaj_wpis1->pesel);
            fprintf(wpp, "%s\n", dodaj_wpis1->numer_pwz);
            fprintf(wpp, "%s\n", dodaj_wpis1->tytul_zawodowy);
            fprintf(wpp, "%s\n", dodaj_wpis1->specjalizacja);
            fprintf(wpp, "%s\n", dodaj_wpis1->email);
            fprintf(wpp, "%s\n", dodaj_wpis1->telefon);
            fprintf(wpp, "%s\n", dodaj_wpis1->dni_pracy);
            fprintf(wpp, "%d\n", dodaj_wpis1->godzina_pocz);
            fprintf(wpp, "%d", dodaj_wpis1->godzina_kon);
            dodaj_wpis1 = dodaj_wpis1 -> nastepny1;
        }
    fclose(wpp);
}

/// Funkcja odpowiadajaca za usuwanie lekarzy. Oparta jest na petli while(), czyszczac kazdy element, przechodzac kolejno az do napotkania wartosci NULL we wskazniku 'poczatek1'; zastosowano tu funkcje 'free();'. \image html az1.png
struct lekarze *usuwanie_lekarzy(struct lekarze *lista1){

    int a;
    struct lekarze *poprzedni1 = NULL; /// Wyzerowanie wskaznika 'poprzedni1', odpowiadajacego za poprzedni element na liscie lekarzy.
    struct lekarze *tmp1 = lista1; /// Wskaznik tymczasowy, niezbedny do procesu usuwania lekarza.
    tmp1 = poczatek1;
    int b = 0;

        if(tmp1 == NULL){
            system("cls");
            printf("Baza lekarzy jest pusta !!\n\n");
            return 0;
        }

        printf("Podaj numer ID lekarza, ktorego chcesz usunac: \n");
        scanf("%d", &a);

            while(koniec1->id < a){
                printf("Podano zly numer!!");
                printf("Podaj numer ID lekarza, ktorego chcesz usunac: \n");
                scanf("%d", &a);
            }
        tmp1 = poczatek1;

        while(tmp1!=NULL){
            if(tmp1->id == a){
                b++;
            }
            tmp1 = tmp1->nastepny1;
        }

        if(b<1){
            printf("Podano zly numer!!");
            usuwanie_lekarzy(lista1);
        }

        tmp1 = poczatek1;
         while(tmp1->id != NULL){
                    if(a == tmp1->id){
                            system("cls");
                            printf("\n*****************************************************************************************************************************");
                            printf("\nNumer ID lekarza: \t\t%d",tmp1->id);
                            printf("\nImie i nazwisko lekarza: \t%s %s", tmp1->imie,tmp1->nazwisko);
                            break;
                    }
                    else{
                        tmp1 = tmp1->nastepny1;
                    }
                }

            printf("\n\nCzy tego lekarza chcesz usunac?\n[1]Tak.\n[2]Nie.\n");
            int u;
            scanf("%d", &u);
            if(u==1){
            }
            else if(u==2){
                usuwanie_lekarzy(lista1);
            }

            int i = 0;
            tmp1 = poczatek1;
            while(tmp1 != NULL){

                    if(tmp1->id == a){
                        tmp1 = tmp1->nastepny1;
                        i++;
                    }

                    else {
                        tmp1 = tmp1->nastepny1;
                    }
                }
            if(i<1){
                system("cls");
                printf("Nie ma lekarza o podanym ID!!\n\n");
                usuwanie_lekarzy(lista1);
            }
            tmp1 = poczatek1;


            while(tmp1){
                if(tmp1->id==a){
                        if(poprzedni1==NULL){
                            struct lekarze *poczatek1 = tmp1->nastepny1;
                            free(tmp1);
                            return poczatek1;
                        }
                        else{
                            poprzedni1->nastepny1=tmp1->nastepny1;
                            free(tmp1);
                           return lista1;
                        }
                }
                else{
                    poprzedni1=tmp1;
                    tmp1=tmp1->nastepny1;
                }
    }
return 0;
}

/// Funkcja pozwalajaca na edycje danych lekarzy; elementem, wg ktorego dokonujemy edycji danych, jest ID; zastosowano tu szereg zabezpieczen, niezbednych do prawidlowego wprowadzenia zadanych danych. \image html edita.png

int edycja_lekarzy(){

if(dodaj_wpis1 == NULL){
            system("cls");
            printf("Baza lekarzy jest pusta !!\n\n");
            return 0;
        }
    dodaj_wpis1 = poczatek1;
    int a, b;

            printf("Podaj numer ID lekarza, ktorego dane chcesz edytowac: ");
            scanf("%d", &a);
            while(koniec1->id < a){
                printf("Nie znaleziono lekarza o podanym ID!!\n\n");
                edycja_lekarzy();
            }

            int i = 0;
            dodaj_wpis1 = poczatek1;
            while(dodaj_wpis1 != NULL){

                    if(dodaj_wpis1->id == a){
                        dodaj_wpis1 = dodaj_wpis1->nastepny1;
                        i++;

                    }

                    else {
                        dodaj_wpis1 = dodaj_wpis1->nastepny1;
                    }
                }
            if(i<1){
                printf("Nie ma lekarza o podanym ID!!\n\n");
                edycja_lekarzy();
            }

            system("cls");

            dodaj_wpis1 = poczatek1;

            system("cls");

            while(dodaj_wpis1 != NULL){
                    if(dodaj_wpis1->id == a){
                        printf("\n*****************************************************************************************************************************");
                        printf("\nNumer ID: \t\t%d",dodaj_wpis1->id);
                        printf("\nImie i Nazwisko: \t%s %s\n",dodaj_wpis1->imie,dodaj_wpis1->nazwisko);
                        printf("PESEL: \t\t\t%s\n",dodaj_wpis1->pesel);
                        printf("Nr PWZ: \t\t%s\n",dodaj_wpis1->numer_pwz);
                        printf("Tytul zawodowy: \t%s\n",dodaj_wpis1->tytul_zawodowy);
                        printf("Specjalizacja: \t\t%s\n",dodaj_wpis1->specjalizacja);
                        printf("E-Mail: \t\t%s\n",dodaj_wpis1->email);
                        printf("Nr telefonu: \t\t+48 %s\n",dodaj_wpis1->telefon);
                        printf("Dni pracy: \t\t");
                            if(dodaj_wpis1->dni_pracy[0] == '1'){
                                printf("Poniedzialek,");
                            }
                            if(dodaj_wpis1->dni_pracy[1] == '1'){
                                printf("Wtorek,");
                            }
                            if(dodaj_wpis1->dni_pracy[2] == '1'){
                                printf("Sroda,");
                            }
                            if(dodaj_wpis1->dni_pracy[3] == '1'){
                                printf("Czwartek,");
                            }
                            if(dodaj_wpis1->dni_pracy[4] == '1'){
                                printf("Piatek,");
                            }
                            if(dodaj_wpis1->dni_pracy[5] == '1'){
                                printf("Sobota,");
                            }
                            if(dodaj_wpis1->dni_pracy[6] == '1'){
                                printf("Niedziela,");
                            }
                        printf("\nGodziny pracy: \t\t%d.00 - %d.00\n",dodaj_wpis1->godzina_pocz, dodaj_wpis1->godzina_kon);
                        break;
                    }
                    else{
                        dodaj_wpis1 = dodaj_wpis1->nastepny1;
                    }
            }

            dodaj_wpis1 = poczatek1;

            printf("\n\nWybierz pole do edycji: \n [1]Imie.\n [2]Nazwisko.\n [3]Pesel.\n [4]Numer PWZ.\n [5]Tytul zawodowy.\n [6]Specjalizacja.\n [7]Email.\n [8]Telefon.\n [9]Dni pracy.\n[10]Godziny pracy.\n\n [11]MENU.\n");
            scanf("%d", &b);
            while(b > 12 || b == 0){
                printf("Zly numer! Wybierz raz jeszcze!");
                scanf("%d",&b);
            }

            if(poczatek1 == NULL){
                printf("Err");

            }

            else if((poczatek1 != NULL) && ((poczatek1->id == a)) && ((dodaj_wpis1 != NULL))){

                system("cls");

                if(b==1){
                printf("\nPodaj imie: \n");
                scanf("%s",dodaj_wpis1->imie);
                }

                if(b==2){
                printf("Podaj nazwisko: \n");
                scanf("%s",dodaj_wpis1->nazwisko);
                }

                if(b==3){
                printf("Podaj pesel: \n");
                scanf("%s", dodaj_wpis1->pesel);


                while((strlen(dodaj_wpis1->pesel)!=11)){
                    printf("Podany pesel jest nieprawidlowy!!\n");
                    scanf("%s",dodaj_wpis1->pesel);
                }
                }

                if(b==4){
                printf("Podaj nr PWZ: \n");
                scanf("%s",dodaj_wpis1->numer_pwz);
                }

                if(b==5){
                printf("Podaj tytul zawodowy: \n");
                scanf("%s", dodaj_wpis1->tytul_zawodowy);
                }

                if(b==6){
                printf("Podaj specjalizacje: \n");
                scanf("%s", dodaj_wpis1->specjalizacja);
                }

                if(b==7){
                printf("Podaj e-mail: \n");
                scanf("%s", dodaj_wpis1->email);
                }

                if(b==8){
                printf("Podaj nr telefonu: \n");
                scanf("%s", dodaj_wpis1->telefon);


                while((strlen(dodaj_wpis1->telefon)!=9)){
                printf("Podany nr telefonu jest nieprawidlowy!!\n");
                scanf("%s",dodaj_wpis1->telefon);
                }
                }

                if(b==9){
                    int y = 1;

                    strcpy(dodaj_wpis1->dni_pracy, "0000000");

                    while(y==1){

                        printf("Wybierz dni pracy lekarza od nowa: \n[0]Poniedzialek.\n[1]Wtorek.\n[2]Sroda.\n[3]Czwartek.\n[4]Piatek.\n[5]Sobota.\n[6]Niedziela.");
                        int wybierz_dzien;
                        scanf("%d", &wybierz_dzien);


                            if(wybierz_dzien == 0){
                                if( dodaj_wpis1->dni_pracy[0] == '0'){
                                    dodaj_wpis1->dni_pracy[0] = '1';
                                }
                            }

                            if(wybierz_dzien == 1){
                                if( dodaj_wpis1->dni_pracy[1] == '0'){
                                    dodaj_wpis1->dni_pracy[1] = '1';
                                }
                            }

                            if(wybierz_dzien == 2){
                                if( dodaj_wpis1->dni_pracy[2] == '0'){
                                    dodaj_wpis1->dni_pracy[2] = '1';
                                }
                            }

                            if(wybierz_dzien == 3){
                                if( dodaj_wpis1->dni_pracy[3] == '0'){
                                    dodaj_wpis1->dni_pracy[3] = '1';
                                }
                            }

                            if(wybierz_dzien == 4){
                                if( dodaj_wpis1->dni_pracy[4] == '0'){
                                    dodaj_wpis1->dni_pracy[4] = '1';
                                }
                            }

                            if(wybierz_dzien == 5){
                                if( dodaj_wpis1->dni_pracy[5] == '0'){
                                    dodaj_wpis1->dni_pracy[5] = '1';
                                }
                            }

                            if(wybierz_dzien == 6){
                                if( dodaj_wpis1->dni_pracy[6] == '0'){
                                    dodaj_wpis1->dni_pracy[6] = '1';
                                }
                            }


                        printf("Czy chcesz dodac kolejny dzien?\n[1]Tak.\n[2]Nie.");
                        int y;
                        scanf("%d", &y);
                        if(y==1){
                            printf("Wybierz dzien ktory chcesz dodac: ");

                        }
                        else if(y==2){
                            break;
                        }
                        else while(y != 1 && y != 2){
                            printf("Podaj prawidlowy numerek !!");
                            scanf("%d", &y);
                        }
                        printf("\n\n\n%s\n\n\n", dodaj_wpis1->dni_pracy);
                    }
                }

                if(b==10){
                printf("Podaj godzine rozpoczecia pracy: \n");
                scanf("%d", &dodaj_wpis1->godzina_pocz);
                while(dodaj_wpis1->godzina_pocz < 6){
                    printf("Godzina rozpoczecia pracy nie moze byc mniejsza niz 06:00 !\n");
                    scanf("%d", &dodaj_wpis1->godzina_pocz);
                }

                printf("Podaj godzine zakonczenia pracy: \n");
                scanf("%d", &dodaj_wpis1->godzina_kon);
                while(dodaj_wpis1->godzina_kon > 22){
                    printf("Godzina zakonczenia pracy nie moze byc wieksza niz 22:00 !\n");
                    scanf("%d", &dodaj_wpis1->godzina_kon);
                }
                while(dodaj_wpis1->godzina_pocz == dodaj_wpis1->godzina_kon){
                    printf("Godzina rozpoczecia pracy nie moze byc taka sama jak godzina zakonczenia pracy !!\n");
                    printf("Podaj godzine rozpoczecia pracy: \n");
                    scanf("%d", &dodaj_wpis1->godzina_pocz);
                    printf("Podaj godzine zakonczenia pracy: \n");
                    scanf("%d", &dodaj_wpis1->godzina_kon);
                }

                while(dodaj_wpis1->godzina_kon < dodaj_wpis1->godzina_pocz){
                    printf("Nieprawidlowe godziny pracy, wprowadz ponownie !\n");
                    printf("Podaj godzine rozpoczecia: ");
                    scanf("%d", &dodaj_wpis1->godzina_pocz);
                    printf("Podaj godzine zakonczenia: ");
                    scanf("%d", &dodaj_wpis1->godzina_kon);
                }
                }

                if(b==11){

                }
                }

            else while((dodaj_wpis1!=NULL) && ((dodaj_wpis1->id!=a))){

                dodaj_wpis1 = dodaj_wpis1->nastepny1;

                if(dodaj_wpis1->id ==a){

                system("cls");

                if(b==1){
                printf("\nPodaj imie: \n");
                scanf("%s",dodaj_wpis1->imie);
                }

                if(b==2){
                printf("Podaj nazwisko: \n");
                scanf("%s",dodaj_wpis1->nazwisko);
                }

                if(b==3){
                printf("Podaj pesel: \n");
                scanf("%s", dodaj_wpis1->pesel);


                while((strlen(dodaj_wpis1->pesel)!=11)){
                    printf("Podany pesel jest nieprawidlowy!!\n");
                    scanf("%s",dodaj_wpis1->pesel);
                }
                }

                if(b==4){
                printf("Podaj nr PWZ: \n");
                scanf("%s",dodaj_wpis1->numer_pwz);
                }

                if(b==5){
                printf("Podaj tytul zawodowy: \n");
                scanf("%s", dodaj_wpis1->tytul_zawodowy);
                }

                if(b==6){
                printf("Podaj specjalizacje: \n");
                scanf("%s", dodaj_wpis1->specjalizacja);
                }

                if(b==7){
                printf("Podaj e-mail: \n");
                scanf("%s", dodaj_wpis1->email);
                }

                if(b==8){
                printf("Podaj nr telefonu: \n");
                scanf("%s", dodaj_wpis1->telefon);

                while((strlen(dodaj_wpis1->telefon)!=9)){
                printf("Podany nr telefonu jest nieprawidlowy!!\n");
                scanf("%s",dodaj_wpis1->telefon);
                    }
                }


                if(b==9){
                    int y = 1;

                    strcpy(dodaj_wpis1->dni_pracy, "0000000");

                    while(y==1){

                        printf("Wybierz dni pracy lekarza: \n[0]Poniedzialek.\n[1]Wtorek.\n[2]Sroda.\n[3]Czwartek.\n[4]Piatek.\n[5]Sobota.\n[6]Niedziela.");
                        int wybierz_dzien;
                        scanf("%d", &wybierz_dzien);


                            if(wybierz_dzien == 0){
                                if( dodaj_wpis1->dni_pracy[0] == '0'){
                                    dodaj_wpis1->dni_pracy[0] = '1';
                                }
                            }

                            if(wybierz_dzien == 1){
                                if( dodaj_wpis1->dni_pracy[1] == '0'){
                                    dodaj_wpis1->dni_pracy[1] = '1';
                                }
                            }

                            if(wybierz_dzien == 2){
                                if( dodaj_wpis1->dni_pracy[2] == '0'){
                                    dodaj_wpis1->dni_pracy[2] = '1';
                                }
                            }

                            if(wybierz_dzien == 3){
                                if( dodaj_wpis1->dni_pracy[3] == '0'){
                                    dodaj_wpis1->dni_pracy[3] = '1';
                                }
                            }

                            if(wybierz_dzien == 4){
                                if( dodaj_wpis1->dni_pracy[4] == '0'){
                                    dodaj_wpis1->dni_pracy[4] = '1';
                                }
                            }

                            if(wybierz_dzien == 5){
                                if( dodaj_wpis1->dni_pracy[5] == '0'){
                                    dodaj_wpis1->dni_pracy[5] = '1';
                                }
                            }

                            if(wybierz_dzien == 6){
                                if( dodaj_wpis1->dni_pracy[6] == '0'){
                                    dodaj_wpis1->dni_pracy[6] = '1';
                                }
                            }


                        printf("Czy chcesz dodac kolejny dzien?\n[1]Tak.\n[2]Nie.");
                        int y;
                        scanf("%d", &y);
                        if(y==1){
                            printf("Wybierz dzien ktory chcesz dodac: ");

                        }
                        else if(y==2){
                            break;
                        }
                        else while(y != 1 && y != 2){
                            printf("Podaj prawidlowy numerek !!");
                            scanf("%d", &y);
                        }
                        printf("\n\n\n%s\n\n\n", dodaj_wpis1->dni_pracy);
                    }
                }

                if(b==10){
                printf("Podaj godzine rozpoczecia pracy: \n");
                scanf("%d", &dodaj_wpis1->godzina_pocz);
                while(dodaj_wpis1->godzina_pocz < 6){
                    printf("Godzina rozpoczecia pracy nie moze byc mniejsza niz 06:00 !\n");
                    scanf("%d", &dodaj_wpis1->godzina_pocz);
                }

                printf("Podaj godzine zakonczenia pracy: \n");
                scanf("%d", &dodaj_wpis1->godzina_kon);
                while(dodaj_wpis1->godzina_kon > 22){
                    printf("Godzina zakonczenia pracy nie moze byc wieksza niz 22:00 !\n");
                    scanf("%d", &dodaj_wpis1->godzina_kon);
                }
                while(dodaj_wpis1->godzina_pocz == dodaj_wpis1->godzina_kon){
                    printf("Godzina rozpoczecia pracy nie moze byc taka sama jak godzina zakonczenia pracy !!\n");
                    printf("Podaj godzine rozpoczecia pracy: \n");
                    scanf("%d", &dodaj_wpis1->godzina_pocz);
                    printf("Podaj godzine zakonczenia pracy: \n");
                    scanf("%d", &dodaj_wpis1->godzina_kon);
                }

                while(dodaj_wpis1->godzina_kon < dodaj_wpis1->godzina_pocz){
                    printf("Nieprawidlowe godziny pracy, wprowadz ponownie !\n");
                    printf("Podaj godzine rozpoczecia: ");
                    scanf("%d", &dodaj_wpis1->godzina_pocz);
                    printf("Podaj godzine zakonczenia: ");
                    scanf("%d", &dodaj_wpis1->godzina_kon);
                }
                }

                if(b==11){
                    break;
                }
                }
        }
         int n;
            printf("\n\nCzy chcesz edytowac kolejnego lekarza?\n[1]Tak.\n[2]Nie.");
            scanf("%d", &n);
            if(n==1){
                edycja_lekarzy();
                return 0;
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

/// Menu pozwalajace na wyszukiwanie lekarzy po ID, imieniu, nazwisku, numeru PESEL, numerze PWZ, tytule zawodowym i specjalizacji; zastosowano tu odpowiednie zabezpieczenia przed wprowadzeniem niewlasciwych danych. \image html szukl.png
int menu_wyszukiwania_lekarzy(){
    if(dodaj_wpis == NULL){
            system("cls");
            printf("Baza lekarzy jest pusta !!\n\n");
            return 0;
        }
    int id_dzialania1;
    void wyswietl_dane_lekarzy();

    int z = 0;

    int id_lekarza;
    char imie_lekarza[ROZMIAR];
    char nazwisko_lekarza[ROZMIAR];
    char pesel_lekarza[ROZMIAR];
    char pwz_lekarza[ROZMIAR];
    char tytul_lekarza[ROZMIAR];
    char specjalizacja_lekarza[ROZMIAR];

    dodaj_wpis1 = poczatek1;

        printf("Po ktorym polu chcesz wyszukac?\n");
        printf("1.ID\n2.Imie\n3.Nazwisko\n4.PESEL\n5.Numer PWZ.\n6.Tytul zawodowy lekarza.\n7.Specjalizacja.\n");
        scanf("%d",&id_dzialania1);
        while(id_dzialania1 > 7 || id_dzialania1 == 0){
            printf("Zly numer! Wybierz raz jeszcze!");
            scanf("%d",&id_dzialania1);
        }

        if(id_dzialania1 == 1){
            printf("Podaj ID szukanego pacjenta:");
            scanf("%d", &id_lekarza);

            while(dodaj_wpis1 != NULL){

                    if(dodaj_wpis1->id == id_lekarza){
                        wyswietl_dane_lekarzy(dodaj_wpis1);
                        dodaj_wpis1 = dodaj_wpis1->nastepny1;
                        z++;
                    }

                    else {
                        dodaj_wpis1 = dodaj_wpis1->nastepny1;
                    }
                }
            }


        if(id_dzialania1 == 2){
            printf("Podaj imie szukanego lekarza:");
            scanf("%s", imie_lekarza);

            while(dodaj_wpis1 != NULL){

                    if(stricmp(dodaj_wpis1->imie, imie_lekarza)==0){
                        wyswietl_dane_lekarzy(dodaj_wpis1);
                        dodaj_wpis1 = dodaj_wpis1->nastepny1;
                        z++;
                    }
                    else{
                        dodaj_wpis1 = dodaj_wpis1->nastepny1;
                    }
                }
            }


        if(id_dzialania1 == 3){
            printf("Podaj oddzial szukanego lekarza:");
            scanf("%s", nazwisko_lekarza);

            while(dodaj_wpis1 != NULL){

                    if(stricmp(dodaj_wpis1->nazwisko, nazwisko_lekarza)==0){
                        wyswietl_dane_lekarzy(dodaj_wpis1);
                        dodaj_wpis1 = dodaj_wpis1->nastepny1;
                        z++;
                    }

                    else{
                        dodaj_wpis1 = dodaj_wpis1->nastepny1;
                    }
                }
            }


        if(id_dzialania1 == 4){
            printf("Podaj pesel szukanego lekarza:");
            scanf("%s", pesel_lekarza);

            while(dodaj_wpis1 != NULL){

                    if(stricmp(dodaj_wpis1->pesel, pesel_lekarza)==0){
                        wyswietl_dane_lekarzy(dodaj_wpis1);
                        dodaj_wpis1 = dodaj_wpis1->nastepny1;
                        z++;
                    }

                    else{
                        dodaj_wpis1 = dodaj_wpis1->nastepny1;
                    }
                }
            }


        if(id_dzialania1 == 5){
            printf("Podaj numer PWZ szukanego lekarza:");
            scanf("%s", pwz_lekarza);

            while(dodaj_wpis1 != NULL){

                    if(stricmp(dodaj_wpis1->numer_pwz, pwz_lekarza)==0){
                        wyswietl_dane_lekarzy(dodaj_wpis1);
                        dodaj_wpis1 = dodaj_wpis1->nastepny1;
                        z++;
                    }

                    else{
                        dodaj_wpis1 = dodaj_wpis1->nastepny1;
                    }
                }
            }

            if(id_dzialania1 == 6){
            printf("Podaj tytul szukanego lekarza:");
            scanf("%s", tytul_lekarza);

            while(dodaj_wpis1 != NULL){

                    if(stricmp(dodaj_wpis1->tytul_zawodowy, tytul_lekarza)==0){
                        wyswietl_dane_lekarzy(dodaj_wpis1);
                        dodaj_wpis1 = dodaj_wpis1->nastepny1;
                        z++;
                    }
                    else{
                        dodaj_wpis1 = dodaj_wpis1->nastepny1;
                    }
                }
            }

            if(id_dzialania1 == 7){
            printf("Podaj specjalizacje szukanego lekarza:");
            scanf("%s", specjalizacja_lekarza);

            while(dodaj_wpis1 != NULL){

                    if(stricmp(dodaj_wpis1->specjalizacja, specjalizacja_lekarza)==0){
                        wyswietl_dane_lekarzy(dodaj_wpis1);
                        dodaj_wpis1 = dodaj_wpis1->nastepny1;
                        z++;
                    }

                    else{
                        dodaj_wpis1 = dodaj_wpis1->nastepny1;
                    }
                }
            }

        if(id_dzialania1 > 7){
            printf("Wybierz wlasciwa liczbe !");
        }

        if(z<1){
            printf("Nie znaleziono uzytkownika o podanych danych.\n");
        }

        int n;
            printf("\n\nCzy chcesz wyszukac kolejnego lekarza?\n[1]Tak.\n[2]Nie.");
            scanf("%d", &n);
            if(n==1){
                menu_wyszukiwania_lekarzy();
                return 0;
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

/// Funkcja pozwalajca na wyswietlenie szczegolowych danych konkretnego lekarza.\image html konkretny.png
void wyswietl_dane_lekarzy(){

                printf("\n*****************************************************************************************************************************");
                printf("\nNumer ID: \t\t%d",dodaj_wpis1->id);
                printf("\nImie i Nazwisko: \t%s %s\n",dodaj_wpis1->imie,dodaj_wpis1->nazwisko);
                printf("PESEL: \t\t\t%s\n",dodaj_wpis1->pesel);
                printf("Nr PWZ: \t\t%s\n",dodaj_wpis1->numer_pwz);
                printf("Tytul zawodowy: \t%s\n",dodaj_wpis1->tytul_zawodowy);
                printf("Specjalizacja: \t\t%s\n",dodaj_wpis1->specjalizacja);
                printf("E-Mail: \t\t%s\n",dodaj_wpis1->email);
                printf("Nr telefonu: \t\t+48 %s\n",dodaj_wpis1->telefon);
                printf("Dni pracy: \t\t");
                if(dodaj_wpis1->dni_pracy[0] == '1'){
                    printf("Poniedzialek,");
                }
                if(dodaj_wpis1->dni_pracy[1] == '1'){
                    printf("Wtorek,");
                }
                if(dodaj_wpis1->dni_pracy[2] == '1'){
                    printf("Sroda,");
                }
                if(dodaj_wpis1->dni_pracy[3] == '1'){
                    printf("Czwartek,");
                }
                if(dodaj_wpis1->dni_pracy[4] == '1'){
                    printf("Piatek,");
                }
                if(dodaj_wpis1->dni_pracy[5] == '1'){
                    printf("Sobota,");
                }
                if(dodaj_wpis1->dni_pracy[6] == '1'){
                    printf("Niedziela,");
                }
                printf("\nGodziny pracy: \t\t%d.00 - %d.00\n",dodaj_wpis1->godzina_pocz, dodaj_wpis1->godzina_kon);
}

/// Funkcja pozwala na zamiane danych 2 lekarzy, przekazanych przez argument funkcji jako 2 wskazniki do odpowiednich struktur.\image html kod.png
void swap_lekarze(struct lekarze *a, struct lekarze *b){

    struct lekarze *temp = (struct lekarze *)malloc(sizeof(struct lekarze));

    temp->id = a->id;
    strcpy(temp->imie,a->imie);
    strcpy(temp->nazwisko,a->nazwisko);
    strcpy(temp->pesel,a->pesel);

    a->id = b->id;
    strcpy(a->imie,b->imie);
    strcpy(a->nazwisko,b->nazwisko);
    strcpy(a->pesel,b->pesel);

    b->id = temp->id;
    strcpy(b->imie,temp->imie);
    strcpy(b->nazwisko,temp->nazwisko);
    strcpy(b->pesel,temp->pesel);

}

/// Sortowanie lekarzy wg imienia: \image html sort_imie.png
int sort_lekarze_imie(struct lekarze* a, struct lekarze* b){

    return stricmp(a->imie,b->imie);
}

/// Sortowanie lekarzy wg nazwiska: \image html sort_nazw.png
int sort_lekarze_nazwisko(struct lekarze* a, struct lekarze* b){

    return stricmp(a->nazwisko,b->nazwisko);
}

/// Sortowanie lekarzy wg numeru PESEL: \image html sort_pesel.png
int sort_lekarze_pesel(struct lekarze* a, struct lekarze* b){

    return stricmp(a->pesel,b->pesel);
}

/// Funkcja tworzaca menu odpowiedzialne za sortowanie lekarzy, rowniez po imieniu, nazwisku etc. \image html sorta.png
void menu_sortowania_lekarzy(struct lekarze *lista1){

        int a,b;
        system("cls");

        if(poczatek1 == NULL){
            printf("Baza lekarzy jest pusta!! \n\n");
            return ;
        }

        printf("Jak chcesz posortowac dane? \n[1]Rosnaco. \n[2]Malejaco.\n");
        scanf("%d", &a);

        if(a==1){

        printf("WYBIERZ POLE PO KTORYM CHCESZ POSORTOWAC LEKARZY:\n [1]Imie,\n [2]Nazwisko,\n [3]Pesel,\n\n\n [4]MENU.\n");
        scanf("%d", &b);
        switch(b){

            case 1:
                sort_od_min_leka(sort_lekarze_imie);
                pokaz_lekarzy(lista1);
                break;
            case 2:
                sort_od_min_leka(sort_lekarze_nazwisko);
                pokaz_lekarzy(lista1);
                break;
            case 3:
                sort_od_min_leka(sort_lekarze_pesel);
                pokaz_lekarzy(lista1);
                break;
            case 4:
                break;
            default:
                break;
            }
        }
        else if(a==2){
            printf("WYBIERZ POLE PO KTORYM CHCESZ POSORTOWAC LEKARZY:\n [1]Imie,\n [2]Nazwisko,\n [3]Pesel,\n\n\n [4]MENU.\n");
        scanf("%d", &b);
        switch(b){

            case 1:
                sort_od_max_leka(sort_lekarze_imie);
                pokaz_lekarzy(lista1);
                break;
            case 2:
                sort_od_max_leka(sort_lekarze_nazwisko);
                pokaz_lekarzy(lista1);
                break;
            case 3:
                sort_od_max_leka(sort_lekarze_pesel);
                pokaz_lekarzy(lista1);
                break;
            case 4:
                break;
            default:
                break;
            }
        }
}

/// Funkcja sortujaca lekarzy rosnaco. \image html sortmin.png Sortowanie rosnaco po nazwisku
void sort_od_min_leka(int(*porownaj)(struct lekarze* pierwszy, struct lekarze* drugi)){

    int swapped;

    struct lekarze *lptr = NULL;
    struct lekarze *ptr1;
    do
    {
        swapped = 0;
        ptr1 = poczatek1;

        while (ptr1->nastepny1 != lptr)
        {
            if (porownaj(ptr1, ptr1->nastepny1) > 0)
            {
                swap_lekarze(ptr1, ptr1->nastepny1);
                swapped = 1;
            }
            ptr1 = ptr1->nastepny1;
        }
        lptr = ptr1;
    }
    while (swapped);

}

/// Funkcja sortujaca lekarzy malejaco.\image html sortmax.png Sortowanie malejaco po nazwisku
void sort_od_max_leka(int(*porownaj)(struct lekarze* pierwszy, struct lekarze* drugi)){

    int swapped;

    struct lekarze *lptr = NULL;
    struct lekarze *ptr1;
    do
    {
        swapped = 0;
        ptr1 = poczatek1;

        while (ptr1->nastepny1 != lptr)
        {
            if (porownaj(ptr1, ptr1->nastepny1) < 0)
            {
                swap_lekarze(ptr1, ptr1->nastepny1);
                swapped = 1;
            }
            ptr1 = ptr1->nastepny1;
        }
        lptr = ptr1;
    }
    while (swapped);

}

