# Audit de Sécurité

## Analyse

### Confidential - Do not save sensitive information
La clé API est stockée dans la classe main, en dure. 
```java
public class Main {
    private static String apiKey = "74b0194008b56de27687486cd366d4c0";
    private static CityRepository cityRepo;
}
```
Il est préférable de conservé un fichier à part, secret, et de l'importer par la suite pour l'utiliser.

<u>Solution proposée :</u>
Créer une classe Credential dans laquelle on stocke la clé API et que l'on appellera par la suite. Cette classe est
finale et doit soit être ignorée par git soit être envoyée et la clé sera donné oralement/d'une autre manière.
```java
public final class Credential {
    public final static String apiKey = "YourApiKey";
}
```

et dans le main:
```java
private static String apiKey = Credential.apiKey;
```


### Extends - Limit the extensibility of classes and methods

Beaucoup de classe sont utilisées pour les données, aucun héritage n'est possible, envisageable. Nous les mettons en
final.

```java
public final class City
public final class Coord
public final class Infos
public final class CityRepository implements CrudRepository<City>
```

### Injection SQL - Requêtes préparées mais pas suffisamment protégées

Les requêtes sont préparées et  s'assure du bon type de chaque valeur. Cependant, le nom de la ville est récupéré
par une saisie de l'utilisateur et cette dernière n'est pas vérifiée. Cela nous rend vulnérable à une injection sql.

Récupération d'une saisie dans le main
```java
String cityName = scanner.nextLine();
City city = cityRepo.getCity(cityName);
```

Définition de la méthode pour récupérer une ville
```java
public City getCity(String cityName) {
        City city = null;

        try (PreparedStatement preparedStatement = connection.prepareStatement(
                "SELECT * FROM weather_data WHERE city_name LIKE ?;"
        )) {
            // Récupérer "Arrondissement de Lyon" avec "Lyon"
            preparedStatement.setString(1, "%" + cityName + "%");
          ...
```

Récupération du nom de la ville via l'utilisateur:
```java 
System.out.print("Veuillez entrer un nom de ville : ");
String cityName  = scanner.nextLine();
City city = cityRepo.getCity(cityName);
```


<u>Solution proposée :</u>
Il semblerait, comme indiqué [ici](https://stackoverflow.com/questions/47040521/how-to-detect-sql-injection-in-java), que
les PreparedStatement suffisent à se prévenir des SQLI mais pour cela il faut faire attention à son utilisation et 
notamment ici à l'utilisation du LIKE avec les '%'.

```java
cityName = cityName
        .replace("!", "!!")
        .replace("%", "!%")
        .replace("_", "!_")
        .replace("[", "![");
```

### Guideline 1-2 / DOS-2: Release resources in all cases

La connexion à la base de donnée n'est jamais fermée.
Il est conseillé d'ouvrir et de fermer la connexion après chaque requête pour minimiser la durée pendant laquelle la
connexion est active et ainsi éviter les fuites de connexions et les problèmes de performance associés.
Le code est plus robuste et réduit les risques de saturation des ressources système, ce qui contribue à prévenir les 
éventuelles attaques de type DOS qui pourraient être exploitées en utilisant des ressources de manière excessive ou en 
les bloquant.

```java
    private Connection connection;

    public CityRepository(String config){
        initConnection(config);
    }
```

<u>Solution proposée :</u>
Ouvrir, tester et refermer la connexion pour chaque utilisation.
Avec l'actuelle implémentation:
```java
initConnection(...);
if(connection != null)
    // Actions à réaliser

    connection.close();

// On peut envoyer une erreur si null
```


### DOS  ?

Lors de la construction d'un objet CityRepository, la méthode initConnection vérifie bien s'il y a une erreur lors de
la création, cependant dans le cas où une erreur est attrapée un simple message d'erreur s'affiche sans pour autant
gérer le cas ou lancer une nouvelle erreur. Cela produit une erreur qui par la suite stop le programme à cause d'une valeur 
null. À noter que la méthode **initConnection** ne retourne rien, il serait préférable de retourner une connection pour 
pouvoir ensuite tester si la valeur est nulle.

```java
public CityRepository(String config){
        initConnection(config);
    }
```

```java
private void initConnection(String config){
        // Create a table if it doesn't exist
        try{
          connection=DriverManager.getConnection(Objects.equals(config,"test")?"jdbc:sqlite:weatherTest.db":"jdbc:sqlite:weather.db");
          Statement statement=connection.createStatement();
          statement.execute(
            "CREATE TABLE IF NOT EXISTS weather_data ("+
            "id INTEGER PRIMARY KEY AUTOINCREMENT,"+
            "city_name TEXT,"+
            "temperature REAL(4),"+
            "max_temperature REAL(4),"+
            "min_temperature REAL(4),"+
            "humidity REAL(4),"+
            "last_updated TIMESTAMP"+  // Utiliser TIMESTAMP à la place de DATE
            ");"
          );
        }
        catch(SQLException e){
          System.out.println("Erreur lors de la connexion à la base de données : "+e.getMessage());
        }
        
        // /!\/!\/!\ ICI connection peut être nulle /!\/!\/!\
}
```

<u>Solution proposée :</u>
S'il y a echec lorsqu'on initialise une connexion, il est préférable de renvoyer une erreur puis d'arrêter le programme
ou, dans notre cas puisque l'on peut récupérer des informations hors de la BDD de faire une requête sur le serveur 
distant.

Dans le main:
```java
try
{
    initConnection();
    ...
}catch(Exception e)
{
    // Traitement
    ...
    appelle requête
}
```

### Guideline 6-1 / MUTABLE-1: Prefer immutability for value types

La classe City est toujours utilisé comme objet immuable. Certains attributs renseignés à la construction devraient être
constant, final.

```java
private String name;
```
Devient:
```java
private final String name;
```