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
        int n, numbermax, numbermemory;
        n = Integer.parseInt(sc.nextLine());
        numbermax = sc.nextInt();
        for (int i = 2; i <= n; i++){
            numbermemory = sc.nextInt();
            numbermax = Math.max(numbermemory, numbermax);
        }
        System.out.println(numbermax);
    }
}