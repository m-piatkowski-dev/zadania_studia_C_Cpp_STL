#ifndef task_w6_h
#define task_w6_h

template <class T>//funkcja pomocnicza do wypisywania zawartosci mapy
void print_map(const T& container)
{ 
    for(auto it=container.begin(); it!=container.end(); ++it)
    {
        std::cout<<(*it).first<<" -  "<<(*it).second<<"\n";
    }
    std::cout<<std::endl;
}

void key_swap_value(const std::map<std::string, int>& container1, std::multimap<int, std::string>& container2)//funkcja zamieniająca klucz z wartością
{ 
    for(const auto& pair: container1)
    {
        container2.insert({pair.second, pair.first});  
    }
}

#endif