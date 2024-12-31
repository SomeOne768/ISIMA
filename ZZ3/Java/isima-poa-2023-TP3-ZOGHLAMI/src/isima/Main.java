package isima;

import java.io.*;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
    interface PrintTest {
        public boolean test(MetroStop s);
    }

    private static void print(PrintStream out, ArrayList<MetroStop> l, PrintTest test) {
        for (MetroStop it : l) {
            if (test.test(it))
                out.println(it);
        }
    }

    private static void print(PrintStream out, ArrayList<MetroStop> l) {
        print(out, l, (s) -> true);
    }

    public static void main(String[] argv) {
        int choice = -1;
        Parser parser = new Parser();
        List<MetroStop> L = null;
        Scanner scanner = new Scanner(System.in);
        String defaultFilepath = "/home/jalil/Documents/ZZ3/isima-poa-2023-TP3-ZOGHLAMI/src/isima/data/ratp_arret.csv";

        while (choice != 6) {
            menu();
            try {
                String s = scanner.next();
                choice = Integer.parseInt(s);
            } catch (Exception e) {
                System.out.println("Veuillez saisir un entier compris entre 1 et 5");
                choice = 0;
            }

            switch (choice) {
                case 1:
                    System.out.println("Saisissez le chemin absolu du fichier");
                    String filepath = scanner.next();
                    try {
                        L = parser.parse(filepath);
                    } catch (Exception e) {
                        System.out.println("Chemin invalide");
                    }
                    break;

                case 2:
                    if (L == null) {
                        System.out.println("Veuillez charger un fichier");
                        break;
                    }

                    Parser.sortById(L);
                    break;

                case 3:
                    if (L == null) {
                        System.out.println("Veuillez charger un ficher");
                        break;
                    }

                    for (MetroStop ms : L)
                        System.out.println(ms);
                    break;

                case 4:
                    if (L == null) {
                        System.out.println("Veuillez charger un ficher");
                        break;
                    }

                    System.out.println("Veuillez saisir un ID");
                    int id = scanner.nextInt();
                    try {
                        System.out.println(getElementById(L, id));
                    } catch (Exception e) {
                        System.out.println("Cet id n'existe pas");
                    }
                    break;

                case 5:
                    try {
                        L = parser.parse(defaultFilepath);
                    } catch (Exception e) {
                        System.out.println("Veuillez télécharger le fichier ratp_arret.csv " +
                                "et le mettre dans le dossier src/isima/data");
                    }
                    break;

                default:
                    break;
            }
        }
    }

    public static void menu() {

        System.out.println("Que souhaitez-vous faire ?\n" +
                "1. Charger un fichier?\n" +
                "2. Trier votre Liste\n" +
                "3. Afficher votre Liste\n" +
                "4. Afficher un MetroStop en particulier (via son ID) ?\n" +
                "5. Charger un fichier par defaut ?\n" +
                "6. Fermer le programme?");
    }

    public static MetroStop getElementById(List<MetroStop> metroStops, int id) throws NullPointerException {
        for (MetroStop ms : metroStops) {
            if (ms.id == id)
                return ms;
        }

        throw new NullPointerException();
    }
}