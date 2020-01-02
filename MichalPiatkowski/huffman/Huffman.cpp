#include <iostream>
#include <string>
#include <queue>
#include <unordered_map>
#include "nag_huff.h"

using namespace std;


int main()
{
    string text;
    cout << "\nNapisz prosze tekst, ktory chcesz skompresowac: \n";
    getline(cin, text);
    //cout << endl;
    buildHuffmanTree(text);
    cout << "\n";

	return 0;
}