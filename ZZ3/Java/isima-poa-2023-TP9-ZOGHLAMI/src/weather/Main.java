package weather;

import com.google.gson.Gson;

import java.io.*;
import java.net.HttpURLConnection;
import java.net.MalformedURLException;
import java.net.URL;
import java.sql.*;
import java.util.*;
import java.util.Date;


public class Main {
    private static String apiKey = Credential.apiKey;
    private static CityRepository cityRepo;

    public static void main(String[] argv) {

        try {
            Scanner scanner = new Scanner(System.in);
            cityRepo = new CityRepository("dev");

            int choice;
            do {
                System.out.println("Menu:");
                System.out.println("1. Afficher la météo d'une ville");
                System.out.println("2. Afficher la météo de toutes les villes de la base de données");
                System.out.println("3. Afficher la météo de toutes les villes triées par ville de la base de données");
                System.out.println("4. Afficher la météo de toutes les villes triées par température de la base de données");
                System.out.println("5. Supprimer une ville de la base de données");
                System.out.println("6. Quitter");
                System.out.print("Choix : ");

                while (!scanner.hasNextInt()) {
                    System.out.println("Veuillez entrer un chiffre entre 1 et 6.");
                    System.out.print("Choix : ");
                    scanner.next(); // consomme l'entrée incorrecte
                }

                choice = scanner.nextInt();
                scanner.nextLine(); // consume the newline character

                switch (choice) {
                    case 1:
                    {
                        System.out.print("Veuillez entrer un nom de ville : ");
                        String cityName = scanner.nextLine();
                        City city = cityRepo.getCity(cityName);
                        if(city == null){
                            city = callWeatherAPI(cityName);
                            city.setLastUpdated(new Date());
                            cityRepo.create(city);
                            city = cityRepo.getCity(cityName);
                        }
                        else{
                            if(!isWeatherUpdated(city)){
                                city = callWeatherAPI(cityName);
                                city.setLastUpdated(new Date());
                                cityRepo.update(city);
                                city = cityRepo.getCity(cityName);
                            }
                        }
                        System.out.println(city);
                    }
                    break;
                    case 2:
                    {
                        List<City> allCities = cityRepo.getAll(null);
                        allCities.forEach(System.out::println);
                    }
                    break;
                    case 3:
                    {
                        List<City> allCities = cityRepo.getAll("city_name");
                        allCities.forEach(System.out::println);
                    }
                    break;
                    case 4:
                    {
                        List<City> allCities = cityRepo.getAll("temperature");
                        allCities.forEach(System.out::println);
                    }
                    break;
                    case 5:
                        System.out.print("Veuillez entrer un nom de ville à supprimer: ");
                        String cityName = scanner.nextLine();
                        cityRepo.delete(cityName);
                        break;
                    case 6:
                        System.out.println("Au revoir !");
                        break;
                    default:
                        System.out.println("Choix invalide. Veuillez réessayer.");
                }

            } while (choice != 6);

            scanner.close();
        } catch (Exception e) {
            System.out.println(e.getMessage());
            e.printStackTrace();
        }
    }

    private static City callWeatherAPI(String cityName){
        HttpURLConnection urlConnection = null ;
        City city = null;

        try {
            URL url = new URL ("https://api.openweathermap.org/data/2.5/weather?q="+ cityName + "&units=metric&appid=" + apiKey);
            urlConnection = ( HttpURLConnection ) url.openConnection();

            InputStream in = new BufferedInputStream(
                    urlConnection.getInputStream());
            InputStreamReader reader = new InputStreamReader(in);
            city = readStreamReader(reader);

        }catch (MalformedURLException e) {
            System.out.println("L'url n'est pas bonne :" + e.getMessage());
        }catch(IOException e){
            System.out.println("Pas de données pour cette ville : " + cityName);
        }
        finally {
            if ( urlConnection != null ){
                urlConnection.disconnect ();
            }
        }
        return city;
    }

    private static City readStreamReader(InputStreamReader br) {
        Gson gson = new Gson();
        City city = gson.fromJson (br, City.class);
        return city;
    }

    private static boolean isWeatherUpdated(City city) {
        Calendar lastUpdatedCalendar = Calendar.getInstance();
        lastUpdatedCalendar.setTime(city.getLastUpdated());

        Calendar now = Calendar.getInstance();

        long milliseconds = now.getTimeInMillis() - lastUpdatedCalendar.getTimeInMillis();
        long seconds = milliseconds / 1000;

        return seconds < 3600;
    }
}