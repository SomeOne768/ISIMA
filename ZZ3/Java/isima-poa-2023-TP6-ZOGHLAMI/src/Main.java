import java.lang.reflect.Method;

public class Main {

    public static void main(String[] args)
    {
        // 1
        Personne p = new Personne();
        System.out.println("Start:\n" + p);
//        ExplorerClass ec = new ExplorerClass(p);
//
//        System.out.println(ec.getClassName());
//        System.out.println(ec.getAttributeName());

        // 2
        System.out.println("\nExploration:");
        ExplorerClass.explore(Personne.class);

        // 3
        System.out.println("\nManipulation:");
        ManipulationClass.manipulate2(p);
        System.out.println(p);

        // 4
        System.out.println("\nAfficherDetails:");
        Class<?> c = p.getClass();
        Class<?>[] interfaces = c.getInterfaces();
        for (Class<?> inter : interfaces) {
            if (inter.getSimpleName().equals("Affichable")) {
                try {
                    Method afficherDetailsMethod = inter.getDeclaredMethod("afficherDetails");
                    afficherDetailsMethod.setAccessible(true);
                    afficherDetailsMethod.invoke(p);
                } catch (NoSuchMethodException e) {
                    System.out.println("afficherDetails not implemented");
                } catch (Exception e) {
                    e.printStackTrace();
                }
            }
        }
    }
}
