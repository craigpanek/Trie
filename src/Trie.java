class TrieNode {
    
	public char character;
    public TrieNode sibling;
    public TrieNode children;
    public boolean isWord;
    public boolean exists;
	
    TrieNode() {
        character = '\0';
        sibling = null;
        children = null;
        isWord = false;
        exists = false;
    }
};

class Trie {
	
	private TrieNode root;
	
	public Trie() {
		root = new TrieNode();
	}
	
	public void insert(String word) {
	    TrieNode currentNode = root;

	    while (word.length() > 0) {
	        char currentChar = word.charAt(0);
	        word = word.substring(1, word.length()); // this works even if size() is 1
	        boolean endWord = (word.length() == 0);
	        currentNode = insertAtLevel(currentChar, currentNode, endWord);

	        if (!endWord) { // go down to next level
	            if (currentNode.children == null) {
	                currentNode.children = new TrieNode();
	                currentNode = currentNode.children;
	            } else
	                currentNode = currentNode.children;
	        }
	    }
	}
	
	public boolean exists(String word) {
		TrieNode currentNode = root;
		Exists exists = new Exists();
		exists.exists = false;

		while (word.length() > 0 && !exists.exists) {
			char currentChar = word.charAt(0);
			word = word.substring(1, word.length());
			boolean endWord = (word.length() == 0);
			currentNode = existsAtLevel(currentChar, currentNode, endWord, exists);
			if (exists.exists == true) // return true if word exists
			    return true;
			if(currentNode == null) // return false if letter didn't exist
			    return false;
			if (!endWord) { // go down to next level
				currentNode = currentNode.children;
				if (currentNode == null) // return false if we can't go down a level
				    return false;
			}
		}
		return false;
	}
	
/*	public boolean remove(String word) {
		
	}*/
	
	public void printChildren() {/*
		trieNode *currentNode = root;

		while (currentNode != NULL) {
			cout << currentNode->character << " ";
			currentNode = currentNode->children;
		}
		cout << endl;*/
	}
	
	public void specialPrint() {/*
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

		cout << endl;*/
	}
	
	private TrieNode insertAtLevel(char ch, TrieNode currentNode, boolean endWord) {

		if(currentNode.character == '\0') { // at a newly created empty node
			currentNode.character = ch;
		    if (endWord) {
		        currentNode.isWord = true;
		    }
		    return currentNode;
		}

	    boolean found = false;
	    TrieNode previousNode = null;
//	    assert(currentNode != NULL);
		while (currentNode != null && !found) {
			if (currentNode.character == ch) {
				found = true;
			} else {
			    previousNode = currentNode;
			    currentNode = currentNode.sibling;
			}
		}
		if (!found) {
		    currentNode = new TrieNode();
			previousNode.sibling = currentNode;
		    currentNode.character = ch;
		}
		if(endWord)
		    currentNode.isWord = true;
		return currentNode;
	}

	private TrieNode existsAtLevel(char ch, TrieNode currentNode, boolean endWord, Exists exists) {
		
		TrieNode previousNode;
		while (currentNode != null) {
			if (currentNode.character == ch) {
			    if (endWord && currentNode.isWord) {
			        exists.exists = true;
			    }
			    return currentNode;
			}
			else {
			    previousNode = currentNode;
			    currentNode = currentNode.sibling;
			}
		}
		return currentNode;
	}
};
