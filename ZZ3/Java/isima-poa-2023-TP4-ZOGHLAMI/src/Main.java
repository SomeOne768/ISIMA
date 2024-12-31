import com.google.gson.Gson;
import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.Objects;
import java.util.Scanner;

public class Main {

  public static void main(String[] args) {
    // Initialisation
    final String dbName = "TEST.db";
    final String tableName = "WeatherData";
    String today = new SimpleDateFormat("dd/MM/yyyy").format(new Date());
    String  lang,
            cityName;

    DBManager dbManager = new DBManager(dbName);
    dbManager.createDB();
    dbManager.createTable(tableName);

    System.out.println("""
            Lang:
            1 - FR
            2 - EN""");
    int choice = getChoice();
    lang = (choice == 1) ? "FR" : "EN";
    menu(lang);
    choice = getChoice();

    switch (choice)
    {
      case 1:
        cityName = getCityName(lang);
        String json = dbManager.getJsonData(
                tableName,
                "city_name",
                cityName.toUpperCase(),
                today,
                lang
        );

        if (!Objects.equals(json, "")) {
          // Exist
          Gson gson = new Gson();
          WeatherData weatherData = gson.fromJson(json, WeatherData.class);
          System.out.println(weatherData.displayMainInformation(lang));
        }
        else
        {
          // Doesn't exist, we need to make an API call
          System.out.println("We need to call API to fetch data from remote server");
          Application app = new Application("metric", lang);
          City c = new City(cityName);
          try {
            WeatherData weatherData = app.getWeatherData(c);
            dbManager.saveWeather(tableName, weatherData, lang);
            System.out.println("Data have been fetch");
            System.out.println(weatherData.displayMainInformation(lang));
          } catch (Exception e) {
            System.out.println("Failed to fetch weather data for " + c.name);
            e.printStackTrace();
          }
        }
        break;

      case 2:
        dbManager.displayTable(tableName);
        System.out.println("sorted:");
        dbManager.displayTableSorted(tableName);
        break;

      case 3:
        dbManager.deleteTables();
        break;

      default:
        String s = (lang.equals("FR"))? "Mauvaise saisie":"Wrong input";
        System.out.println(s);
        break;
    }
  }


  public static void menu(String lang)
  {
    if(lang.equals("FR"))
      System.out.println("""
              Que souhaitez-vous faire?
              1 - Récupérer la météo d'une ville
              2 - Afficher la base de donnée
              3 - Effacer la base de donnée
              """);
    else
      System.out.println("""
              What do you want to do?
              1 - Fetch city weather
              2 - Display database
              3 - Erase database
              """);
  }

  public static int getChoice()
  {
    int choice = 0;
    Scanner scanner = new Scanner(System.in);
    String s = scanner.next();
    choice = Integer.parseInt(s);

    return choice;
  }

  public static String getCityName(String lang)
  {
    if(lang.equalsIgnoreCase("FR"))
      System.out.println("Veuillez indiquer le nom de la ville");
    else
      System.out.println("Please type a city name");
    Scanner scanner = new Scanner(System.in);
    return scanner.next();
  }
}
