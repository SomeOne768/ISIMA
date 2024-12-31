import java.util.ArrayList;
import java.util.List;
import java.util.Random;

public class Consommateur extends Thread{

    //        Cr´eez une classe Consommateur qui consomme entre 1 et 5 PereNoel (al´eatoirement) toutes les secondes.
//                Lorsque le stock est vide ou inssufisant le consommateur doit ˆetre mis en pause le temps que le stock soit
//        suffisament fourni. A chaque fois que le consommateur ach`ete un ` PereNoel, il affiche le num´ero de s´erie.

    public List<PereNoel> santas = new ArrayList<PereNoel>();
    private int consoMin = 1;
    private int consoMax = 5;

    private final int numClient;

    public static int count = 0;

    private Stock stock = null;

    public Consommateur() {
        this.numClient = count++;
    }
    public Consommateur(int consoMin, int consoMax) {
        // consoMin >0;
        this.consoMin = consoMin;
        this.consoMax = consoMax;
        this.numClient = count++;
    }

    public void setStock(Stock stock) {
        this.stock = stock;
    }

    public int consume()
    {
        Random random = new Random();
        int randomNumber = random.nextInt(consoMax - consoMin + 1) + consoMin;
        System.out.println(toString() + " desire: " + randomNumber + " santas.");
        return randomNumber;
    }

    public synchronized void run()
    {
        while(true)
        {
            try{
                int nbDesiredSanta = consume();
                ArrayList<PereNoel> santas = null;
                int stockLeft = -1;

                synchronized (stock) {
                    if (stock == null || stock.getStock() < nbDesiredSanta) {
                        if (stock == null)
                            System.out.println(this + " is waiting for a store to open");
                        else
                            System.out.println(this + " is waiting for a store to have stock");

                    }
                    else
                    {
                        santas = stock.getSanta(nbDesiredSanta);
                        stockLeft = stock.getStock();
                    }
                }

                if (santas != null)
                {
                    for (PereNoel santa : santas) {
                        System.out.println(this + " bought: " + santa);
                        this.santas.add(santa);
                    }
                    if(stockLeft != -1)
                        System.out.println(stockLeft + " santas left in the store");

                    sleep(1000);
                }
                else{
                    while (stock.getStock() <5)
                        wait(2000);
                }

            } catch (InterruptedException e) {
                System.out.println(this + " leaves the store");
                break;
            }

        }
    }

    @Override
    public String toString() {
        return "Consommateur " + numClient;
    }
}
