#include <iostream>
#include <algorithm>
#include <set>
#include <chrono>
#include <random>

std::set <int> los_osoby;

void print(const std::set<int>& i, int& s)//pomocnicza funkcja do wypisywania elem. kontenera z opisem jako 2 arg.
{
    std::cout<<"Przeprowadzono: "<<s<<" losowan.\n";
    std::cout<<"[ ";
    for(unsigned int x: i)
    {
        std::cout<< x<<" ";
    }
    std::cout<< "]" << std::endl;
}

int main()
{
    std::srand(time(nullptr));

    for(int i=0; i<100; ++i)
    {
        los_osoby.insert(i);
    }
    int licznik = 0;
    while (los_osoby.size()!=0)
    { 
        int losowanie = (rand()%100); 
        los_osoby.erase(losowanie); 
        licznik++;
        if(licznik%100==0)
        {
            print(los_osoby, licznik); 
        } 
    }print(los_osoby, licznik);
    
return 0;
}