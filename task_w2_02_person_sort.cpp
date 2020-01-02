/* Michal Piatkowski
    Dzien dobry,
    Nie zdazylem wszystkiego dobrze obrobic i poskracac, niektore elementy moznaby zastapic 
    funkcja plus opcje sortowania moglem zrobic na 2 sposoby(wiecej funkcji porownawczych 
    lub to co mamy) oraz generowanie osob tez moznabylo zrobic ciut inaczej. Nie wiem czy #include 
    nie jest za duzo bo mialem problem z jednym motywem i kombinowalem, mam nadzieje, ze w ogolnym
    rozrachunku o to chodzilo :)
*/

#include <iostream>
#include <algorithm>
#include <chrono>
#include <array>
#include <string>
#include <random>
#include <cstdlib>
#include <ctime>

std::array<std::string, 10>imiona{"Anna", "Mariola", "Stefan", "Barbara", "Michal", "Wojciech", "Pawel", "Karol","Roman","Ignacy"};
std::array<std::string, 10>nazwiska{"Nowak", "Pawlak", "Moscicki", "Paderewski", "Matejko", "Pilsudski", "Curie", "Wolski","Opel","Kosciuszko"};

class Person {

public:
    
	Person(std::string name, std::string surname, int age)
    {
        this->name = name;
        this->surname = surname;
        this->age = age;
    };
    //zad.1 
    Person() = default;
    friend std::ostream& operator<<(std::ostream& s,const Person & p)
    {
        return s <<p.name<<" "<<p.surname<<" "<<p.age<<std::endl;
    };
    //zad.2 (metoda zwraca konstruktor generujący, 
    // aby z niego skorzystać należy utworzyć obiekt, ktory nastepnie 
    // tworzy kolejne obiekty generowane losowo)

    Person generuj_osobe()
    {
        return Person(imiona[rand() % 10], nazwiska[rand() % 10], (rand()%90)+10 );
    }
     
    std::string name;
    std::string surname;
    int age;

};

bool porownaj_rosnaco_imie(Person a , Person b)
    {
        return a.name < b.name;
    }
bool porownaj_rosnaco_nazwisko(Person a , Person b)
    {
        return a.surname < b.surname;
    }
bool porownaj_rosnaco_wiek(Person a , Person b)
    {
        return a.age < b.age;
    }

int main()
{
    std::srand(time(nullptr)); // losowe ziarno (zrobilem z losowym bo ladniej wyglada)

    Person michal {"Michal", "Piatkowski", 35}; //obiekt testowy

    std::cout << michal;//sprawdzenie przeładowania operatora(test_zad.1)

    for (int i=0; i<10; ++i)//generowanie i wypisanie 10 losowych osob(test_zad.2)
        { 
            Person losowa_osoba = michal.generuj_osobe();
            std::cout<<losowa_osoba;
        }
    std::cout<<std::endl<<"koniec listy\n\n";

    //zad.3   
    std::array<Person, 10> lista_osob={};
    std::cout<<"Zad.3 lista_osob wygenerowana - nieposorotowana\n\n";

    for (long unsigned int i =0; i<lista_osob.size();++i)
    {
        lista_osob[i] = michal.generuj_osobe();
        std::cout<<lista_osob[i];
    }

    std::sort(lista_osob.begin(), lista_osob.end(), porownaj_rosnaco_wiek);
    std::cout<<"lista_osob wygenerowana - posorotowana rosnaco wiek\n\n";
    for (long unsigned int i =0; i<lista_osob.size();++i)
    {
        std::cout<<lista_osob[i]<<std::endl;
    }
    std::sort(lista_osob.begin(), lista_osob.end(), porownaj_rosnaco_imie);
    std::cout<<"lista_osob wygenerowana - posorotowana rosnaco imie\n\n";
    for (long unsigned int i =0; i<lista_osob.size();++i)
    {
        std::cout<<lista_osob[i]<<std::endl;
    }

    std::sort(lista_osob.begin(), lista_osob.end(), porownaj_rosnaco_nazwisko);
    std::cout<<"lista_osob wygenerowana - posorotowana rosnaco nazwisko\n\n";
    for (long unsigned int i =0; i<lista_osob.size();++i)
    {
        std::cout<<lista_osob[i]<<std::endl;
    }

    std::sort(lista_osob.rbegin(), lista_osob.rend(), porownaj_rosnaco_imie);
    std::cout<<"lista_osob wygenerowana - posorotowana malejaco imie\n\n";
    for (long unsigned int i =0; i<lista_osob.size();++i)
    {
        std::cout<<lista_osob[i]<<std::endl;
    }

    std::sort(lista_osob.rbegin(), lista_osob.rend(), porownaj_rosnaco_nazwisko);
    std::cout<<"lista_osob wygenerowana - posorotowana malejaco nazwisko\n\n";
    for (long unsigned int i =0; i<lista_osob.size();++i)
    {
        std::cout<<lista_osob[i]<<std::endl;
    }

    std::sort(lista_osob.rbegin(), lista_osob.rend(), porownaj_rosnaco_wiek);
    std::cout<<"lista_osob wygenerowana - posorotowana malejaco wiek\n\n";
    for (long unsigned int i =0; i<lista_osob.size();++i)
    {
        std::cout<<lista_osob[i]<<std::endl;
    }

return 0;
}


