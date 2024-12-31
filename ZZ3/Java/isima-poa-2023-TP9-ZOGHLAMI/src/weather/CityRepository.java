package weather;

import java.sql.*;
import java.util.ArrayList;
import java.util.List;
import java.util.Objects;

public final class CityRepository implements CrudRepository<City>{

    private Connection connection;

    public CityRepository(String config){
        initConnection(config);
    }

    private void initConnection(String config) {
        // Create a table if it doesn't exist
        try {
            connection = DriverManager.getConnection(Objects.equals(config, "test") ? "jdbc:sqlite:weatherTest.db" : "jdbc:sqlite:weather.db");
            Statement statement = connection.createStatement();
            statement.execute(
                    "CREATE TABLE IF NOT EXISTS weather_data (" +
                            "id INTEGER PRIMARY KEY AUTOINCREMENT," +
                            "city_name TEXT," +
                            "temperature REAL(4)," +
                            "max_temperature REAL(4)," +
                            "min_temperature REAL(4)," +
                            "humidity REAL(4)," +
                            "last_updated TIMESTAMP" +  // Utiliser TIMESTAMP à la place de DATE
                            ");"
            );
        }
        catch (SQLException e) {
            System.out.println("Erreur lors de la connexion à la base de données : " + e.getMessage());
        }
    }

    @Override
    public City getCity(String cityName) {
        City city = null;

        try (PreparedStatement preparedStatement = connection.prepareStatement(
                "SELECT * FROM weather_data WHERE city_name LIKE ?;"
        )) {
            // Récupérer "Arrondissement de Lyon" avec "Lyon"
            preparedStatement.setString(1, "%" + cityName + "%");
            ResultSet resultSet = preparedStatement.executeQuery();

            if (resultSet.next()) {
                city = new City(
                        resultSet.getString("city_name"),
                        new Infos(
                                resultSet.getDouble("temperature"),
                                resultSet.getDouble("max_temperature"),
                                resultSet.getDouble("min_temperature"),
                                resultSet.getDouble("humidity")
                        )
                );
                // Récupérer la date depuis la colonne "last_updated" en tant que Timestamp
                Timestamp timestamp = resultSet.getTimestamp("last_updated");
                // Convertir le Timestamp en java.util.Date
                Date lastUpdated = new Date(timestamp.getTime());
                city.setLastUpdated(lastUpdated);
            }
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }

        return city;
    }


    @Override
    public List<City> getAll(String sortedParam) {
        List<City> cities = new ArrayList<>();

        String query = "SELECT * FROM weather_data;";

        if(sortedParam != null){
            query = "SELECT * FROM weather_data ORDER BY " + sortedParam + ";";
        }

        try (Statement statement = connection.createStatement()) {
            ResultSet resultSet = statement.executeQuery(
                    query
            );
            while (resultSet.next()) {
                City city = new City(
                        resultSet.getString("city_name"),
                        new Infos(
                                resultSet.getDouble("temperature"),
                                resultSet.getDouble("max_temperature"),
                                resultSet.getDouble("min_temperature"),
                                resultSet.getDouble("humidity")
                        )
                );
                // Récupérer la date depuis la colonne "last_updated" en tant que Timestamp
                Timestamp timestamp = resultSet.getTimestamp("last_updated");
                // Convertir le Timestamp en java.util.Date
                Date lastUpdated = new Date(timestamp.getTime());
                city.setLastUpdated(lastUpdated);

                cities.add(city);
            }
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }

        return cities;
    }




    @Override
    public void create(City city) {
        try (PreparedStatement preparedStatement = connection.prepareStatement(
                "INSERT INTO weather_data (city_name, temperature, max_temperature, min_temperature, humidity, last_updated) " +
                        "VALUES (?, ?, ?, ?, ?, ?);"
        )) {
            preparedStatement.setString(1, city.getName());
            preparedStatement.setDouble(2, city.getInfos().getTemp());
            preparedStatement.setDouble(3, city.getInfos().getMaxTemp());
            preparedStatement.setDouble(4, city.getInfos().getMinTemp());
            preparedStatement.setDouble(5, city.getInfos().getHumidity());
            preparedStatement.setTimestamp(6, new Timestamp(city.getLastUpdated().getTime()));

            preparedStatement.execute();
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }
    }

// Même changement pour getCity et getAll



    @Override
    public void update(City city) {
        try (PreparedStatement preparedStatement = connection.prepareStatement(
                "UPDATE weather_data SET temperature = ?, max_temperature = ?, min_temperature = ?, humidity = ?, last_updated = ? WHERE city_name = ?;"
        )) {
            preparedStatement.setDouble(1, city.getInfos().getTemp());
            preparedStatement.setDouble(2, city.getInfos().getMaxTemp());
            preparedStatement.setDouble(3, city.getInfos().getMinTemp());
            preparedStatement.setDouble(4, city.getInfos().getHumidity());
            preparedStatement.setTimestamp(5, new Timestamp(city.getLastUpdated().getTime()));
            preparedStatement.setString(6, city.getName());

            int rowsUpdated = preparedStatement.executeUpdate();

            if (rowsUpdated == 0) {
                System.out.println("La ville n'existe pas dans la base de données.");
            } else {
                System.out.println("Mise à jour réussie.");
            }
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }
    }



    @Override
    public void delete(String cityName) {
        try (PreparedStatement preparedStatement = connection.prepareStatement(
                "DELETE FROM weather_data WHERE city_name LIKE ?;"
        )) {
            preparedStatement.setString(1, "%" + cityName + "%");

            int rowsDeleted = preparedStatement.executeUpdate();

            if (rowsDeleted == 0) {
                System.out.println("La ville n'existe pas dans la base de données.");
            } else {
                System.out.println("Suppression réussie.");
            }
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }
    }
}
