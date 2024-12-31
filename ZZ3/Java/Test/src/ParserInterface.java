import java.io.FileNotFoundException;
import java.io.IOException;
import java.util.ArrayList;

public interface ParserInterface {

    public ArrayList<Produit> parse(String fileName) throws IOException;
}
