import java.lang.reflect.Field;
import java.lang.reflect.InvocationTargetException;
import java.lang.reflect.Method;
import java.util.ArrayList;

public class ManipulationClass {

    public static void manipulate(String className) {
        try {
            Class<?> c = Class.forName(className);
            // ExplorerClass.explore(c);
            Field[] fields = c.getDeclaredFields();
            ArrayList<String> attributesNames = new ArrayList<>();
            ArrayList<String> attributesTypes = new ArrayList<>();

            for (Field f : fields) {
                attributesNames.add(f.getName());
                attributesTypes.add(Util.cleanType(String.valueOf(f.getType())));
            }

            System.out.println(attributesNames);
            System.out.println(attributesTypes);

            for (int i = 0; i < fields.length; i++) {

                try {
                    if (attributesTypes.get(i).equals("int")) {
                        fields[i].setInt(c, fields[i].getInt(c) + 1);
                    } else if (attributesTypes.get(i).equals("float")) {
                        fields[i].setFloat(c, fields[i].getFloat(c) + 1);
                    } else if (fields[i].getType().isAssignableFrom(String.class)) {
                        // fields[i].get(c);
                        // s2 += "_XXXX";
                        // System.out.println(s2);
                        // fields[i].set(c, s2);
                    }
                } catch (IllegalAccessException e) {

                }
            }
            ExplorerClass.explore(c);

            // Methods manipulation
            System.out.println("Methodes:");
            Method[] methods = c.getMethods();

            ArrayList<Integer> getter = new ArrayList<>();
            ArrayList<Integer> setter = new ArrayList<>();

            for(int i=0; i<methods.length; i++) {
                if(methods[i].toString().contains("get"))
                    getter.add(i);
                else if(methods[i].toString().contains("set"))
                    setter.add(i);
            }

            for(int set : setter)
            {
                System.out.println(methods[set].toString());
                methods[set].invoke(c, "UPDATED");
            }
        } catch (Exception e) {
            e.printStackTrace();
        }

    }

    public static void manipulate2(Personne p)
    {
        Class<?> c = p.getClass();

        try {
            // Attributes
            Field   ageField = c.getDeclaredField("age"),
                    nameField = c.getDeclaredField("name"),
                    firstNameField = c.getDeclaredField("firstname"),
                    addressField = c.getDeclaredField("address");

            ageField.setAccessible(true);
            ageField.setInt(p, 30);

            nameField.set(p, "NAME");
            firstNameField.set(p, "FIRSTNAME");
            addressField.set(p, "XXXXX");

            // Methods
            // Setter
            Method setAgeMethod = c.getDeclaredMethod("setAge", int.class);
            Method setNameMethod = c.getDeclaredMethod("setName", String.class);
            Method setFirstnameMethod = c.getDeclaredMethod("setFirstname", String.class);
            Method setAddressMethod = c.getDeclaredMethod("setAddress", String.class);

            // Getter
            Method getNameMethod = c.getDeclaredMethod("getName");
            Method getFirstnameMethod = c.getDeclaredMethod("getFirstname");
            Method getAddressMethod = c.getDeclaredMethod("getAddress");
            Method getAgeMethod = c.getDeclaredMethod("getAge");

            // Modifying with setters
            setNameMethod.invoke(p, "MYNAME");
            setFirstnameMethod.invoke(p, "PRENOM");
            setAddressMethod.invoke(p, "XXXXXXXXXX");
            setAgeMethod.setAccessible(true);
            setAgeMethod.invoke(p, 15);

            // Trying to use getter
            getAgeMethod.invoke(p);
            getAddressMethod.invoke(p);
            getFirstnameMethod.invoke(p);
            getNameMethod.invoke(p);

        } catch (NoSuchFieldException | IllegalAccessException | NoSuchMethodException | InvocationTargetException e) {
            e.printStackTrace();
        }

    }


}
