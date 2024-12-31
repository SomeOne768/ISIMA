class Main {
    public static void main(String[] args) {
        System.out.println("Hey bro!");

        printArgs(args);

        System.out.println(args.length);
        
        printArgsInv(args);

        printArgsUpper(args);

        printArgsLength(args);

    }

    public static void printArgs(String[] args) {
        for (String s : args) {
            System.out.println(s);
        }
    }

    public static void printArgsInv(String[] args) {
        for (int i = args.length - 1; i >= 0; i--) {
            System.out.println(args[i]);
        }
    }

    public static void printArgsUpper(String[] args) {
        for (String s : args) {
            System.out.println(s.toUpperCase());
        }
    }

    public static void printArgsLength(String[] args) {
        for (String s : args) {
            int longueur = s.length();
            System.out.println(s + ": " + longueur);
        }
    }

    public static void menu(String[] args, int choice)
    {
        switch(choice){
            case 1:
                
                break;
            
            default:
                System.out.println("Mauvais choix");
                break;

        }
    }
    
    
    

    // public static contains(String s, char c)
    // {
    // for(int i=0; i<s.length(); i++)
    // {
    // if(i == c)
    // return true;
    // }

    // return false;
    // }
    // public int Count(String s){
    // String tmp;
    // int count = 0;

    // for(int i=0; i<s.length(); i++)
    // {
    // if( !tmp.contains( s.charAt(i) ) )
    // {
    // tmp += s.charAt(i);
    // count++;
    // }
    // }

    // return count;
    // }
}