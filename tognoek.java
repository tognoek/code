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
        Scanner sc = new Scanner(System.in);
        int a, b, c;
        a = sc.nextInt();
        b = sc.nextInt();
        c = sc.nextInt();
        System.out.println((a - b ) * c);
        sc.close();
    }
}