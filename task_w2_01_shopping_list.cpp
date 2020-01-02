/*
    Michal Piatkowski
    Dzien dobry,
    to zadanie zrobilem na zajeciach ale na wszelki wypadek podsylam. Poprawilem warningi
    i dopisalem boolalpha.
*/
#include <iostream>
#include <algorithm>
#include <array>
#include <string>

//1
std::array<std::string, 5>zakupy{"por", "seler", "marchew", "brukiew", "mleko"};

void zamiana(std::string &elem)
{
    if (elem[0]=='m')
    {
        elem="ziemniaki";
    }
}

bool porownaj_rosnaco(const std::string &a, const std::string &b)
{
    return a<b;
}

bool porownaj_malejaco(const std::string &a, const std::string &b)
{
    return a>b;
}
int main()
{
 //2
    std::cout<<"Petla for zakresowa:"<<std::endl;
    for(auto x:zakupy)
    {
        std::cout << x << " ";
    }
    std::cout<<std::endl;

    std::cout<<"Petla for + klasyczny dostęp do elementów(poprzez index tablicy): "<<std::endl;
    for(long unsigned int i=0; i<zakupy.size(); ++i)
    {
        std::cout<<zakupy[i]<<" ";
    }
    std::cout<<std::endl;

std::cout<<"Petla for + dostęp operatorem at():"<<std::endl;
    for(long unsigned int i=0; i<zakupy.size(); ++i)
    {
        std::cout<<zakupy.at(i)<<" ";
    }
    std::cout<<std::endl;

//3
std::cout<<"Rozmiar tablicy: "<<zakupy.size()<<std::endl;

std::cout<<"Czy tablica jest pusta? "<< std::boolalpha << zakupy.empty() << std::endl;

//4
for(long unsigned int i=0; i<zakupy.size(); ++i)
{
    zamiana(zakupy[i]);
};
std::cout<<"Wyniki zamiany pierwszych liter:"<<std::endl;
    for(auto x:zakupy)
    {
        std::cout<<x<<" ";
    }
    std::cout<<std::endl;

//5
std::cout<<"Wypisanie poprzez wsteczny iterator:"<<std::endl;
for(auto i=zakupy.rbegin(); i!=zakupy.rend(); ++i)
    {
        std::cout<< *i << " ";
    };
    std::cout<<std::endl;

//6
std::cout<<"Wyjątek"<<std::endl;

try { std::cout<<zakupy.at(11)<<std::endl;
  //7  
} catch (const std::out_of_range& e) {
    std::cout<<"Wyjechales poza tablice:!!!"<<e.what()<<std::endl;
} catch (...){
    std::cout<<"inny wyjątek.."<<std::endl;
}
//8
std::cout<<"Sortowanie: "<<std::endl;
std::sort(zakupy.begin(), zakupy.end());
for(auto i=zakupy.begin(); i!=zakupy.end(); ++i)
    {
        std::cout<< *i << " ";
    };
    std::cout<<std::endl;
//9
std::cout<<"Sortowanie z wlasna funkcja rosnaco: "<<std::endl;
sort(zakupy.begin(), zakupy.end(), porownaj_rosnaco);
for(auto i=zakupy.begin(); i!=zakupy.end(); ++i)
    {
        std::cout<< *i << " ";
    };
    std::cout<<std::endl;

//10
std::cout<<"Sortowanie z wlasna funkcja malejaco: "<<std::endl;
sort(zakupy.begin(), zakupy.end(), porownaj_malejaco);
for(auto i=zakupy.begin(); i!=zakupy.end(); ++i)
    {
        std::cout<< *i << " ";
    };
    std::cout<<std::endl;



return 0;
}