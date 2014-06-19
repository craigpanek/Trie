import java.io.FileNotFoundException;
import java.util.Scanner;


public class Main {

	public static void main(String[] args) throws FileNotFoundException {
	    Lexicon lexicon = new Lexicon("Enhanced North American Benchmark Lexicon.txt");
	
	    System.out.println("Enter words to be checked. Enter EOF (Ctrl-z on Windows) when you are done\n");
	    Scanner in = new Scanner(System.in)
	    ;
	    while (in.hasNext()) {
	        String word = in.next();
	        System.out.println(word + " is" + (lexicon.isWord(word) ? "":" NOT") + " a word\n");
	    }
    /*
	    Trie trie = new Trie();

		trie.insert("apple");
		
		trie.insert("apply");
		trie.insert("orange");
		trie.insert("or");

		System.out.println("apply is a word:" + trie.exists("apply") + "\n");
		System.out.println("orange is a word:" + trie.exists("orange") + "\n");
		System.out.println("oranges is a word:" + trie.exists("oranges") + "\n");
		System.out.println("or is a word:" + trie.exists("orange") + "\n");
		System.out.println("app is a word:" + trie.exists("app") + "\n");

		//system("pause"); // if needed, comment out but don't delete
	*/
	}

}
