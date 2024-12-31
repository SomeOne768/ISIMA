package isima;

public class MetroStop implements Comparable<MetroStop> {
    public int id;
    public double longitude;
    public double latitude;
    public String nom;
    public String arrondissement;
    public String type;

    @Override
    public String toString() {
        return "MetroStop{" +
                "id=" + id +
                ", longitude=" + longitude +
                ", latitude=" + latitude +
                ", nom='" + nom + '\'' +
                ", arrondissement='" + arrondissement + '\'' +
                ", type='" + type + '\'' +
                '}';
    }


    public static MetroStop MetroSample()
    {
        MetroStop metroStop = new MetroStop();
        metroStop.id = 1;
        metroStop.longitude = 49.3;
        metroStop.latitude = 58.5;
        metroStop.nom = "Borne";
        metroStop.arrondissement = "PARIS-4EME";
        metroStop.type = "Virus";

        return  metroStop;
    }

//    @Override
//    public boolean compareTo(MetroStop m)
//    {
//        return this.id <= m.id;
//    }

    @Override
    public int compareTo(MetroStop m) {
        return Integer.compare(this.id, m.id);
    }
}