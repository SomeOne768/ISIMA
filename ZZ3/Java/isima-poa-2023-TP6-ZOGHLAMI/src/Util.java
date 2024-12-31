public class Util {

    public static String cleanType(String s) {
        int i = 0,
                last = 0;
        while (i != -1) {
            last = i;
            i = nextPoint(s, i);
        }

        return s.substring(last);
    }

    public static int nextPoint(String s, int i) {
        while (i < s.length() && s.charAt(i) != '.') {
            i++;
        }

        return (i == s.length()) ? -1 : i + 1;
    }
}
