package app.repositories;

import java.util.List;

import org.springframework.data.repository.CrudRepository;
import app.entities.OrderEntity;

public interface OrderEntityRepository extends CrudRepository<OrderEntity, Long> {
    public List<OrderEntity> findByClientId(Long clientId);
}