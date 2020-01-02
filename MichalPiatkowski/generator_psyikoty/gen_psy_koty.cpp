/*  Generator list kotów i psów version 1.0 
    Projekt i wykonanie: Michał Piątkowski
    all rights reserved :P
*/

#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <time.h>
#include <unistd.h>
#include <algorithm>
#include <iomanip>
#include "gen_psy_koty.h"

using namespace std;

int main()
{   
    char powt;
    char wybor;
    srand( time( 0 ) );
    do
    {
        system("clear");
        do
        {
            
            cout <<" _______________________________________________\n|\t\t\t\t\t\t|\n";
            cout <<"| <== Generator list kotów i psów ==>>\t\t|\n|\t\t\t\t\t\t|\n" //poprawic menu i wybieranie!!
                << "| Generuj KOTA/Y\t-> naciśnij 1 i <enter>\t|\n"
                << "| Wyświetl KOTA/Y\t-> naciśnij 2 i <enter>\t|\n"
                << "| Sortuj KOTA\t\t-> naciśnij 3 i <enter>\t|\n"
                << "| Usuń KOTA/Y\t\t-> naciśnij 4 i <enter>\t|\n"
                << "| Generuj PSA/Y\t\t-> naciśnij 5 i <enter>\t|\n"
                << "| wyswietl PSA/Y\t-> naciśnij 6 i <enter>\t|\n"
                << "| Sortuj PSA/Y\t\t-> naciśnij 7 i <enter>\t|\n"
                << "| Usun PSA/Y\t\t-> naciśnij 8 i <enter>\t|\n"
                << "| Wyjście z programu\t-> naciśnij 9 i <enter>\t|\n|\t\t\t\t\t\t|\n";
            cout <<"|_______________________________________________|\n\n";
            cin >> wybor;
            if (wybor != '1' && wybor != '2' && wybor != '3' && wybor != '4' && wybor != '5' && wybor != '6' && wybor != '7' && wybor != '8' && wybor != '9')
            {
            cout << "##!!Wybrano niewłaściwą opcję, wybierz ponownie!!##\n\n\n";
            }
        }while (wybor != '1' && wybor != '2' && wybor != '3' && wybor != '4' && wybor != '5' && wybor != '6' && wybor != '7' && wybor != '8' && wybor != '9');

        switch(wybor) 
        {
            case '1':
                dodaj_koty();
                wyswietl_koty();
            break;
            case '2':
                wyswietl_koty();
            break;
            case '3':
                sortuj_koty();
            break;
            case '4':                
                usun_koty();
            break;
            case '5':
                dodaj_psy();
                wyswietl_psy();
            break;
            case '6':
                wyswietl_psy();
            break;
            case '7':
                sortuj_psy();
            break;

            case '8':
                usun_psy();
            break;
            case '9':
                cout << "Program zamknięto prawidłowo!\n";
                exit (0);
            break;
        }
        cout << "\nCzy chcesz wrócić do menu głównego??\n\n TAK - naciśnij dowolny klawisz i <enter>\n NIE - naciśnij (N\\n) <enter> i zamknij\n\n";
        cin >> powt;
        
    }while ( powt != 'N' && powt != 'n' );
    cout << "Program zamknięto prawidłowo!\n";
return 0;
}
