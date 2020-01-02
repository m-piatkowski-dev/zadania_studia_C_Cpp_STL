#include <set>
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

    Person generuj_osobe()
    {
        return Person(imiona[rand() % 10], nazwiska[rand() % 10], (rand()%90)+10 );
    }
    
    struct  Cmp{
        bool operator() (const Person &p1, const Person &p2)
        {
            if(p1.surname!=p2.surname) return(p1.surname<p2.surname);
            if(p1.name!=p2.name) return(p1.name<p2.name);
            if(p1.age!=p2.age) return(p1.age<p2.age);
            return false;
        }
    };
    private:
    std::string name;
    std::string surname;
    int age;

};
/*
int operator<(const Person &p1, const Person &p2)
{   
    if(p1.surname!=p2.surname) return(p1.surname<p2.surname);
    if(p1.name!=p2.name) return(p1.name<p2.name);
    if(p1.age!=p2.age) return(p1.age<p2.age);
    return 0;
}
*/


std::set<Person, Person::Cmp> ludzie;

int main()
{
    std::srand(time(nullptr)); // losowe ziarno 

    Person michal {"Michal", "Piatkowski", 35}; //obiekt testowy inicjujący

    std::cout << michal;

    for (int i=0; i<1000; ++i)
        { 
            //Person losowa_osoba = michal.generuj_osobe();
            ludzie.insert(michal.generuj_osobe());
        }

    std::cout<<"Wygenerowana lista osob:\n\n";

    for (auto it=ludzie.begin(); it!=ludzie.end();++it)
    {
        std::cout<<*it;
    }


return 0;
}


