// By Peter Nguyen and Craig Panek
// 5-20-2014

#include <iostream>
#include <conio.h>
#include "myTrie.h"
using namespace std;

int main() {
	Trie trie;

	trie.insert("apple");
	trie.insert("apply");
	trie.insert("orange");
	trie.insert("or");

	cout << "apple is a word: " << trie.exists("apple") << endl;
	cout << "apply is a word: " << trie.exists("apply") << endl;
	cout << "orange is a word: " << trie.exists("orange") << endl;
	cout << "oranges is a word: " << trie.exists("oranges") << endl;
	cout << "or is a word: " << trie.exists("orange") << endl;
	cout << "app is a word: " << trie.exists("app") << endl;

	system("pause"); // if needed, comment out but don't delete
	return 0;
}
