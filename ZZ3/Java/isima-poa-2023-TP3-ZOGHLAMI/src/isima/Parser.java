package isima;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.Reader;
import java.util.ArrayList;
import java.util.List;
import java.util.Collections;

public class Parser {

    public Parser(){
    }

    public List<MetroStop> parse(String filePath) throws Exception {
        List<MetroStop> listMetroStop=new ArrayList<MetroStop>();
        Reader reader = new FileReader(filePath);
        BufferedReader br = new BufferedReader(reader);
        String line;
        while ((line = br.readLine())!= null){
            MetroStop metroStop = new MetroStop();

            String[] parts = line.split("#");

            metroStop.id = Integer.parseInt(parts[0]);
            metroStop.longitude = Double.parseDouble(parts[1]);
            metroStop.latitude = Double.parseDouble(parts[2]);
            metroStop.nom = parts[3];
            metroStop.arrondissement = parts[4];
            metroStop.type = parts[5];

            listMetroStop.add(metroStop);
        }
        br.close();
        reader.close();

        return listMetroStop;
    }

    public static void sortById(List<MetroStop> metroStops) {
        Collections.sort(metroStops);
    }
}