import java.util.*;

public class WordCounter {
    
    private HashMap <String, Integer> wordcounter; 
    private boolean caseSensitive;

    public WordCounter(String s)
    {
        this(s, true);
    }

    public WordCounter(String s, boolean caseSensitive)
    {
        this.caseSensitive = caseSensitive;
        wordcounter = new HashMap<String, Integer>();
        for(String subs: s.split(" "))
        {
            if(!caseSensitive)
                subs = subs.toUpperCase();
            
            Integer new_value = 1;
            if(wordcounter.containsKey(subs))
            {
                new_value = wordcounter.get(subs) + 1;
            }
            wordcounter.put(subs, new_value);
        }
    }

    public String toString(){
        String out = "This is " + (this.caseSensitive == false ? "not ": "") + "case sensitive\n";
        for(String key: wordcounter.keySet())
        {
            out += key + " : " + wordcounter.get(key) + "\n";
        }

        return out;
    }
}
