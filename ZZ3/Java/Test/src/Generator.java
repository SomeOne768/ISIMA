import java.util.Collection;
import java.util.Random;

public class Generator extends Thread{

    private final Collection<Integer> L;
    private final int min;
    private final int max;
    private final int n;

    public Generator(Collection<Integer> l, int min, int max, int n) {
        L = l;
        this.min = min;
        this.max = max;
        this.n = n;
    }
    public void run()
    {
        Random r = new Random();

        while(true)
        {
            int randomInt = r.nextInt(max-min) + min;
            synchronized (L)
            {
                if(L.size() < n)
                    L.add(randomInt);
                else
                    break;
            }
        }
    }
}
