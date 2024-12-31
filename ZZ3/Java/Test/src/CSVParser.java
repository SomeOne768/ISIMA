import java.io.*;
import java.util.ArrayList;

public class CSVParser extends Parser implements ParserInterface {

    public ArrayList<Produit> parse(String fileName) throws IOException {
        ArrayList<Produit> elts = new ArrayList<>();
        Reader reader = new FileReader(fileName);
        BufferedReader br = new BufferedReader(reader);
        String line;

        while((line = br.readLine()) != null)
        {
            elts.add(super.parseLine(line, ";"));
        }

        return elts;
    }

}
