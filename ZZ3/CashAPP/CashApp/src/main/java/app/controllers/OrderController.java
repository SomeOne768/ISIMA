package app.controllers;

import java.util.*;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.http.HttpStatus;
import org.springframework.http.ResponseEntity;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.bind.annotation.ResponseBody;
import org.springframework.web.bind.annotation.*;
import org.springframework.ui.Model;

import app.entities.*;
import app.repositories.*;
import app.services.*;


@Controller
public class OrderController {

    @Autowired
    private OrderService orderService;

    @Autowired
    private MyUserDetailsService userDetailService;

    @Autowired
    private ProductRepository productRepository;

    @Autowired
    private ProductService productService;

    @Autowired
    private ClientService clientService;

    @GetMapping("/orders")
    public String getOrders(Model model) {
        Client client = userDetailService.getLoggedClient();
        List<OrderEntity> orders = orderService.findOrdersByClientID(client.getClientId());
        model.addAttribute("orders", orders);
        return "orders";
    }


    // Afficher le formulaire de retour de produit
    @GetMapping("/product/return")
    public String showReturnForm() {
        return "/product/return";
    }



    @PostMapping("/order/{id}/return")
    public String removefromOrder(@PathVariable("id") Long id, @RequestParam("productId") Long id2, @RequestParam("quantity") int quantity) {
 
        productService.returnProduct(id2, quantity);
        orderService.removeProduct(id, id2, quantity);

        return "redirect:/cart";
    }

}
