#include <iostream>
#include <algorithm>
#include <array>
#include <string>
#include <vector>

template <class T>
void print(const T& kontener, const std::string& s)//pomocnicza funkcja do wypisywania elem. kontenera z opisem jako 2 arg.
{
    std::cout<<s<<": \n";
    std::cout<<"[ ";
    for (unsigned int i=0; i <kontener.size(); ++i)
    {
        std::cout<< kontener[i]; 
        if (i< kontener.size()-1)
            std::cout<<", ";
    }
    std::cout<< " ]" << std::endl;
}
//Zadanie inser_every_second
std::vector<int> n_el;
void roz_poj_vec()
{
    std::cout<<"rozmiar vectora: "<<n_el.size()<<" pojemnosc vectora: "<<n_el.capacity()<<std::endl;
}

int main()
{
    int poj_vek = 0;
    int wypelniacz = 900;
    std::cout<<"Podaj ile elementow ma zawierac vector?: \n";
    std::cin>>poj_vek;
    n_el.reserve(poj_vek);
    
    roz_poj_vec();
    
    for(unsigned int i=0; i<n_el.capacity(); ++i)//ad.1)
    {
        n_el.push_back(wypelniacz);
        wypelniacz++; 
    }
    print(n_el, "Wypisanie wektora");//ad.2) 
    roz_poj_vec();

    auto it=n_el.begin();
    for( int i=0; i<poj_vek; ++i)
    {
        auto x=n_el.insert(it, i);
        it= x+2;
    }
    print(n_el, "Wypisanie wektora po dodaniu pozycji f.insert()"); 
    roz_poj_vec();

    for( auto ite=n_el.begin()+1; ite<n_el.end(); ++ite)
    {
        n_el.erase(ite);
    }
    print(n_el, "Wypisanie wektora po usunieciu wypełniacza f.erase()");
    roz_poj_vec();
    n_el.shrink_to_fit();
    std::cout<<"Po optymalizacji pojemności vectora:\n";
    roz_poj_vec();
return 0;
}
