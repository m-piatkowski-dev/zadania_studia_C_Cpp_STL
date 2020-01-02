#include <iostream>
#include <algorithm>
#include <vector>

std::vector<std::string> wyrazy{"clever", "meek", "hurried", "nice"};
std::vector<int> liczby{5, 3, 15, 22, 4};
std::string tekst{"to be or not to be!"};
std::string tekst2{"THE LITTLE MARMAID"};

auto print = [](const std::string& i){std::cout <<"\"" << i<<"\" "; };

void addEnding(std::vector<std::string>& s, const std::string& str)
{
    std::for_each(s.begin(), s.end(), [&](std::string&w){w+=str;});
    std::cout<<"-> [";
    std::for_each(s.begin(), s.end(), print);
    std::cout<<"]\n";
}

bool existsHigher(const std::vector<int>& v, const int& n )
{
    return std::any_of(v.begin(), v.end(),[&](int x) { return x>n;});
}

std::string ascii_capitalise(std::string& st)
{   
   for(auto& i: st)
   {
       if(i%2==0)
       {
           i=std::toupper(i);
       }else i=std::tolower(i);
   }return st;
}

int main()
{

    addEnding(wyrazy, "ly");

    std::cout<<"-> "<<std::boolalpha<<existsHigher(liczby, 10)<<"\n";
    std::cout<<"-> "<<std::boolalpha<<existsHigher(liczby,50)<<"\n";

    std::cout<<"-> \""<<ascii_capitalise(tekst)<<"\"\n";
    std::cout<<"-> \""<<ascii_capitalise(tekst2)<<"\"\n";

return 0;
}