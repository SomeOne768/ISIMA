package weather;

import java.util.List;

public interface CrudRepository<T> {
    T getCity(String cityName);
    List<T> getAll(String sortedParam);
    void create(T t);
    void update(T t);
    void delete(String cityName);
}
