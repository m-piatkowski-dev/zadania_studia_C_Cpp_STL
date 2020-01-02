#ifndef nag_huff_h
#define nag_huff_h

using namespace std;

// wzorzec wezla drzewa Huffmana
struct Node
{
	char ch;
	int freq;
	Node *left, *right;
};

void encode(Node* root, string str,	unordered_map<char, string> &huffmanCode);
void decode(Node* root, int &index, string str);
void buildHuffmanTree(string text);

#endif