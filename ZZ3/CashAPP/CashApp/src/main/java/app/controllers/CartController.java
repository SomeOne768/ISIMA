package app.controllers;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.*;
import org.springframework.ui.Model;
import org.springframework.http.HttpStatus;
import org.springframework.http.ResponseEntity;
import app.repositories.ProductRepository;
import app.services.CartService;
import java.util.*;
import app.entities.*;

@Controller
public class CartController {

    @Autowired
    CartService cartService;

    @Autowired
    ProductRepository productRepository;

    @GetMapping(path = { "/cart" })
    public String index(Model model) {
        model.addAttribute("cart", cartService.getCart());
        return "cart/index";
    }

    @PostMapping("/cart/add/{id}")
    public ResponseEntity<String> add(@PathVariable("id") Long id, @RequestParam("quantity") int quantity) {
        Cart cart = cartService.getCart();
        Optional<Product> product = productRepository.findById(id);
        if (!product.isPresent() || quantity < 1) {
            return ResponseEntity.status(HttpStatus.NOT_FOUND).body("Product not found.");
        } else {
            cartService.addToCart(cart, product.get(), quantity);
            return ResponseEntity.ok("Product added to cart successfully.");
        }
    }

    @GetMapping("/cart/paye")
    public String paye()
    {
        Cart cart = cartService.getCart();
        cartService.paye(cart);

        return "redirect:/cart";
    }

}
