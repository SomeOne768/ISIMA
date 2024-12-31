package app.repositories;

import org.springframework.data.repository.CrudRepository;

import app.entities.CartItem;


public interface CartItemRepository extends CrudRepository<CartItem, Long> {
}