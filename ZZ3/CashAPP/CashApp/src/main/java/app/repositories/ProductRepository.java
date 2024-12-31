package app.repositories;

import org.springframework.data.repository.CrudRepository;
import app.entities.Product;
import java.util.Optional;

public interface ProductRepository extends CrudRepository<Product, Long> {
    public Optional<Product> findByName(String nameToFind);
}