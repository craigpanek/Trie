// By Peter Nguyen and Craig Panek
// 5-20-2014

#include <iostream>
#include <conio.h>
#include "myTrie.h"
using namespace std;
#include "Lexicon.h"

int main() {

    Lexicon lexicon("Enhanced North American Benchmark Lexicon.txt");
    string word;

    cout << "Enter words to be checked. Enter EOF (Ctrl-z on Windows) when you are done\n";
    cin >> word;
    while (!cin.eof()) {
        cout << word << " is" << (lexicon.isWord(word) ? "":" NOT") << " a word\n";
        cin >> word;
    }
	//system("pause"); // if needed, comment out but don't delete
	return 0;
}
