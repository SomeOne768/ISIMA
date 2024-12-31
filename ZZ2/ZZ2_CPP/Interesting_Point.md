

# Fonctiun with same comportment but with different Type:

When we have the same comportment for differents classes (like rectangle and cercle which inherit from Forme) we can use the following expression:

    - **Here we use a transtype and get parameters by reference**
```
template <typename FormeType>
void Groupe::add(FormeType & forme, int & nb) {

}
```

    - **Here we use the lambda expression which will automatically detect the type because of using reference **
```
void Groupe::addEncore(Forme & f) {
    auto addForme = [](auto & maForme, int & nb){

    };
}
``` 