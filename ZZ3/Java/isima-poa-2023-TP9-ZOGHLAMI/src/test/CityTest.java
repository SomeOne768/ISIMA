package test;

import com.google.gson.Gson;
import org.junit.Test;
import weather.City;

import java.io.*;
import java.net.HttpURLConnection;
import java.net.MalformedURLException;
import java.net.URL;

import static org.junit.Assert.*;

public class CityTest {

    String apiKey = "74b0194008b56de27687486cd366d4c0";
    String cityName = "Paris";
    String wrongCityName = "FausseVille";


    @Test
    public void testCityCreation() {
        City city = new City(cityName);
        assertEquals(cityName, city.getName());    }

    @Test
    public void testWrongUrlHttpRequest(){

        HttpURLConnection urlConnection = null ;
        try {
            URL url = new URL ("ht://api.openweathermap.org/data/2.5/weather?q="+ cityName + "&units=metric&appid=" + apiKey);
            urlConnection = (HttpURLConnection) url.openConnection();
            InputStream in = new BufferedInputStream(
                    urlConnection.getInputStream());
            fail("Bad URL http request");
        } catch (MalformedURLException e) {
            // test réussi
        }catch (Exception e) {
            fail("Autre exception");
        } finally {
            if ( urlConnection != null ){
                urlConnection.disconnect ();
            }
        }
    }

    @Test
    public void testHttpRequestWithWrongCity() throws IOException {

        HttpURLConnection urlConnection = null ;
        try {
            URL url = new URL("https://api.openweathermap.org/data/2.5/weather?q="+ wrongCityName + "&units=metric&appid=" + apiKey);
            urlConnection = (HttpURLConnection) url.openConnection();
            int responseCode = urlConnection.getResponseCode();

            // Assert that the response code is 200
            assertEquals(404, responseCode);
        }
        finally{
            if ( urlConnection != null ){
                urlConnection.disconnect ();
            }
        }
    }

    @Test
    public void testHttpRequestWithInvalidApiKey() throws IOException {
        HttpURLConnection urlConnection = null;
        try {
            URL url = new URL("https://api.openweathermap.org/data/2.5/weather?q=" + cityName + "&units=metric&appid=invalid_api_key");
            urlConnection = (HttpURLConnection) url.openConnection();
            int responseCode = urlConnection.getResponseCode();

            assertEquals(401, responseCode); // Assuming 401 is the expected response code for an invalid API key
        } finally {
            if (urlConnection != null) {
                urlConnection.disconnect();
            }
        }
    }

    @Test
    public void testHttpRequestWithEmptyCityName() throws IOException {
        HttpURLConnection urlConnection = null;
        try {
            URL url = new URL("https://api.openweathermap.org/data/2.5/weather?q=&units=metric&appid=" + apiKey);
            urlConnection = (HttpURLConnection) url.openConnection();
            int responseCode = urlConnection.getResponseCode();

            assertEquals(400, responseCode); // Assuming 400 is the expected response code for a bad request
        } finally {
            if (urlConnection != null) {
                urlConnection.disconnect();
            }
        }
    }


    @Test
    public void testHttpRequestCode() throws IOException {

        HttpURLConnection urlConnection = null ;
        try {
            URL url = new URL ("https://api.openweathermap.org/data/2.5/weather?q="+ cityName + "&units=metric&appid=" + apiKey);
            urlConnection = (HttpURLConnection) url.openConnection();

            int responseCode = urlConnection.getResponseCode();

            // Assert that the response code is 200
            assertEquals(200, responseCode);

        } finally {
            if ( urlConnection != null ){
                urlConnection.disconnect ();
            }
        }
    }

    @Test
    public void testGsonCreation() {
        Gson gson = new Gson();
        assertNotNull(gson);
    }

    @Test
    public void testHttpRequestClass() throws IOException{

        HttpURLConnection urlConnection = null ;
        try {
            URL url = new URL ("https://api.openweathermap.org/data/2.5/weather?q="+ cityName + "&units=metric&appid=" + apiKey);
            urlConnection = (HttpURLConnection) url.openConnection();
            InputStream in = new BufferedInputStream(
                    urlConnection.getInputStream());
            InputStreamReader reader = new InputStreamReader(in);

            Gson gson = new Gson();
            City city = gson.fromJson (reader, City.class);

            assertNotNull(city);
            assertNotNull(city.toString());

        } finally {
            if ( urlConnection != null ){
                urlConnection.disconnect ();
            }
        }
    }

    @Test
    public void testHumidity() throws IOException{

        HttpURLConnection urlConnection = null ;
        try {
            URL url = new URL ("https://api.openweathermap.org/data/2.5/weather?q="+ cityName + "&units=metric&appid=" + apiKey);
            urlConnection = (HttpURLConnection) url.openConnection();
            InputStream in = new BufferedInputStream(
                    urlConnection.getInputStream());
            InputStreamReader reader = new InputStreamReader(in);

            Gson gson = new Gson();
            City city = gson.fromJson (reader, City.class);

            assertTrue(city.getInfos().getHumidity() <= 100);
            assertTrue(city.getInfos().getHumidity() >= 0);

        } finally {
            if ( urlConnection != null ){
                urlConnection.disconnect ();
            }
        }
    }

    @Test
    public void testTemp() throws IOException{

        HttpURLConnection urlConnection = null ;
        try {
            URL url = new URL ("https://api.openweathermap.org/data/2.5/weather?q="+ cityName + "&units=metric&appid=" + apiKey);
            urlConnection = (HttpURLConnection) url.openConnection();
            InputStream in = new BufferedInputStream(
                    urlConnection.getInputStream());
            InputStreamReader reader = new InputStreamReader(in);

            Gson gson = new Gson();
            City city = gson.fromJson (reader, City.class);

            assertTrue(city.getInfos().getTemp() <= city.getInfos().getMaxTemp());
            assertTrue(city.getInfos().getTemp() >= city.getInfos().getMinTemp());

        } finally {
            if ( urlConnection != null ){
                urlConnection.disconnect ();
            }
        }
    }


}
