public class PereNoel {
    private static int count = 1;
    public final int serialNumber;

    @Override
    public String toString() {
        return "PereNoel{" +
                "serialNumber=" + serialNumber +
                '}';
    }

    public PereNoel() {
        this.serialNumber = count++;
    }
}
