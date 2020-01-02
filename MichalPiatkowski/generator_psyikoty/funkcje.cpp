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

//pojemniki na dane kotow
vector <string> imiona_k {"Bonifacy", "Filemon", "Ernest", "Czesio", "Bazyl","Stefan","Kicia","Niuniek","Rudy"};  
vector <string> rasy_k {"Perski", "Dachowiec", "Syjamski", "Munchkin", "Sfinks", "Arab", "Pustynny", "Tygrys"};
vector <int> waga_k {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
//pojemniki na dane psow
vector <string> imiona_p {"Lala", "Fafik", "Reksio", "Dingo", "Azor", "Brutus", "Misiek", "Lola", "Pożeracz"};
vector <string> rasy_p {"Jamnik", "Wyzel", "Dog", "Labrador", "Buldog", "Mastif", "Beagle", "Posokowiec", "Owczarek"};
vector <int> waga_p {5, 7, 9, 10, 12, 14, 17, 21, 25, 30, 35, 40, 45, 60, 70};

struct zwierze
{
    string imie;
    string rasa;
    int waga;
};

struct zwierze kot;
vector<zwierze> koty;

struct zwierze pies;
vector<zwierze> psy;

int gen_los_z_vec(int rozmiar_v)
{
int element_vectora = ( rand() % rozmiar_v ) + 0;       
return element_vectora;
}

void dodaj_koty()
{
    system("clear");
    cout<<"Ile kotów chcesz dodać??"<<endl;
    int ile_kotow;
    cin>>ile_kotow;
    
        for(int i=0; i<ile_kotow; ++i)
        {
            kot.imie = imiona_k[gen_los_z_vec(imiona_k.size())]; 
            kot.rasa = rasy_k[gen_los_z_vec(rasy_k.size())];
            kot.waga = waga_k[gen_los_z_vec(waga_k.size())];
            koty.push_back(kot); 
        }      
}

void wyswietl_koty()
{
     system("clear");
    for (int i=0; i<koty.size(); ++i)
    {
    cout << "Kot nr"<<setw(4)<<i+1<<":  "<<"imię: "<<koty[i].imie<<"\t\t"<<"rasa: "<<koty[i].rasa<<"\t\t"<<"waga: "<<koty[i].waga<< "\n";
    }
    cout << "\nObecnie na liście znajduje się "<<koty.size()<<" kotów\n";
}
//funkcja pomocnicza do funkcji sortujacej, porównująca 2 argumenty i zwracająca true or false 
bool sort_imie( const zwierze &lhs, const zwierze &rhs) {return lhs.imie < rhs.imie;}
bool sort_rasa( const zwierze &lhs, const zwierze &rhs) {return lhs.rasa < rhs.rasa;}
bool sort_waga( const zwierze &lhs, const zwierze &rhs) {return lhs.waga < rhs.waga;}

void sortuj_koty()
{   
    char wyb_k;        
    system("clear");
    do
    {
        
        cout<<"Wybierz opcję sortowania: \n"
        << "Sortuj po imieniu\t -> naciśnij 1 <enter>\n"
        << "Sortuj po rasie\t\t -> naciśnij 2 <enter>\n"
        << "Sortuj po wadze\t\t -> naciśnij 3 <enter>\n"
        <<"Wróc do menu głównego\t -> naciśnij 4 <enter>\n";
        cin>>wyb_k;
        if(wyb_k != '1' && wyb_k != '2' && wyb_k != '3' && wyb_k != '4') 
        {
            cout << "##!!Wybrano niewłaściwą opcję, wybierz ponownie!!##\n\n\n";
        }
        switch(wyb_k)                        
        {
            case '1':
            sort(koty.begin(), koty.end(), sort_imie);//bierze wynik z bool sort_imie();
            wyswietl_koty();
            break;
            case '2':
            sort(koty.begin(), koty.end(), sort_rasa);//bierze wynik z bool sort_rasa();
            wyswietl_koty();
            break;
            case '3':
            sort(koty.begin(), koty.end(), sort_waga);//bierze wynik z bool sort_waga();
            wyswietl_koty();
            break;
            case '4':
            break;
        }

    }while ( (wyb_k != '1' && wyb_k != '2' && wyb_k != '3' && wyb_k != '4') || (wyb_k == '1' || wyb_k == '2' || wyb_k == '3' && wyb_k != '4') );           
}

void usun_koty()
{
    system("clear");
    cout<<"Ile kotów z listy chcesz usunąć??"<<endl;
    cout << "\nObecnie na liście znajduje się "<<koty.size()<<" kotów\n";
    int ile_kotow;
    cin>>ile_kotow;
    if (ile_kotow<=koty.size())
    {
        for(int i=0; i<ile_kotow; ++i)
        {
            koty.pop_back();
        }
        cout<<"Usunięto "<<ile_kotow<<" kotów z listy!"<<endl;
        cout << "\nObecnie na liście znajduje się "<<koty.size()<<" kotów\n";
    }else
        {
        cout<<"Wybrano więcej kotów niż jest na liście, wybierz ponownie!"<<endl;
        } 
}

void dodaj_psy()
{
    system("clear");
    cout<<"Ile psów chcesz dodać??"<<endl;
    int ile_psow;
    cin>>ile_psow;
    
        for(int i=0; i<ile_psow; ++i)
        {
            pies.imie = imiona_p[gen_los_z_vec(imiona_p.size())];
            pies.rasa = rasy_p[gen_los_z_vec(rasy_p.size())];
            pies.waga = waga_p[gen_los_z_vec(waga_p.size())];
            psy.push_back(pies);
        }      
}

void wyswietl_psy()
{
    system("clear");
    for (int i=0; i<psy.size(); ++i)
    {
    cout << "Pies nr "<<setw(5)<<i+1<<": "<<"imię: "<<psy[i].imie<<"\t\t"<<"rasa: "<<psy[i].rasa<<"\t\t"<<"waga: "<<psy[i].waga<< "\n";
    }
    cout << "\nObecnie na liście znajduje się "<<psy.size()<<" psów\n";
}
void sortuj_psy()
{   
    char wyb_p;        
    system("clear");
    do
    {
        cout<<"Wybierz opcję sortowania: \n"
        << "Sortuj po imieniu -> naciśnij 1 <enter>\n"
        << "Sortuj po rasie -> naciśnij 2 <enter>\n"
        << "Sortuj po wadze -> naciśnij 3 <enter>\n"
        <<"Wróc do menu głównego -> naciśnij 4 <enter>\n";
        cin>>wyb_p;
        if(wyb_p != '1' && wyb_p != '2' && wyb_p != '3' && wyb_p != '4') 
        {
            cout << "\n\n##!!Wybrano niewłaściwą opcję, wybierz ponownie!!##\n\n\n";
        }
        switch(wyb_p)                        
        {
            case '1':
            sort(psy.begin(), psy.end(), sort_imie);//bierze wynik z bool sort_imie();
            wyswietl_psy();
            break;
            case '2':
            sort(psy.begin(), psy.end(), sort_rasa);//bierze wynik z bool sort_rasa();
            wyswietl_psy();
            break;
            case '3':
            sort(psy.begin(), psy.end(), sort_waga);//bierze wynik z bool sort_waga();
            wyswietl_psy();
            break;
            case '4':
            break;
        }

    }while ( (wyb_p != '1' && wyb_p != '2' && wyb_p != '3' && wyb_p != '4') || (wyb_p == '1' || wyb_p == '2' || wyb_p == '3' && wyb_p != '4') );           
}

void usun_psy()
{
    system("clear");
    cout<<"Ile psów z listy chcesz usunąć??"<<endl;
    cout << "\nObecnie na liście znajduje się "<<psy.size()<<" psów\n";
    int ile_psow;
    cin>>ile_psow;
    if (ile_psow<=psy.size())
    {
        for(int i=0; i<ile_psow; ++i)
        {
            psy.pop_back();
        }
        cout<<"Usunięto "<<ile_psow<<" psów z listy!"<<endl;
        cout << "\nObecnie na liście znajduje się "<<psy.size()<<" psów\n";
    }else
        {
        cout<<"Wybrano więcej psów niż jest na liście, wybierz ponownie!"<<endl;
        } 
}
