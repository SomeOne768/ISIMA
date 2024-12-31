public class Produit {
    public int elt1;
    public int elt2;
    public int elt3;

    public Produit(int elt1, int elt2, int elt3) {
        this.elt1 = elt1;
        this.elt2 = elt2;
        this.elt3 = elt3;
    }


    @Override
    public String toString() {
        return "Produit{" +
                "elt1=" + elt1 +
                ", elt2=" + elt2 +
                ", elt3=" + elt3 +
                '}';
    }
}
