/**
* This is the implementation file for the Lexicon class.
* It is using a trie data structure.
*
* @author      Craig Panek
* Created:     May 22, 2014
* Source File: Lexicon.cpp
*/

#include "Lexicon.h"
#include <iostream>
#include <cstdlib>
#include <fstream>

Lexicon::Lexicon(string lexiconFileName) {
    loadLexicon(lexiconFileName);
}

bool Lexicon::isWord(string word) {
    return (trie.exists(word));
}

void Lexicon::loadLexicon(string lexiconFileName) {
    ifstream inWords;
    string word;

    inWords.open(lexiconFileName.c_str());
    if(!inWords) {
        cerr << "ERROR - file \"" << lexiconFileName << "\" does not exist!";
        exit(1);
    }

    while(inWords >> word) {
        trie.insert(word);
    }
    inWords.close();
}
