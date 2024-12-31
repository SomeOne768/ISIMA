package weather;

import com.google.gson.annotations.SerializedName;

public final class Coord {
    @SerializedName( "long" )
    private double longitude;
    @SerializedName ( "lat" )
    private double latitude;

    @Override
    public String toString() {
        return "Coord{" +
                "longitude=" + longitude +
                ", latitude=" + latitude +
                '}';
    }
}
