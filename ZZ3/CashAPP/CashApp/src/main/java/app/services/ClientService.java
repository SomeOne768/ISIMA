package app.services;

import java.util.Optional;

import org.springframework.beans.factory.annotation.Autowired;
import app.entities.*;
import app.repositories.ClientRepository;
import org.springframework.stereotype.Service;

@Service
public class ClientService {
    
    @Autowired 
    private ClientRepository clientRepository;

    public void insertClient(Client client){
        clientRepository.save(client);
    }

    public Optional<Client> findByFirstname(String nameToFind){
        return clientRepository.findByFirstname(nameToFind);
    }

}