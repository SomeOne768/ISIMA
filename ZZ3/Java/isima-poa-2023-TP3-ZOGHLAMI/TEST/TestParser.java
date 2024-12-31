import isima.MetroStop;
import isima.Parser;
import junit.framework.TestCase;

import java.util.List;
import java.io.FileNotFoundException;

public class TestParser extends TestCase {
    private Parser p;

    @Override
    protected void setUp() throws Exception {
        super.setUp();
        p = new Parser();
    }

    @Override
    protected void tearDown() throws Exception {
        super.tearDown();
        p = null;
    }

    public void testTrue() {
        assertTrue(true);
    }

    public void testWrongFileImport() {
        try {
            p.parse("Not existing file");
            fail("Should fail before");
        } catch (Exception e) {
            assertTrue(e instanceof FileNotFoundException);
        }
    }

    public void testCorrectFileImport() {
        try {
            p.parse("/home/jalil/Documents/ZZ3/isima-poa-2023-TP3-ZOGHLAMI/src/isima/data/ratp_arret.csv");
        } catch (Exception e) {
            fail("Shouldn't raise exception");
        }
    }

    public void testParse() {
        List<MetroStop> L;
        try {
            L = p.parse("/home/jalil/Documents/ZZ3/isima-poa-2023-TP3-ZOGHLAMI/src/isima/data/ratp_arret.csv");

            // First: 1975#2.33871281165883#48.8844176451841#Abbesses#PARIS-18EME#metro
            MetroStop ms = L.get(0);
            assertEquals(ms.id, 1975);
            assertEquals(ms.longitude, 2.33871281165883);
            assertEquals(ms.latitude, 48.8844176451841);
            assertEquals(ms.nom, "Abbesses");
            assertEquals(ms.arrondissement, "PARIS-18EME");
            assertEquals(ms.type, "metro");

            // Last: 445422#2.23014400439772#48.9137080056912#VICTOR BASCH#COLOMBES#tram
            ms = L.get(L.size() - 1);
            assertEquals(ms.id, 445422);
            assertEquals(ms.longitude, 2.23014400439772, 0.01);
            assertEquals(ms.latitude, 48.9137080056912, 0.01);
            assertEquals(ms.nom, "VICTOR BASCH");
            assertEquals(ms.arrondissement, "COLOMBES");
            assertEquals(ms.type, "tram");
        } catch (Exception e) {
            fail("should not fail");
        }

    }

    public void testParsedList() {
        try {
            List<MetroStop> L = p.parse("/home/jalil/Documents/ZZ3/isima-poa-2023-TP3-ZOGHLAMI/src/isima/data/ratp_arret.csv");
            List<MetroStop> L2 = p.parse("/home/jalil/Documents/ZZ3/isima-poa-2023-TP3-ZOGHLAMI/src/isima/data/ratp_arret.csv.1");
            assertEquals(L.size(), 12012);
            assertEquals(L2.size(), 12012);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    public void testSort() {

        try {
            List<MetroStop> L = p.parse("/home/jalil/Documents/ZZ3/isima-poa-2023-TP3-ZOGHLAMI/src/isima/data/ratp_arret.csv");
            Parser.sortById(L);
            int lastId = L.get(0).id;
            for(MetroStop ms : L)
            {
                assertTrue(lastId <= ms.id);
                lastId = ms.id;
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }


}
