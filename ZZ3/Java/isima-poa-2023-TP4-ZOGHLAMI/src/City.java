public class City {

    public String name;
    public double latitude;
    public double longitude;

    public City(String name)
    {
        this.name = name;
    }

    public City(double latitude, double longitude)
    {
        this.latitude = latitude;
        this.longitude = longitude;
    }

    public City(String name, double latitude, double longitude) {
        this.name = name;
        this.latitude = latitude;
        this.longitude = longitude;
    }


    @Override
    public String toString() {
        return "City{" +
                "name='" + name + '\'' +
                ", latitude=" + latitude +
                ", longitude=" + longitude +
                '}';
    }
}
