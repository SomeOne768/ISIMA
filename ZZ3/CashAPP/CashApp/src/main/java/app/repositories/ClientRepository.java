package app.repositories;
import java.util.Optional;

import org.springframework.data.repository.CrudRepository;
import app.entities.Client;


public interface ClientRepository extends CrudRepository<Client, Long> {
    public Optional<Client> findByFirstname(String nameToFind);
}