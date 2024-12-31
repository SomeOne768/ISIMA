import com.google.gson.annotations.SerializedName;

public class Rain {
    @SerializedName("1h")
    public double h1;


    @Override
    public String toString() {
        return "Rain{" +
                "h1=" + h1 +
                '}';
    }
}
