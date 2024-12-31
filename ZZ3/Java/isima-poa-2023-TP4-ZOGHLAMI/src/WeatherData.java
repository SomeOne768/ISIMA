import com.google.gson.annotations.SerializedName;

import java.util.Arrays;
import java.util.Date;

public class WeatherData {
    public Coord coord;
    public Weather[] weather;
    public String base;
    @SerializedName("main")
    public Temperature temperature;
    public int visibility;
    public Wind wind;
    public Rain rain;
    public Clouds clouds;
    public long dt;
    public Sys sys;
    public int timezone;
    public int id;
    public String name;
    public int cod;

    public String date;

    @Override
    public String toString() {
        return "WeatherData{" +
                "coord=" + coord +
                ", weather=" + Arrays.toString(weather) +
                ", base='" + base + '\'' +
                ", temperature=" + temperature +
                ", visibility=" + visibility +
                ", wind=" + wind +
                ", rain=" + rain +
                ", clouds=" + clouds +
                ", dt=" + dt +
                ", sys=" + sys +
                ", timezone=" + timezone +
                ", id=" + id +
                ", name='" + name + '\'' +
                ", cod=" + cod +
                ", date=" + date +
                '}';
    }

    public String displayMainInformation(String lang)
    {
        StringBuilder s = new StringBuilder();
        for(Weather w: weather) s.append(w.description);
        return name + " ("+ coord.lon + ", "+ coord.lat  +")" +
                " " + date + ":" +
                temperature.temp +
                "°C, " + (lang.equals("en")? "feels_like:":"ressentie:") + temperature.feels_like +
                "°C, " + "min:" + temperature.temp_min +
                "°C, " + "max:" + temperature.temp_max +
                "°C, " + (lang.equals("en")? "humidity:":"humidité:") + temperature.humidity +
                ", " + s;
    }
}

