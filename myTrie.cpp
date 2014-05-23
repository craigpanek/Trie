// By Peter Nguyen and Craig Panek
// 5-20-2014

#include "myTrie.h"
#include <string>
#include <iostream>
#include <cassert>
using namespace std;

Trie::Trie() {
	root = new trieNode();
}

void Trie::insert(string word) {
    trieNode *currentNode = root;

    while (word.size() > 0) {
        char currentChar = word[0];
        word = word.substr(1, word.size() - 1); // this works even if size() is 1
        bool endWord = (word.size() == 0);
        currentNode = insertAtLevel(currentChar, currentNode, endWord);

        if (!endWord) { // go down to next level
            if (currentNode->children == NULL) {
                currentNode->children = new trieNode;
                currentNode = currentNode->children;
            } else
                currentNode = currentNode->children;
        }
    }
}

trieNode* Trie::insertAtLevel(char ch, trieNode *currentNode, bool endWord) {

	if(currentNode->character == '\0') { // at a newly created empty node
	    currentNode->character = ch;
	    if (endWord) {
	        currentNode->isWord = true;
	    }
	    return currentNode;
	}

    bool found = false;
    trieNode *previousNode = NULL; // must initialize for first compile in VS2013
    assert(currentNode != NULL);
	while (currentNode != NULL && !found) {
		if (currentNode->character == ch) {
			found = true;
		} else {
		    previousNode = currentNode;
		    currentNode = currentNode->sibling;
		}
	}
	if (!found) {
	    currentNode = new trieNode;
		previousNode->sibling = currentNode;
	    currentNode->character = ch;
	}
	if(endWord)
	    currentNode->isWord = true;
	return currentNode;
}

bool Trie::exists(string word) {

	trieNode *currentNode = root;

	bool exists = false;

	while (word.size() > 0 && !exists) {
		char currentChar = word[0];
		word = word.substr(1, word.size() - 1);
		bool endWord = (word.size() == 0);
		currentNode = existsAtLevel(currentChar, currentNode, endWord, exists);

		if (!endWord && currentNode != NULL) { // go down to next level
			currentNode = currentNode->children;
		}
	}

	if (exists) {
		return true;
	} else return false;
}

trieNode* Trie::existsAtLevel(char ch, trieNode *currentNode, bool endWord, bool &exists) {

	bool found = false;
	//assert(currentNode != NULL);
	trieNode *previousNode;

	while (currentNode != NULL) {
		if (currentNode->character == ch) {

			if (endWord && currentNode->isWord) {
				exists = true;
			}
			return currentNode;
		}
		else {
			previousNode = currentNode;
			currentNode = currentNode->sibling;
		}
	}
	
	exists = false;
	return currentNode;
}

void Trie::printChildren() const {
	trieNode *currentNode = root;

	while (currentNode != NULL) {
		cout << currentNode->character << " ";
		currentNode = currentNode->children;
	}
	cout << endl;
}

void Trie::specialPrint() const {
	trieNode *currentNode = root;

	cout << currentNode->character << " ";
	currentNode = currentNode->children;

	cout << currentNode->character << " ";
	currentNode = currentNode->children;

	cout << currentNode->character << " ";
	currentNode = currentNode->children;

	cout << currentNode->character << " ";
	currentNode = currentNode->children;

	currentNode = currentNode->sibling;

	cout << currentNode->character << " ";

	cout << endl;
}

void Trie::printAll() const {
	trieNode *currentNode = root;
}