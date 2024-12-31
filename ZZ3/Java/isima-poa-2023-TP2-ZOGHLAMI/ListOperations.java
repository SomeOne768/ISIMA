import java.util.*;


public class ListOperations{

    public static ArrayList<Integer> filterEvenNumbers(ArrayList<Integer> L)
    {
        ArrayList<Integer> evenNumbers = new ArrayList<Integer>();
        for(Integer i: L)
        {
            if(i % 2 == 0)
                evenNumbers.add(i);
        }

        return evenNumbers;
    }
}