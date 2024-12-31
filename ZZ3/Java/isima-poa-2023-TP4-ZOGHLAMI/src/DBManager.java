import com.google.gson.Gson;
import com.google.gson.JsonObject;
import org.sqlite.SQLiteException;

import java.sql.*;
import java.util.ArrayList;
import java.util.List;
import java.util.Objects;

public class DBManager {
    private final  String dbName;

    public DBManager(String dbName)
    {
        this.dbName = dbName;
    }

    public Connection getSQLClient() throws SQLException
    {
        Connection connection;
        try {
            String DBurl = "jdbc:sqlite:" + dbName;
            connection = DriverManager.getConnection(DBurl);
        }catch (SQLException e)
        {
            e.printStackTrace();
            throw new SQLException();
        }

        return connection;
    }
    public void createDB()
    {
        try {
            Class.forName("org.sqlite.JDBC");
            String DBurl = "jdbc:sqlite:" + dbName;
            Connection connection = DriverManager.getConnection(DBurl);
            connection.close();
        }catch (SQLException e)
        {
            System.out.println("Db " + dbName + " already exist");
        }catch (Exception e)
        {
            e.printStackTrace();
        }
    }

    public void createTable(String tableName) {
        Connection connection = null;
        Statement stmt = null;

        try {
            connection = getSQLClient();
            stmt = connection.createStatement();

            String request = "CREATE TABLE IF NOT EXISTS " + tableName + " (" +
                    "id INTEGER PRIMARY KEY AUTOINCREMENT," +
                    "lat DECIMAL(10, 6)," +
                    "long DECIMAL(10, 6)," +
                    "temperature FLOAT," +
                    "sys_country VARCHAR(10)," +
                    "city_name VARCHAR(100)," +
                    "cod INT," +
                    "weather_description VARCHAR(25)," +
                    "jsonObj JSON," +
                    "date VARCHAR(11)," +
                    "country_code VARCHAR(3)" +
                    ");";

            int nbMaj = stmt.executeUpdate(request);
            System.out.println("Number of updates = " + nbMaj);

        } catch (SQLException e) {
            System.out.println("Error while attempting to create the table: " + e.getMessage());
        } finally {
            try {
                if (stmt != null) {
                    stmt.close();
                }
                if (connection != null) {
                    connection.close();
                }
            } catch (Exception e) {
                System.out.println("Error closing resources: " + e.getMessage());
            }
        }
    }

    public boolean deleteTables() {
        Connection connection = null;
        boolean success = true;
        Statement stmt = null;
        try {
            connection = getSQLClient();

            DatabaseMetaData metaData = connection.getMetaData();
            ResultSet tables = metaData.getTables(null, null, "%", new String[]{"TABLE"});

            ArrayList<String> tablesNames = new ArrayList<String>();

            while (tables.next()) {
                String tableName = tables.getString("TABLE_NAME");
                tablesNames.add(tableName);
            }
            tables.close();

            for(String tableName : tablesNames)
            {
                String request = "DROP TABLE " + tableName;
                stmt = connection.createStatement();
                stmt.executeUpdate(request);
                System.out.println("Table " + tableName + " deleted.");
            }
        } catch (Exception e) {
            System.out.println("Error from deleting");
            e.printStackTrace();
            success = false;
        } finally {
            try {
                if (stmt != null) {
                    stmt.close();
                }
                if (connection != null) {
                    connection.close();
                }
            } catch (SQLException e) {
                e.printStackTrace();
            }
        }

        return success;
    }

    public void saveWeather(String tableName, WeatherData weatherData, String lang )
    {
        // Json converter to stock whole data
        Gson gson = new Gson();
        String json = gson.toJson(weatherData);

        String request = "INSERT INTO '" + tableName +"' (lat, long, temperature, sys_country, city_name, " +
                "cod, weather_description, jsonObj, date, country_code) VALUES (" +
                weatherData.coord.lat + ", " +
                weatherData.coord.lon + ", " +
                weatherData.temperature.temp + ", " +
                "'" + weatherData.sys.country + "', " +
                "'" + weatherData.name.toUpperCase() + "', " +
                weatherData.cod + ", " +
                "'" + ((weatherData.weather != null && weatherData.weather.length > 0 && weatherData.weather[0].description != null) ? weatherData.weather[0].description : "") + "'" +
                ", '" + json +
                "', '" + weatherData.date +
                "', '" + lang.toUpperCase() +
                "')";

        Connection connection = null;
        try {
            connection = getSQLClient();
            Statement stmt = connection.createStatement();
            int nbMaj = stmt.executeUpdate(request);
            System.out.println("Number of updates = " + nbMaj);

            stmt.close();
            connection.close();
        }
        catch (Exception e)
        {
            e.printStackTrace();
        }

    }


    public void displayTable(String tableName)
    {
        String request = "SELECT * FROM " + tableName;
        Connection connection = null;
        Statement stmt = null;
        ResultSet resultSet = null;

        try
        {
            connection = getSQLClient();
            stmt = connection.createStatement();
            resultSet =  stmt.executeQuery(request);
            int nbColumns = resultSet.getMetaData().getColumnCount();

            for (int i = 1; i <= nbColumns; i++) {
                String s = resultSet.getMetaData().getColumnName(i);
                System.out.print(s + "\t");
            }
            System.out.println();

            while(resultSet.next())
            {
                for (int i = 1; i <= nbColumns; i++) {

                    int columnType = resultSet.getMetaData().getColumnType(i);

                    if (columnType == java.sql.Types.BOOLEAN) {
                        System.out.print(resultSet.getBoolean(i) + "\t");
                    } else if (columnType == java.sql.Types.FLOAT || columnType == java.sql.Types.DOUBLE) {
                        System.out.print(resultSet.getFloat(i) + "\t");
                    } else if (columnType == java.sql.Types.INTEGER) {
                        System.out.print(resultSet.getInt(i) + "\t");
                    } else {
                        System.out.print(resultSet.getString(i) + "\t");
                    }
                }
                System.out.println();
            }
        }
        catch (SQLException e)
        {
            System.out.println("Table does not exist");
        }
        catch (Exception e)
        {
            e.printStackTrace();
        }
        finally {
            try {
                if(connection != null)
                {
                    connection.close();
                }

                if(stmt != null)
                {
                    stmt.close();
                }

                if(resultSet != null)
                {
                    resultSet.close();
                }

            }catch (Exception e)
            {
                e.printStackTrace();
            }
        }
    }


    public void displayTableSorted(String tableName)
    {
        String request = "SELECT * FROM " + tableName + " ORDER BY city_name, temperature ASC";
        Connection connection = null;
        Statement stmt = null;
        ResultSet resultSet = null;

        try
        {
            connection = getSQLClient();
            stmt = connection.createStatement();
            resultSet =  stmt.executeQuery(request);
            int nbColumns = resultSet.getMetaData().getColumnCount();

            for (int i = 1; i <= nbColumns; i++) {
                String s = resultSet.getMetaData().getColumnName(i);
                System.out.print(s + "\t");
            }
            System.out.println();

            while(resultSet.next())
            {
                for (int i = 1; i <= nbColumns; i++) {

                    int columnType = resultSet.getMetaData().getColumnType(i);

                    if (columnType == java.sql.Types.BOOLEAN) {
                        System.out.print(resultSet.getBoolean(i) + "\t");
                    } else if (columnType == java.sql.Types.FLOAT || columnType == java.sql.Types.DOUBLE) {
                        System.out.print(resultSet.getFloat(i) + "\t");
                    } else if (columnType == java.sql.Types.INTEGER) {
                        System.out.print(resultSet.getInt(i) + "\t");
                    } else {
                        System.out.print(resultSet.getString(i) + "\t");
                    }
                }
                System.out.println();
            }
        }
        catch (SQLException e)
        {
            System.out.println("Table does not exist");
        }
        catch (Exception e)
        {
            e.printStackTrace();
        }
        finally {
            try {
                if(connection != null)
                {
                    connection.close();
                }

                if(stmt != null)
                {
                    stmt.close();
                }

                if(resultSet != null)
                {
                    resultSet.close();
                }

            }catch (Exception e)
            {
                e.printStackTrace();
            }
        }
    }


    public String getJsonData(String tableName, String columnName, String columnValue, String date, String lang)
    {
        String request = "SELECT jsonObj, date, country_code FROM " + tableName +" WHERE "+ columnName +" = '" + columnValue +"'" +
               " AND date='" + date +"' AND country_code='" + lang.toUpperCase() + "'";
        Connection connection = null;
        Statement stmt = null;
        ResultSet resultSet = null;
        String json = "";
        try
        {
            connection = getSQLClient();
            stmt = connection.createStatement();
            resultSet = stmt.executeQuery(request);

            if(resultSet.next())
            {
                Gson gson = new Gson();
                json = resultSet.getString("jsonObj");
            }
            else {
                System.out.println("no data");
            }

        }
        catch (Exception e)
        {
            e.printStackTrace();
        }
        finally {
            try {
                if (connection != null) {
                    connection.close();
                }

                if(stmt != null)
                {
                    stmt.close();
                }

                if(resultSet != null)
                {
                    resultSet.close();
                }
            }
            catch (Exception e)
            {
                e.printStackTrace();
            }
        }

        return json;
    }
}
