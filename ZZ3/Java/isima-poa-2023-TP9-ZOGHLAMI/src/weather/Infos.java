package weather;

import com.google.gson.annotations.SerializedName;

public final class Infos {

    public Infos(double temp, double maxTemp, double minTemp, double humidity){
        this.temp = temp;
        this.maxTemp = maxTemp;
        this.minTemp = minTemp;
        this.humidity = humidity;
    }

    @SerializedName( "temp" )
    private double temp;
    @SerializedName( "temp_max" )
    private double maxTemp;

    @SerializedName( "temp_min" )
    private double minTemp;

    @SerializedName( "humidity" )
    private double humidity;

    public double getTemp() {
        return temp;
    }

    public void setTemp(double temp) {
        this.temp = temp;
    }

    public double getMaxTemp() {
        return maxTemp;
    }

    public void setMaxTemp(double maxTemp) {
        this.maxTemp = maxTemp;
    }

    public double getMinTemp() {
        return minTemp;
    }

    public void setMinTemp(double minTemp) {
        this.minTemp = minTemp;
    }

    public double getHumidity() {
        return humidity;
    }

    public void setHumidity(double humidity) {
        this.humidity = humidity;
    }

    @Override
    public String toString() {
        return String.format("Infos{temp= %.1f°C, maxTemp= %.1f°C, minTemp= %.1f°C, humidity= %.1f}",
                temp, maxTemp, minTemp, humidity);
    }

}
