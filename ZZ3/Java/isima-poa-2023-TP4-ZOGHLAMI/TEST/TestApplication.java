import junit.framework.TestCase;

import javax.naming.directory.InvalidAttributesException;
import java.io.FileNotFoundException;
import java.io.IOException;

public class TestApplication extends TestCase {
    private  Application app;

    @Override
    protected void setUp() throws Exception{
        super.setUp();
        app = new Application("metrics", "fr");
    }

    @Override
    protected void tearDown() throws Exception{
        super.tearDown();
        app = null;
    }

    public void testFetchApiInfo200() {
        City city = new City("Clermont-Ferrand");
        try {
            String apiResponse = app.fetchApiInfo(city);
            assertNotNull(apiResponse);
            assertFalse(apiResponse.isEmpty());
        } catch (InvalidAttributesException e) {
            fail("Unexpected attribut error thrown");
        }
        catch (Exception e)
        {
            fail("Unexpected HTTP response");
        }
    }

    public void testFetchApiInfo404() {
        City city = new City("IncorrectName");
        try {
            String apiResponse = app.fetchApiInfo(city);
            fail("Expected InvalidAttributesException but was not thrown");

        } catch (InvalidAttributesException e) {
            assertNotNull(e.getMessage());
        }
        catch (Exception e)
        {
            e.printStackTrace();
        }
    }


    public void testGetWeatherData200() {
        City city = new City("Clermont-Ferrand");

        try {
            WeatherData weatherData = app.getWeatherData(city);
            assertNotNull(weatherData);
        } catch (InvalidAttributesException e) {
            fail("Unexpected exception: " + e);
        }
    }

    public void testGetWeatherData404() {
        City city = new City("IncorrectName");

        try {
            WeatherData weatherData = app.getWeatherData(city);
            fail("Expected InvalidAttributesException but was not thrown");
        } catch (InvalidAttributesException e) {
            assertNotNull(e.getMessage());
        }catch (Exception e) {
            fail("Unexpected exception: " + e);
        }
    }
}
