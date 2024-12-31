public class Calculator {

    public static float divide(float numerator, float denominator) throws Exception
    {
        if(denominator == 0)
            throw new ArithmeticException("Denominator must be different than 0");

        if(numerator < 0 || denominator < 0)
            throw new NegativeNumberException();

        return numerator/denominator;
    }

}