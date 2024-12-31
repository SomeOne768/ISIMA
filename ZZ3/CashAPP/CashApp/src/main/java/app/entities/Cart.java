package app.entities;

import java.util.*;


import jakarta.persistence.Column;
import jakarta.persistence.GeneratedValue;
import jakarta.persistence.GenerationType;
import jakarta.persistence.Id;
import jakarta.persistence.OneToMany;
import jakarta.persistence.Table;
import jakarta.persistence.Entity;
import jakarta.persistence.CascadeType;

@Entity
@Table(name = "carts")
public class Cart {

    @Id
    @GeneratedValue(strategy = GenerationType.IDENTITY)
    @Column(name = "cart_id")
    private Long cartId;

    @OneToMany(mappedBy = "cart", cascade = CascadeType.ALL)
    private List<CartItem> cartItems;


    public List<CartItem> getItems() {
        return cartItems;
    }

    public void setItems(List<CartItem> items) {
        this.cartItems = items;
    }

    public void addItems(CartItem items) {
        if(this.cartItems == null)
            this.cartItems = new ArrayList<CartItem>();
        this.cartItems.add(items);
    }

    public void removeItems(CartItem items) {
        this.cartItems.remove(items);
    }

    public void clearList()
    {
        this.cartItems.clear();
    }

}
