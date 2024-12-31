import static java.lang.Integer.parseInt;

public class Parser {

    public Produit parseLine(String line, String separator)
    {
        String[] elt = line.split(separator);
        return new Produit(parseInt(elt[0]), parseInt(elt[1]), parseInt(elt[2]));
    }
}
