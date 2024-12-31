import com.google.gson.Gson;
import com.google.gson.JsonObject;
import com.google.gson.JsonParser;

import javax.naming.directory.InvalidAttributesException;
import java.io.*;
import java.net.HttpURLConnection;
import java.net.URL;
import java.text.SimpleDateFormat;
import java.util.Date;

public class Application {

    public String unit = "metric";
    public String lang = "fr";
    private final String key = "74b0194008b56de27687486cd366d4c0";

    public Application() {

    }

    public Application(String unit) {
        // Fahrenheit: "imperial"
        // Celsius: "metric"
        // Kelvin: default or "Kelvin"
        if (unit.equals("imperial") || unit.equals("metric") || unit.equals("Kelvin") || unit.isEmpty())
            this.unit = unit;
    }

    public Application(String unit, String lang) {
        // Fahrenheit: "imperial"
        // Celsius: "metric"
        // Kelvin: default or "Kelvin"
        if (unit.equals("imperial") || unit.equals("metric") || unit.equals("Kelvin") || unit.isEmpty())
            this.unit = unit;
        lang = lang.toUpperCase();
        if(lang.equals("FR") || lang.equals("EN"))
            this.lang = lang;
    }

    public String getUrl(String cityName) {
        return "https://api.openweathermap.org/data/2.5/weather?q=" + cityName + "&appid=" + key + "&units=" +
                unit + "&lang=" + lang;
    }

    public String getUrl(double latitude, double longitude) {
        return "https://api.openweathermap.org/data/2.5/weather?lat=" + latitude + "&lon=" + longitude +
                "&appid=" + key + "&units=" +  unit + "&lang=" + lang;
    }

    public String getUrl(City city) throws InvalidAttributesException {
        String url;

        if(city.name != null && !city.name.isEmpty())
            url = getUrl(city.name);
        else if (city.latitude != 0.0 && city.longitude != 0.0)
            url = getUrl(city.latitude, city.longitude);
        else
            throw new InvalidAttributesException();

        return  url;
    }

    public String fetchApiInfo(City city) throws InvalidAttributesException
    {
        HttpURLConnection urlConnection = null ;
        String apiResponse="";

        try {
            String api = getUrl(city);
            URL url = new URL(api);
            urlConnection = (HttpURLConnection) url.openConnection();
            InputStream in = new BufferedInputStream(
                    urlConnection.getInputStream());
            InputStreamReader isr = new InputStreamReader(in);
            BufferedReader br = new BufferedReader(isr);
            apiResponse = br.readLine();
        }
        catch (InvalidAttributesException | FileNotFoundException e)
        {
            throw new InvalidAttributesException("Invalid attribute found");
        }
        catch (Exception e)
        {
            e.printStackTrace();
        }
        finally {
            if ( urlConnection != null ){
                urlConnection.disconnect ();
            }
        }

        return apiResponse;
    }

    public WeatherData getWeatherData(City city) throws InvalidAttributesException
    {
        WeatherData weatherData;
        try {
            String response = fetchApiInfo(city);
            Gson gson = new Gson();
            weatherData = gson.fromJson(response, WeatherData.class);
            weatherData.date = new SimpleDateFormat("dd/MM/yyyy").format(new Date());
        }
        catch (InvalidAttributesException e)
        {
            throw new  InvalidAttributesException("Invalide attribute found");
        }
        catch (IllegalArgumentException e)
        {
            throw new  InvalidAttributesException("response is not the one expected");
        }

        return weatherData;
    }
}
