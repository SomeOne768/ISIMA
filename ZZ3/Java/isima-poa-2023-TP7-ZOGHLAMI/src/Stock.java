import java.util.ArrayList;

public class Stock {
    private int stock = 0;

    private  static  int count = 0;
    private final int numStock;
    private ArrayList<PereNoel> santas = new ArrayList<>();;

    public Stock() {
        this.numStock = count++;
    }

    public int getStoreId()
    {
        return numStock;
    }

    public void addSanta(PereNoel p)
    {
        santas.add(p);
        stock++;
    }

    public boolean isFull()
    {
        return stock == 100;
    }

    public boolean hasSanta()
    {
        return stock != 0;
    }

    public boolean hasSanta(int n)
    {
        return stock >= n;
    }

    public ArrayList<PereNoel> getSanta(int n)
    {
        //  1 <= n <= 5
        if( (stock - n) < 0)
            return null;

        ArrayList<PereNoel> L = new ArrayList<>();

        for(int i=0; i<n; i++)
        {
            L.add(santas.get(0));
            santas.remove(0);
            stock--;
        }

        return  L;
    }

    public int getStock() {
        return stock;
    }
}
