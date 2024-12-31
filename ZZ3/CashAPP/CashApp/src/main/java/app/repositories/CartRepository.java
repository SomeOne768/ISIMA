package app.repositories;

import org.springframework.data.repository.CrudRepository;

import app.entities.Cart;


public interface CartRepository extends CrudRepository<Cart, Long> {
}