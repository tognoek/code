import java.util.Scanner;

public class tognoek {

    public static int gcd(int _a, int _b) {
        int temp = _a % _b;
        while (_b != 0) {
            temp = _b;
            _b = _a % _b;
            _a = temp;
        }
        return _a;
    }

    public static void main(String[] args) {
        for (int i = 0; i < 3; i++) {
            System.out.println("**********");
        }
    }
}