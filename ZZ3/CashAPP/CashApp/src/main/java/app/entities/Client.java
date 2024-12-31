package app.entities;

import java.util.Date;

import jakarta.persistence.Column;
import jakarta.persistence.GeneratedValue;
import jakarta.persistence.GenerationType;
import jakarta.persistence.Id;
import jakarta.persistence.JoinColumn;
import jakarta.persistence.OneToOne;
import jakarta.persistence.Table;
import jakarta.persistence.Entity;

@Entity
@Table(name="clients")
public class Client{

    @Id
    @GeneratedValue(strategy=GenerationType.IDENTITY)
    @Column(name="client_id")
    private Long clientId;

    @Column(name="firstname")
    private String firstname;

    @Column(name="lastname")
    private String lastname;

    @Column(name="birthdate")
    private Date birthdate;

    @Column(name="postcode")
    private int postcode;

    @OneToOne
    @JoinColumn(name="cart_id")
    private Cart cart;
    
    public void setCart(Cart cart)
    {
        this.cart = cart;
    }

    public Cart getCart()
    {
        return this.cart;
    }

    public Client()
    {

    }
    
    public Client(String firstname, String lastname, Date birthdate, int postcode) {
        this.firstname = firstname;
        this.lastname = lastname;
        this.birthdate = birthdate;
        this.postcode = postcode;
    }
    
    public Long getClientId() {
        return clientId;
    }

    public void setClientId(Long clientId) {
        this.clientId = clientId;
    }

    public String getFirstname() {
        return firstname;
    }

    public void setFirstname(String firstname) {
        this.firstname = firstname;
    }

    public String getLastname() {
        return lastname;
    }

    public void setLastname(String lastname) {
        this.lastname = lastname;
    }

    public Date getBirthdate() {
        return birthdate;
    }

    public void setBirthdate(Date birthdate) {
        this.birthdate = birthdate;
    }

    public int getPostcode() {
        return postcode;
    }

    public void setPostcode(int postcode) {
        this.postcode = postcode;
    }
}
