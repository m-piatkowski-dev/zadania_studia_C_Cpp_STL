/* dodalem jeszcze wypisywanie wartosci po kazdym skoku aby mozna
    bylo sobie wszystko sprawdzic */

#include <iostream>
#include <algorithm>
#include <chrono>
#include <array>
#include <random>

std::array<int, 30> tab_int{};

template <class T>
void print(const T& kontener)//pomocnicza funkcja do wypisywania elem. kontenera z opisem jako 2 arg.
{
    std::cout<<"[ ";
    std::for_each(kontener.begin(), (kontener.end()-1),[] (const int& n){std::cout<<n<<", ";}); 
    std::cout<<*(kontener.end()-1)<<" ]\n";
}

//auto print = [](const int& n){std::cout<<n<<", ";}; //pierwsza wersja funkcji do wypisywania->potrzebuje for_each`a, zmieniłem na tą wyzej
auto fill = [](int& x){ return x = (rand()%5+1); };//funkcja pomocnicza do wypelniania randomowymi liczbami
int main()
{   
    std::srand(time(nullptr));
    /* //dwie wersje wypelniania tablicy randomowymi liczbami, za pomoca for`a
    for(auto && it=tab_int.begin(); it!=tab_int.end(); ++it)
    {
        *it = rand()%5+1;
    }*/
    std::for_each(tab_int.begin(), tab_int.end(), fill);// druga za pomoca for_each z funkcja pomocnicza

    print(tab_int);
   
    auto it = tab_int.begin();//ad.2)
   
    while(it<tab_int.end())
    {
        auto x = *it;
        std::cout<< x<< "->";
        *it += 100;
        std::advance(it, x);
    } 
    std::cout<<"end()\n";
    
    print(tab_int);
 
return 0;
}