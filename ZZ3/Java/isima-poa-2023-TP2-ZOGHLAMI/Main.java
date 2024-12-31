import java.util.*;

public class Main {
    
    public static void main(String args[])
    {
        /*************************** Even number ***************************/
        prettySeparator(50);
        System.out.println("Testing list filtering\n");
        ArrayList<Integer> L = new ArrayList<Integer>();
        
        // Fill list
        for(int i=-10; i<10; i++)
        {
            L.add(i);
        }

        // Display List
        System.out.println("List values: ");
        displayList(L);

        // Taking and display even numbers
        System.out.println("List filtered: ");
        ArrayList<Integer> L2 = ListOperations.filterEvenNumbers(L);
        displayList(L2);
        System.out.println();


        /*************************** Word counter ***************************/
        prettySeparator(50);
        System.out.println("Testing word counter\n");

        // Initialization
        String sentence = "Is my word counter ok ok ok OK WORD ?";
        WordCounter wcSensitive = new WordCounter(sentence);
        WordCounter wcNotSensitive = new WordCounter(sentence, false);
        
        // Display results
        System.out.println("Sensitive:");
        System.out.println(wcSensitive.toString());
        System.out.println("Not sensitive:");
        System.out.println(wcNotSensitive.toString());


        /*************************** NegativeNumberException ***************************/
        prettySeparator(50);
        System.out.println("Testing NegativeNumberException\n");
        int negativeNumber = -4;
        try{
            System.out.println("Is " + negativeNumber + " negative?" );
            testException(negativeNumber);
        }
        catch(Exception e)
        {
            System.out.println(e.getMessage());
        }
        System.out.println();


        /*************************** Handling Exception ***************************/
        prettySeparator(50);
        // divide by 0
        System.out.println("Testing divide\n");
        try{
            System.out.println("Dividing " + 5 + " by " + 0 + "..");
            Calculator.divide(5, 0);
        }
        catch(Exception e)
        {
            System.out.println(e.getMessage());
        }
        System.out.println();

        // negative number
        try{
            System.out.println("Dividing " + -5 + " by " + 1 + "..");
            Calculator.divide(-5, 1);
        }
        catch(Exception e)
        {
            System.out.println(e.getMessage());
        }
        System.out.println();

        // OK test
        float res;
        try{
            System.out.println("Dividing " + 5 + " by " + 3 + "..");
            res = Calculator.divide(5, 3);
            System.out.println("Result of 5/1: " + res);
        }
        catch(Exception e)
        {
            System.out.println(e.getMessage());
        }
        finally
        {
            System.out.println("It works!\n");
        }

        prettySeparator(50);
        System.out.println("\t\tEnd of programme");
        prettySeparator(50);
    }


    public static void testException(int n) throws NegativeNumberException
    {
        if(n<0)
            throw new NegativeNumberException();
    }

    public static void prettySeparator(int n)
    {
        for(int i=0; i<n; i++)
        {
            System.out.print("-");
        }
        System.out.println();
    }

    public static void displayList(ArrayList<Integer> L)
    {
        for(Integer i: L)
        {
            System.out.print(i + " ");
        }
        System.out.println();
    }
}
