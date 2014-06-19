import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

/**
 * A class that represents a list of words and that can be interrogated to
 * determine whether or not word exists in the list. The file that contains
 * the list of words is sent to the constructor.
 */
class Lexicon {

	private Trie trie = new Trie();

	/**
	 * Initializes the lexicon, given the file name that contains the list
	 * of words.
	 * @param lexiconFileName the file name that contains the list of words.
	 * @throws FileNotFoundException 
	 */
	public Lexicon(String lexiconFileName) throws FileNotFoundException {
	    loadLexicon(lexiconFileName);
	}

	/**
	 * Returns true if word exists in lexicon
	 * @param word the word for which to search
	 * @return true if word exists in lexicon, and false otherwise
	 */
	public boolean isWord(String word) {
	    return (trie.exists(word));
	}

	/**
	 * Loads lexicon from lexiconFileName, exiting with an error message on
	 * stderr if lexiconFileName cannot be opened.
	 * @param lexiconFileName the file name that contains the list of words.
	 * @throws FileNotFoundException 
	 */
	public void loadLexicon(String lexiconFileName) throws FileNotFoundException {
	    File inputFile = new File("Enhanced North American Benchmark Lexicon.txt");
	    Scanner in = new Scanner(inputFile);
	    while(in.hasNext()) {
	    	String word = in.next();
	    	trie.insert(word);
	    }
	    in.close();
		/*
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
	    inWords.close();*/
	}
}
