package weather;

import com.google.gson.annotations.SerializedName;

import java.sql.Timestamp;
import java.time.Duration;
import java.time.Instant;
import java.util.Calendar;
import java.util.Date;

public final class City {
    public City(String name){
        this.name = name;
    }

    public City(String name, Infos infos){
        this.name = name;
        this.infos = infos;
    }

    private String name;

    private Date lastUpdated;

    @SerializedName( "coord" )
    private Coord coord;

    @SerializedName( "main" )
    private Infos infos;

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public Infos getInfos(){
        return infos;
    }

    public Date getLastUpdated() {
        return lastUpdated;
    }

    public String getLastUpdatedStringFormat() {
        Calendar lastUpdatedCalendar = Calendar.getInstance();
        lastUpdatedCalendar.setTime(lastUpdated);

        Calendar now = Calendar.getInstance();

        long milliseconds = now.getTimeInMillis() - lastUpdatedCalendar.getTimeInMillis();
        long seconds = milliseconds / 1000;
        long hours = seconds / 3600;
        long minutes = (seconds % 3600) / 60;
        long days = hours / 24;
        seconds = seconds % 60;

        return String.format("Dernière mise à jour il y a %d jours, %d heures, %d minutes, %d secondes", days, hours % 24, minutes, seconds);
    }





    public void setLastUpdated(Date lastUpdated) {
        this.lastUpdated = lastUpdated;
    }

    @Override
    public String toString() {
        return String.format("%s, temp= %.1f°C, minTemp= %.1f°C, maxTemp= %.1f°C, humidity= %.1f%%\n%s\n",
                name, infos.getTemp(), infos.getMinTemp(), infos.getMaxTemp(), infos.getHumidity(), getLastUpdatedStringFormat());
    }

}
