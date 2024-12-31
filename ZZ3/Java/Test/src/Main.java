import java.io.IOException;
import java.lang.reflect.Array;
import java.util.ArrayList;

public class Main {


    public static void main(String[] args) throws InterruptedException, IOException {

        // Generate 1 000 000 of random int as fast as possible with threads
        int n = 1000000;
        ArrayList<Integer> L = new ArrayList<>();
        ArrayList<Generator> gens = new ArrayList<>();
        for(int i=0; i<10; i++)
        {
            Generator g = new Generator(L, 0, 10000, n);
            g.start();
            gens.add(g);
        }

        System.out.println("List size: " + L.size() + "-");
        for(Generator g : gens)
        {
            g.join();
        }

        // Parseur interface -> JSON or CSV
        CSVParser p = new CSVParser();
        JSONParser j = new JSONParser();
        String CSVfile = "./src/data.csv";
        String JSONfile = "./src/data.json";

        for(Produit elt : p.parse(CSVfile))
        {
            System.out.println(elt);;
        }

        for(Produit elt : j.parse(JSONfile))
        {
            System.out.println(elt);;
        }
    }
}
