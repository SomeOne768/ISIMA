public class Personne implements Affichable {

    private int age;
    protected String name;
    protected String firstname;
    public String address;

    public String getName() {
        return name;
    }

    public String getFirstname() {
        return firstname;
    }

    public String getAddress() {
        return address;
    }

    public int getAge()
    {
        return age;
    }

    private void setAge(int x)
    {
        if(x>0)
            age = x;
    }

    protected void setName(String name)
    {
        this.name = name;
    }

    public void setFirstname(String firstname) {
        this.firstname = firstname;
    }

    public void setAddress(String address) {
        this.address = address;
    }

    @Override
    public String toString() {
        return "Personne{" +
                "age=" + age +
                ", name='" + name + '\'' +
                ", firstname='" + firstname + '\'' +
                ", address='" + address + '\'' +
                '}';
    }

    public void afficherDetails()
    {
        System.out.println("Implementation done");
    }
}
