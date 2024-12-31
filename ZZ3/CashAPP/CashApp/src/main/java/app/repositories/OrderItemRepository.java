package app.repositories;

import org.springframework.data.repository.CrudRepository;

import app.entities.OrderItem;


public interface OrderItemRepository extends CrudRepository<OrderItem, Long> {
}