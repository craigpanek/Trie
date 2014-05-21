// By Peter Nguyen and Craig Panek
// 5-20-2014

#include "myTrie.h"
#include <string>
#include <iostream>
#include <cassert>
using namespace std;

Trie::Trie() {
	root = new trieNode();

	// manually inserted characters
	trieNode *currentNode;
	root->character = 'a';

	root->children = new trieNode;
	currentNode = root->children;
	currentNode->character = 'p';
	currentNode->children = new trieNode;
	currentNode = currentNode->children;
	currentNode->character = 'p';
	printChildren();
	cout << endl;
}

void Trie::printChildren() const {
	trieNode *currentNode = root;

	while (currentNode != NULL) {
		cout << currentNode->character << " ";
		currentNode = currentNode->children;
	}
	cout << endl;
}

void Trie::add(string word) {
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

	if(currentNode->character == '*') { // at a newly created empty node
	    currentNode->character = ch;
	    if (endWord) {
	        currentNode->isWord = true;
	    }
	    return currentNode;
	}

    bool found = false;
    trieNode *previousNode;
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
	return false;
}

bool Trie::remove(string word) {
	if (exists(word)) {
		return true; // removed
	}
	else {
		return false; // not removed
	}
}
