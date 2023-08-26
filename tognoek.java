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
        int a, b;
        double k;
        a = sc.nextInt();
        b = sc.nextInt();
        if (a == 0) {
            if (b == 0) {
                System.out.println("WOW");
            } else {
                System.out.println("NO");
            }
        } else {
            if (b == 0) {
                System.out.println(0);
            } else {
                k = (double) (-b * 1.0 / a);
                System.out.println(String.format("%.2f", k));
            }
        }
        sc.close();
    }
}