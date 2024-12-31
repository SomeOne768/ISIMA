import isima.MetroStop;
import isima.Parser;
import junit.framework.TestCase;

public class TestMetroStop extends TestCase {
    private MetroStop metroStop;

    @Override
    protected void setUp () throws Exception {
        super . setUp ();
        metroStop = MetroStop.MetroSample();
    }

    @Override
    protected void tearDown () throws Exception {
        super . tearDown ();
        metroStop = null ;
    }
    public void testTrue()
    {
        assertTrue(true);
        // fail();
    }

    public void testMetroSample()
    {
        assertEquals(metroStop.id, 1);
        assertEquals(metroStop.longitude, 49.3);
        assertEquals(metroStop.latitude, 58.5);
        assertEquals(metroStop.nom, "Borne");
        assertEquals(metroStop.arrondissement, "PARIS-4EME");
        assertEquals(metroStop.type, "Virus");
    }

    public void testToString()
    {
        assertEquals(metroStop.toString(),
            "MetroStop{id=1, longitude=49.3, latitude=58.5, nom='Borne', arrondissement='PARIS-4EME', type='Virus'}"
        );
    }
}
