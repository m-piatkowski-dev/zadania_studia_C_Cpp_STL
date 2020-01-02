#include <map>
#include <string>
#include <fstream>
#include <iostream>
#include "task_w6.h"

std::map<std::string,int> token_kod;
std::multimap<int, std::string> kod_token;

int main()
{
    std::string word;
    std::ifstream file;
    file.open(__FILE__);
    while(file>>word)
    {      
        auto it=token_kod.insert({word, 1});
        if(it.second==false)
        token_kod[word]+=1;       
    }   
    print_map(token_kod);
    key_swap_value(token_kod, kod_token);
    print_map(kod_token);
}