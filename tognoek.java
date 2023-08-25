import java.util.Scanner;

public class tognoek {

    public static int gcd(int _a,int _b){
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
        int a, b, c, x, y;
        a = sc.nextInt();
        b = sc.nextInt();
        if (a * b  < 0 && a % b != 0){
            System.out.print("-");
            c = tognoek.gcd(Math.abs(a), Math.abs(b));
            x = Math.abs(a) / c;
            y = Math.abs(b) / c;

            System.out.println(x + " " + y);
        }
        if (a * b  > 0 && a % b != 0){
            c = tognoek.gcd(Math.abs(a), Math.abs(b));
            x = Math.abs(a) / c;
            y = Math.abs(b) / c;

            System.out.println(x + " " + y);
        }
        if (b != 0 && a % b == 0){
            System.out.print(a / b);
        }
        if (b == 0){
            System.out.print("INVALID");
        }
        

        sc.close();
    }
}