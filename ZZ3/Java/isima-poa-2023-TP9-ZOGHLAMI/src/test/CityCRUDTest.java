package test;

import org.junit.jupiter.api.*;

import weather.City;
import weather.CityRepository;
import weather.Infos;

import java.util.Date;
import java.util.List;

import static org.junit.Assert.assertNotNull;
import static org.junit.jupiter.api.Assertions.*;

public class CityCRUDTest {
    private static CityRepository cityRepository;

    @BeforeAll
    static void setUp() {
        cityRepository = new CityRepository("test");
    }

    @Test
    void testCRUDOperations() {
        City city = new City("TestCity", new Infos(20.0, 25.0, 15.0, 70.0));
        city.setLastUpdated(new Date());

        // CREATE
        cityRepository.create(city);

        // READ
        City retrievedCity = cityRepository.getCity("TestCity");
        Assertions.assertNotNull(retrievedCity);
        Assertions.assertEquals("TestCity", retrievedCity.getName());

        // UPDATE
        retrievedCity.getInfos().setTemp(22.0);
        cityRepository.update(retrievedCity);

        // Vérification la mise à jour
        retrievedCity = cityRepository.getCity("TestCity");
        Assertions.assertEquals(22.0, retrievedCity.getInfos().getTemp());

        // DELETE
        cityRepository.delete("TestCity");

        // Vérification que la ville a été supprimée
        retrievedCity = cityRepository.getCity("TestCity");
        assertNull(retrievedCity);
    }

    @Test
    void testGetAllCities() {
        // Création de plusieurs villes pour le test
        City city1 = new City("City1", new Infos(20.0, 25.0, 15.0, 70.0));
        city1.setLastUpdated(new Date());
        cityRepository.create(city1);

        City city2 = new City("City2", new Infos(18.0, 23.0, 14.0, 72.0));
        city2.setLastUpdated(new Date());
        cityRepository.create(city2);

        City city3 = new City("City3", new Infos(22.0, 26.0, 16.0, 68.0));
        city3.setLastUpdated(new Date());
        cityRepository.create(city3);

        // Toutes les villes triées par nom
        List<City> citiesByName = cityRepository.getAll("city_name");

        // Vérification que la liste n'est pas nulle
        Assertions.assertNotNull(citiesByName);

        // Vérification que les villes sont correctement triées par nom
        assertEquals("City1", citiesByName.get(0).getName());
        assertEquals("City2", citiesByName.get(1).getName());
        assertEquals("City3", citiesByName.get(2).getName());

        // Toutes les villes triées par température
        List<City> citiesByTemperature = cityRepository.getAll("temperature");

        // Vérification que la liste n'est pas nulle
        assertNotNull(citiesByTemperature);

        // Vérification que les villes sont correctement triées par température
        assertEquals(18.0, citiesByTemperature.get(0).getInfos().getTemp());
        assertEquals(20.0, citiesByTemperature.get(1).getInfos().getTemp());
        assertEquals(22.0, citiesByTemperature.get(2).getInfos().getTemp());

        // Suppression des villes créées pour le test
        cityRepository.delete("City1");
        cityRepository.delete("City2");
        cityRepository.delete("City3");
    }

}
