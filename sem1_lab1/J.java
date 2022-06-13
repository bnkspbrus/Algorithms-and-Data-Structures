import java.util.Scanner;
 
public class J {
    static int v1, v2;
    static double a;
 
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        v1 = sc.nextInt();
        v2 = sc.nextInt();
        a = sc.nextDouble();
 
        double x = find();
        System.out.println(x);
        //System.out.println(1 - A);
 
 
 
    }
 
    private static double f(double x) {
        return Math.sqrt(Math.pow(x, 2) + Math.pow(1 - a, 2)) / v1 + Math.sqrt(Math.pow(1 - x, 2) + Math.pow(a, 2)) / v2;
    }
 
    private static double find() {
        double minx = 0.000000;
        double min = f(minx);
        for (int i = 1; i <= 1000000; i ++) {
            double x = i * Math.pow(10, -6);
            //System.out.println(x);
            if (f(x) < min) {
                minx = x;
                min = f(x);
            }
        }
 
        return minx;
    }
    static double round(double x, int precision) {
        return ((int) (x * Math.pow(10.0, precision)) / Math.pow(10.0, precision));
    }
 
 
}
