public class Producteur extends Thread {
    private Stock stock = null;
    private static int count = 0;
    private final int numProducteur;

    public Producteur() {
        this.numProducteur = count++;
    }

    public synchronized void run() {
        while (true) {
            try {
                boolean isFull = false;
                if (stock!=null) {
                    synchronized (stock)
                    {
                        if(!stock.isFull()) {
                            PereNoel santa = product();
                            System.out.println("Producteur " + numProducteur + ":" + santa);
                            stock.addSanta(santa);
                        }
                        else
                        {
                            isFull = true;
                        }
                    }
                    sleep(2000);
                }

                if(stock == null || isFull) {
                    System.out.println("Producteur " + numProducteur + " is waiting");
                    while(stock.hasSanta())
                        wait(4000);
                }
            } catch (InterruptedException e) {
                System.out.println("We are out of chocolate. The factory close, sorry!");
                throw new RuntimeException(e);
            }
        }
    }

    private PereNoel product() throws InterruptedException {
        return new PereNoel();
    }

    public void setStock(Stock stock) {
        this.stock = stock;
    }


}
