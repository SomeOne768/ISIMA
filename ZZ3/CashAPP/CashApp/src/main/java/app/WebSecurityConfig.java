package app;

import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;
import org.springframework.security.config.annotation.web.builders.HttpSecurity;
import org.springframework.security.config.annotation.web.configuration.EnableWebSecurity;
import org.springframework.security.config.annotation.web.configurers.AbstractHttpConfigurer;
import org.springframework.security.web.SecurityFilterChain;


@Configuration
@EnableWebSecurity
public class WebSecurityConfig {

    @Bean
    public SecurityFilterChain securityFilterChain(HttpSecurity http) throws Exception {
        http
            .authorizeHttpRequests((requests) -> requests
                .requestMatchers("/login").permitAll() // Ici ajouter les routes avec connexion non nécéssaire
                .anyRequest().authenticated()
            )
            .formLogin((form) -> form
            //	.loginPage("/login") // If we want a custom login page
                .permitAll()
            ) 
            .logout((logout) -> logout.permitAll())
            .cors(cors -> cors.disable())
            .csrf(AbstractHttpConfigurer::disable);

        return http.build();
    } 
    
    // Si vous décommentez ce code, l'utilisateur qui peut se connecter est celui qui est spécifié
    // cela désactive l'utilisateur du fichier properties
    // ne pas décommenter pour utiliser une base
    /*@Bean
    public UserDetailsService userDetailsService() {
        UserDetails user =
             User.withDefaultPasswordEncoder()
                .username("user")
                .password("password")
                .roles("USER")
                .build();

        return new InMemoryUserDetailsManager(user);
    }*/
    
}

