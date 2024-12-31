public class Temperature {
    public double temp;
    public double feels_like;
    public double temp_min;
    public double temp_max;
    public int pressure;
    public int humidity;

    @Override
    public String toString() {
        return "Temperature{" +
                "temp=" + temp +
                "°C, feels_like=" + feels_like +
                "°C, temp_min=" + temp_min +
                "°C, temp_max=" + temp_max +
                "°C, pressure=" + pressure +
                ", humidity=" + humidity +
                '}';
    }
}