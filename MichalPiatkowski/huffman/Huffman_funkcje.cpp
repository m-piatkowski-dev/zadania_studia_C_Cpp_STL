#include <iostream>
#include <string>
#include <queue>
#include <unordered_map>
#include "nag_huff.h"

using namespace std;


// funkcja tworząca nowy wezel drzewa
Node* getNode(char ch, int freq, Node* left, Node* right)
{
	Node* node = new Node();

	node->ch = ch;
	node->freq = freq;
	node->left = left;
	node->right = right;

	return node;
}

// funkcja przydzielajaca wedlug czestotliwosci wystepowania znaku
struct comp
{
	bool operator()(Node* l, Node* r)
	{
		// im nizsza czestosc wystepowania tym wyzszy priorytet
		return l->freq > r->freq;
	}
};

// przydziela kolejnym galeziom kod Huffmana(koduje znaki)
void encode(Node* root, string str,	unordered_map<char, string> &huffmanCode)
{
	if (root == nullptr)
		return;

	if (!root->left && !root->right) {
		huffmanCode[root->ch] = str;
	}

	encode(root->left, str + "0", huffmanCode);
	encode(root->right, str + "1", huffmanCode);
}

// dekoduje string przechodzac przez kolejne galezie
void decode(Node* root, int &index, string str)
{
	if (root == nullptr) {
		return;
	}

	if (!root->left && !root->right)
	{
		cout << root->ch;
		return;
	}

	index++;

	if (str[index] =='0')
		decode(root->left, index, str);
	else
		decode(root->right, index, str);
}

// tworzy drzewo Huffmana i dekoduje tekst wejsciowy
void buildHuffmanTree(string text)
{
	// oblicza czestosc wystepowania elementow i przydziela elementy do mapy
	unordered_map<char, int> freq;
	for (char ch: text) {
		freq[ch]++;
	}

	// tworzy kolejke priorytetowa i zapisuje liscie
	priority_queue<Node*, vector<Node*>, comp> pq;

	// kazdemu znakowi tworzy i przydziela lisc ktory laduje w kolejce priorytetowej
	
	for (auto pair: freq) {
		pq.push(getNode(pair.first, pair.second, nullptr, nullptr));
	}

	// robi to poki jest wiecej niz jeden lisc
	while (pq.size() != 1)
	{
		// usuwa 2 wezly o najwyzszym priorytecie z kolejki
		Node *left = pq.top(); pq.pop();
		Node *right = pq.top();	pq.pop();

		// Z tych dwoch wezlow tworzy nowy(wewnetrzny wezel) 
        // jako wezel dzieci z czestoscia wystepowania ktora 
        // jest suma czestosci wystepowania dwoch poprzednich.
		// Dodaje ten wezel do kolejki priorytetowej.
		int sum = left->freq + right->freq;
		pq.push(getNode('\0', sum, left, right));
	}

	// wezel korzenia przechwouje wskaznik do korzenia drzewa
	Node* root = pq.top();

	// Przechodzi przez kolene elementy drzewa i zapisuje w nich kod Huffmana
	
	unordered_map<char, string> huffmanCode;
	encode(root, "", huffmanCode);

	cout << "\nZakodowane binarnie znaki przedstawiaja sie nastepujaco: \n\n";
	for (auto pair: huffmanCode) {
		cout <<"\t"<< pair.first << " " << pair.second ;
	}

	cout << "\n\nWpisany tekst wyglada nastepujaco: \n\n" << text << '\n';

	// wypisuje zakodowany string
	string str = "";
	for (char ch: text) {
		str += huffmanCode[ch];
	}

	cout << "\nZakodowany tekst wyglada tak: \n\n" << str 
         << "\n\nI ma długość " << str.size()
         << " bitow natomiast wpisany tekst ma "
         << text.size()*8 << " bitow.\n";

    cout << "\nStopień kompresji (CR) wynosi: "<< ( (double) (text.size()*8) / str.size() ) <<"\n";

    double wynik = ((double)(str.size()) / ((text.size()*8))) ;

    cout << "\nWspolczynnik kompresji wynosi: "<< (100-(100 * wynik) ) <<"%";
    
	// przechodzi po kolejnych elementach drzewa 
    //Huffmana i odkodowuje string wypisujac go
	int index = -1;
	cout << "\n\nOdkodowany tekst wyglada tak: \n\n";
	while (index < (int)str.size() - 2) {
		decode(root, index, str);
	}
    cout << "\n";
}