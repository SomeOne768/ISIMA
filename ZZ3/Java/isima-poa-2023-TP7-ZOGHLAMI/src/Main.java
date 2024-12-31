import static java.lang.Thread.sleep;

public class Main {

    public static void main(String[] Args) throws InterruptedException {
        // Initialisation
        Stock stock = new Stock();

        int nbProducteur = 10;
        int nbConsumer = 100;
        Producteur[] producteurs = new Producteur[nbProducteur];
        Consommateur[] consumers = new Consommateur[nbConsumer];


        for(int i=0; i<nbProducteur; i++) {
            producteurs[i] = new Producteur();
            producteurs[i].setStock(stock);
            producteurs[i].start();
        }

        for(int i=0; i<nbConsumer; i++) {
            consumers[i] = new Consommateur();
            consumers[i].setStock(stock);
            consumers[i].start();
        }

        // Closing
        for(int i=0; i<nbProducteur; i++) {
            producteurs[i].join();
        }

        for(int i=0; i<nbConsumer; i++) {
            consumers[i].join();
        }
    }
}
