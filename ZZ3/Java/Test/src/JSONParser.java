import com.google.gson.Gson;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.Reader;
import java.util.ArrayList;
import java.util.Arrays;

public class JSONParser extends Parser implements ParserInterface {

    public ArrayList<Produit> parse(String fileName) throws IOException {
        ArrayList<Produit> elts = new ArrayList<>();
        Reader reader = new FileReader(fileName);
        BufferedReader br = new BufferedReader(reader);
        String line;

        while((line = br.readLine()) != null)
        {
            Gson gson = new Gson();
            Produit[] p = gson.fromJson(line, Produit[].class);
            elts.addAll(Arrays.asList(p));
        }



        return elts;
    }
}
