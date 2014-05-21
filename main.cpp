// By Peter Nguyen and Craig Panek
// 5-20-2014

#include <iostream>
#include <conio.h>
#include "myTrie.h"
using namespace std;



int main() {
	Trie trie;

	trie.add("apple");
	trie.printChildren();

	trie.add("app");
	trie.printChildren();

	trie.add("ape");
	trie.printChildren();

	cout << "main end" << endl;

	return 0;
}
