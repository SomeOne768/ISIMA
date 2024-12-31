import java.lang.reflect.Field;
import java.lang.reflect.Method;
import java.util.Objects;

public class ExplorerClass<T> {

    public T elt;

    ExplorerClass(T elt)
    {
        this.elt = elt;
    }

    public String getClassName()
    {
        Class<?> c = elt.getClass();
        return "Class name: " + c.getName();
    }

    public String getAttributeName()
    {
        Field[] fields = elt.getClass().getDeclaredFields();
        StringBuilder s = new StringBuilder();
        for(Field elt: fields)
            s.append(elt.getName()).append(" ");

        return s.toString();
    }

    public static void explore(Class<?> c)
    {
        String className = c.getName();
        StringBuilder attributesNames = new StringBuilder();
        StringBuilder methodsNames = new StringBuilder();

        for(Field f :c.getDeclaredFields()) {
            String[] s = f.toString().split(" ");
            for(String elt:s) {
                elt = Util.cleanType(elt);
                attributesNames.append(elt).append(" ");
            }
        }

        for(Method f: c.getDeclaredMethods())
        {
            methodsNames.append(methodSpecialClean(f.toString())).append("| ");
        }

        System.out.println("className: " + className + "\n"+
                "Attributes: " + attributesNames + "\n" +
                "Methods: " + methodsNames);
    }

    private static String methodSpecialClean(String s)
    {
        StringBuilder res = new StringBuilder();

        for(String elt:s.split(" ")) {
            if(elt.contains("(")) {
                String[] nameAndArgs = elt.split("\\(");
                for(int i=0; i<nameAndArgs.length; i++)
                {
                    if(Objects.equals(nameAndArgs[i], ")"))
                        continue;
                    nameAndArgs[i] = Util.cleanType(nameAndArgs[i]);
                    if(i>0) {
                        nameAndArgs[i] = nameAndArgs[i].substring(0, nameAndArgs[i].length() - 1);
                        res.append("args{").append(i).append("}:").append(nameAndArgs[i]).append(" ");
                    }
                    else{
                        res.append(nameAndArgs[i]).append(" ");
                    }
                }
            }
            else
            {
                elt = Util.cleanType(elt);
                res.append(elt).append(" ");
            }
        }

        return res.toString();
    }
}
