package app.services;

import java.util.*;
import org.springframework.beans.factory.annotation.Autowired;
import app.entities.*;
import org.springframework.stereotype.Service;
import app.repositories.OrderEntityRepository;
import app.repositories.ProductRepository;
import jakarta.persistence.EntityManager;
import jakarta.persistence.PersistenceContext;

import org.springframework.transaction.annotation.Transactional;

@Service
public class OrderService {
    
    @PersistenceContext
    EntityManager entityManager;

    @Autowired 
    private OrderEntityRepository orderEntityRepository;

    @Autowired
    private ProductRepository productRepository;

    public void insertOrder(OrderEntity order){
        orderEntityRepository.save(order);
    }

    public List<OrderEntity> findOrdersByClientID(Long clientID) {
        return orderEntityRepository.findByClientId(clientID);
    }


    @Transactional
    public void removeProduct(Long OrderId, Long productId, int quantity) {
        Optional<Product> product = productRepository.findById(productId);
        Optional<OrderEntity> order = orderEntityRepository.findById(OrderId);
        if (product.isPresent() && order.isPresent()) {
            for (OrderItem item : order.get().getItems()) {
                if (item.getProductId() == productId) {
                    quantity = (item.getQuantity() < quantity) ? item.getQuantity() : quantity;

                    product.get().setQuantity(item.getQuantity() - quantity);
                    item.setQuantity(item.getQuantity() - quantity);

                    entityManager.persist(item);
                    entityManager.persist(product);
                    entityManager.flush();

                    return;
                    // if(item.getQuantity() == 0)
                    // {
                    //     entityManager.remove(item);
                    // }
                }
            }
        }
    }

}

