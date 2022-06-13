import java.util.Scanner;
 
public class I {
    static double C, i = 0, eps = 0.0000001;
 
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        C = scanner.nextDouble();
 
        while (f(i) < C) {
            i += 5;
        }
        double x = ternarySearch(i - 5, i);
 
        System.out.println(x);
    }
 
 
    public static double ternarySearch(double left, double right) {
        while (right - left > eps) {
            double mid = (right + left) / 2;
            if (f(mid) > C) {
                right = mid;
            } else {
                left = mid;
            }
        }
        return left;
    }
 
    private static double f(double x) {
        return (x * x + Math.sqrt(x));
    }
 
}
