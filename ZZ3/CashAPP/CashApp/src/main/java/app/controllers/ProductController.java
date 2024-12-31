package app.controllers;

import java.util.*;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.http.HttpStatus;
import org.springframework.http.ResponseEntity;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PathVariable;

import app.entities.Product;
import app.repositories.ProductRepository;
import app.services.ProductService;
import app.services.ClientService;
import app.services.MyUserDetailsService;

@Controller
public class ProductController {

	@Autowired
	private ProductRepository productRepository;

	@GetMapping("/product/{id}")
	public ResponseEntity<?> get(@PathVariable Long id) {
		Optional<Product> product = productRepository.findById(id);

        if (product.isPresent()) {
            return ResponseEntity.ok(product.get());
        } else {
            return ResponseEntity.status(HttpStatus.NOT_FOUND).body("Product not found");
        }
    }
}
