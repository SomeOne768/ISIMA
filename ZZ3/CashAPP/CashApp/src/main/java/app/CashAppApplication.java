package app;

import app.entities.*;
import app.repositories.*;

import java.io.IOException;
import java.util.Arrays;
import java.util.List;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.CommandLineRunner;
import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.context.annotation.ComponentScan;
import org.springframework.jdbc.core.JdbcTemplate;
import org.springframework.web.servlet.config.annotation.CorsRegistry;
import org.springframework.context.annotation.Bean;
import org.springframework.web.servlet.config.annotation.WebMvcConfigurer;

import java.nio.file.*;
import java.nio.*;
import java.util.Base64;

@ComponentScan
@SpringBootApplication
public class CashAppApplication implements CommandLineRunner {

    @Bean
    public WebMvcConfigurer corsConfigurer(){
        return new WebMvcConfigurer(){
            @Override
            public void addCorsMappings(CorsRegistry registry){
                registry.addMapping("/**")
                        .allowedOrigins("http://localcost:8080")
                        .allowedMethods("GET", "POST", "PUT", "DELETE");
            }
        };
    }

    private static final Logger log = LoggerFactory.getLogger(
            CashAppApplication.class);

    @Autowired
    JdbcTemplate jdbcTemplate;

    @Autowired
    private ProductRepository productRepository;

    @Autowired
    private ClientRepository clientRepository;

    @Autowired
    private OrderEntityRepository orderRepository;

    @Autowired
    private UserRepository userRepository;

    @Autowired
    private CartRepository cartRepository;

    public static void main(String[] args) {
        SpringApplication.run(CashAppApplication.class, args);
    }

    @Override
    public void run(String... strings) throws Exception {
        List<String> list = Arrays.asList(strings);

        if (list.contains("install")) {
            productRepository.save(new Product("Chemise", loadImageFromFile("/chemise.jpeg"), "Abidas", 10.32, 40));
            productRepository.save(new Product("fraise", loadImageFromFile("/fraise.jpeg"), "FiTounis", 4.14, 73));
            productRepository.save(new Product("pantalon", loadImageFromFile("/pantalon.jpeg"), "Celio", 15.65, 2));
            productRepository.save(new Product("pomme", loadImageFromFile("/pomme.jpeg"), "Golden", 1.32, 91));

            User u1 = new User("admin", "admin");
            User u2 = new User("user", "user");
            Client c1 = new Client("admin", "admin", null, 63000);
            Client c2 = new Client("user", "user", null, 01000);
            u1.setClient(c1);
            u2.setClient(c2);

            Cart cart1 = new Cart();
            Cart cart2 = new Cart();
            c1.setCart(cart1);
            c2.setCart(cart2);

            cartRepository.save(cart1);
            cartRepository.save(cart2);

            clientRepository.save(c1);
            clientRepository.save(c2);

            userRepository.save(u1);
            userRepository.save(u2);
        }
    }

    private static String loadImageFromFile(String imageName) {
        try {
            // Chemin relatif à partir du répertoire src/main/resources/static/images
            Path path = Paths.get("src", "main", "resources", "static", "images", imageName);
            return Base64.getEncoder().encodeToString(Files.readAllBytes(path));
        } catch (IOException e) {
            System.err.println("Failed to load image from file: " + e.getMessage());
            return null;
        }
    }

}
