package app.entities;

import jakarta.persistence.Column;
import jakarta.persistence.Entity;
import jakarta.persistence.Table;
import jakarta.persistence.ManyToOne;
import jakarta.persistence.JoinColumn;
import jakarta.persistence.GeneratedValue;
import jakarta.persistence.GenerationType;
import jakarta.persistence.Id;

@Entity
@Table(name="orderItems")
public class OrderItem {

    @Id
    @GeneratedValue(strategy=GenerationType.IDENTITY)
    @Column(name="orderItem_id")
    private Long orderItemId;

    @ManyToOne
    @JoinColumn(name="order_id")
    private OrderEntity order_;

    @Column(name="productName")
    private String productName;

    @Column(name="quantity")
    private int quantity;

    @Column(name = "product_id")
    private Long productId;

    @Column(name="unit_price")
    private double unit_price;

    protected OrderItem() {}

    public OrderItem(OrderEntity order, String productName, int quantity, double unit_price) {
        this.order_ = order;
        this.productName = productName;
        this.quantity = quantity;
        this.unit_price = unit_price;
    }

    public OrderEntity getOrder() {
        return order_;
    }

    public void setOrder(OrderEntity orderToSet) {
        this.order_ = orderToSet;
    }

    public String getProductName() {
        return productName;
    }

    public void setProductName(String productName) {
        this.productName = productName;
    }

    public int getQuantity() {
        return quantity;
    }

    public void setQuantity(int quantityToSet) {
        this.quantity = quantityToSet;
    }

    public double getUnitPrice() {
        return unit_price;
    }

    public void setUnitPrice(double UnitPriceToSet) {
        this.unit_price = UnitPriceToSet;
    }

    public Long getProductId() {
        return productId;
    }

    public void setProductId(Long productId) {
        this.productId = productId;
    }

}