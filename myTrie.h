// By Peter Nguyen and Craig Panek
// 5-20-2014

#include <string>
using namespace std;

#ifndef MYTRIE_H_
#define MYTRIE_H_

class trieNode {
    public :
        char character;
        trieNode *sibling;
        trieNode *children;
        bool isWord;

        trieNode() {
            character = '*';
            sibling = NULL;
            children = NULL;
            isWord = false;
        }
};

class Trie {
	public:
		Trie();
		void add(string word);
		bool exists(string word);
		bool remove(string word);
		void printChildren() const;
	private:
		trieNode* insertAtLevel(char ch, trieNode *currentNode, bool endWord);
		trieNode *root;
};

#endif /* MYTRIE_H_ */
