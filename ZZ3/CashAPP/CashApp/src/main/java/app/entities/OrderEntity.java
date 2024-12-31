package app.entities;

import java.io.Serializable;
import java.util.*;

import jakarta.persistence.*;


@Entity
@Table(name="orders")
public class OrderEntity implements Serializable {

    @Id
    @GeneratedValue(strategy=GenerationType.IDENTITY)
    @Column(name="order_id")
    private Long orderId;

    @Column(name="client_id")
    private Long clientId;

    @Column(name="purchase_date")
    private Date purchaseDate;

    @Column(name="total")
    private double total;

    @Column(name="payment_method")
    private String paymentMethod;

    @OneToMany(mappedBy = "order_", cascade = CascadeType.ALL)
    private List<OrderItem> orderItems;

    public List<OrderItem> getItems()
    {
        return orderItems;
    }

    public void setItems(List<OrderItem> items)
    {
        this.orderItems = items;
    }

    public void addItems(OrderItem item)
    {
        if(this.orderItems == null)
            this.orderItems = new ArrayList<>();
        this.orderItems.add(item);
    }

    public OrderEntity(Long clientId, Date purchaseDate, double total, String paymentMethod) {
        this.clientId = clientId;
        this.purchaseDate = purchaseDate;
        this.total = total;
        this.paymentMethod = paymentMethod;
    }

    public OrderEntity() {}

    public Long getOrderId() {
        return orderId;
    }

    public void setOrderId(Long orderId) {
        this.orderId = orderId;
    }

    public Long getClientId() {
        return clientId;
    }

    public void setClientId(Long clientId) {
        this.clientId = clientId;
    }

    public Date getPurchaseDate() {
        return purchaseDate;
    }

    public void setPurchaseDate(Date purchaseDate) {
        this.purchaseDate = purchaseDate;
    }

    public double getTotal() {
        return total;
    }

    public void setTotal(double total) {
        this.total = total;
    }

    public String getPaymentMethod() {
        return paymentMethod;
    }

    public void setPaymentMethod(String paymentMethod) {
        this.paymentMethod = paymentMethod;
    }
}