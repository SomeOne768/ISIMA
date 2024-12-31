package app.controllers;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.bind.annotation.ResponseBody;
import org.springframework.web.multipart.MultipartFile;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.ModelAttribute;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.PathVariable;

import app.repositories.ProductRepository;
import app.services.MyUserDetailsService;
import app.entities.Product;

import java.io.IOException;
import java.util.*;

@Controller
public class ShopController {

    @Autowired
    private ProductRepository productRepository;
    
    @Autowired
    private MyUserDetailsService userService;

   

    // Permet de voir tous les produits disponible à l'achat
    @GetMapping(path = { "/shop" })
    public String index(Model model) {

        model.addAttribute("products", productRepository.findAll());
        return "shop";
    }


    // Voir les détails d'un produit
    @GetMapping(path = { "/shop/{id}" })
    public String findProduct(@PathVariable Long id, Model model) {
        Optional<Product> productOptional = productRepository.findById(id);

        if (!productOptional.isPresent())
            return "redirect:/shop";

        model.addAttribute("product", productOptional.get());
        return "product/index";
    }

    // Editer un produit
    @GetMapping(path = { "/shop/edit/{id}" })
    public String editProduct(@PathVariable Long id, Model model) {
        // Seul l'admin y a accès
        if (!userService.isAdmin())
            return "redirect:/shop";

        Optional<Product> productOptional = productRepository.findById(id);

        if (!productOptional.isPresent())
            return "shop";

        model.addAttribute("product", productOptional.get());
        return "product/edit";
    }

    // Enregistrer les modif d'un produit
    @PostMapping("/shop/edit/{id}")
    public String updateProduct(@PathVariable("id") Long productId, @RequestParam String name,
            @RequestParam String brand, @RequestParam Double price,
            @RequestParam int quantity) {

        // Seul l'admin y a accès
        if (!userService.isAdmin())
            return "redirect:/shop";

        Optional<Product> productOptional = productRepository.findById(productId);
        if (!productOptional.isPresent())
            return "redirect:/shop";

        Product product = productOptional.get();
        product.setName(name);
        product.setBrand(brand);
        product.setPrice(price);
        product.setQuantity(quantity);

        productRepository.save(product);

        return "redirect:/shop";
    }

    // Page pour créer un produit
    @GetMapping(path = { "/shop/new" })
    public String createProduct(Model model) {
        // Seul l'admin y a accès
        if(!userService.isAdmin())
            return "redirect:/shop";

        model.addAttribute("product", new Product());
        return "product/new";
    }

    // Route pour enregistrer le produit créer avec son image associée
    @PostMapping("/shop/new")
    public String create(@ModelAttribute Product product, @RequestParam("imageF") MultipartFile file) {
        // Seul l'admin y a accès
        if(!userService.isAdmin())
            return "redirect:/shop";

        if (!file.isEmpty()) {
            try {
                
                byte[] bytes = file.getBytes();
                product.setImage(Base64.getEncoder().encodeToString(bytes));
            } catch (IOException e) {
                e.printStackTrace();
            }
        }

        productRepository.save(product);
        return "redirect:/shop";
    }

}
