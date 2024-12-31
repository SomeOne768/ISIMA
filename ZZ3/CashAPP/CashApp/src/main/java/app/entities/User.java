package app.entities;

import java.io.Serializable;
import java.util.Collection;
import org.springframework.security.core.userdetails.UserDetails;
import org.springframework.security.core.GrantedAuthority;
import jakarta.persistence.Entity;
import jakarta.persistence.GeneratedValue;
import jakarta.persistence.Id;
import jakarta.persistence.JoinColumn;
import jakarta.persistence.OneToOne;
import jakarta.persistence.Column;
import jakarta.persistence.Table;
import jakarta.persistence.GenerationType;
import org.springframework.security.crypto.bcrypt.BCryptPasswordEncoder;

@Entity
@Table(name="users") 
public class User implements Serializable, UserDetails {
 
    @Id
    @GeneratedValue(strategy = GenerationType.IDENTITY)
    private Long id;
 
    @Column(nullable = false, unique = true)
    private String username;
    @Column(nullable = false, unique = false)
    private String password;

    @OneToOne
    @JoinColumn(name="client_id")
    private Client client;
    
    public void setClient(Client client)
    {
        this.client = client;
    }

    public Client getClient()
    {
        return this.client;
    }

    public User(){}
    public User(String username, String password) {
        this.username = username;
        this.setPassword(password);
    }
      
    public String getUsername() 
    {
        return username;
    }

    public String getPassword() 
    {
        return password;
    }

    public void setUsername(String username) 
    {
        this.username = username;
    }

    public void setPassword(String password) 
    {
        String mdpe = new BCryptPasswordEncoder().encode(password);
        this.password = "{bcrypt}"+mdpe;
    }

    public boolean isEnabled() { return true; }

    public boolean isCredentialsNonExpired() { return true; }

    public boolean isAccountNonLocked() { return true; }

    public boolean isAccountNonExpired() { return true; }

    public Collection< ? extends GrantedAuthority> getAuthorities() { return null; }

}
