/**
 * A class that tests the trie data structure and class.
 * @author Craig Panek
 * Date: 6-19-2014
 */

import java.io.FileNotFoundException;
import java.util.Scanner;

public class TrieTester {

	public static void main(String[] args) throws FileNotFoundException {
	    Dictionary dictionary = new Dictionary("Enhanced North American Benchmark Lexicon.txt");
	
	    System.out.println("Enter words to be checked. Enter EOF (Ctrl-z on Windows) when you are done\n");
	    Scanner in = new Scanner(System.in);
	    while (in.hasNext()) {
	        String word = in.next();
	        System.out.println(word + " is" + (dictionary.isWord(word) ? "" : " NOT") + " a word.");
	    }
	    in.close();
	}
}
