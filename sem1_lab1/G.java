import java.util.Scanner;
 
public class G {
    public static void main(String[] args) {
        //System.out.println(Math.ceil(10.0 / 2.0));
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int x = sc.nextInt();
        int y = sc.nextInt();
 
 
        if (y < x) {
            int tmp = y;
            y = x;
            x = tmp;
        }
        int a = 0, b = 0, counter = x;
        n--;
        /*while (true) {
            if (((y * (b + 1) / x) + (b + 1) < n) || (((y * (b + 1) / x) + (b + 1) == n) && ((y * (b + 1) / x) * x == y * (b + 1)))){//|| (((y * (b + 1) / x) + (b + 1) = n) && ()){
                a = y * (b + 1) / x;
                b++;
                if (a + b == n) {
                    break;
                }
            } else {
                while (a + b < n) {
                    a++;
                }
                break;
            }
        }
        counter += x * a;
        System.out.println(counter);*/
        while ((y * (b + 1) / x) + (b + 1) < n) {
            a = y * (b + 1) / x;
            b++;
        }
        if (((y * (b + 1) / x) + (b + 1) == n) && ((y * (b + 1) / x) * x == y * (b + 1))) {
            a = y * (b + 1) / x;
            //b++;
            counter += x * a;
            //System.out.println(counter);
 
        } else {
            int k = a;
            a = y * (b + 1) / x;
            while (k + b < n) {
                k++;
            }
            //System.out.println(counter);
            counter += Math.min((a * x + (y * (b + 1) % x)), k * x);
 
        }
        System.out.println(counter);
 
 
        /*while (true) {
            if (((a + Math.ceil((y * (b + 1) / x))) * x + (b + 1) * y) < n) {
                b++;
 
            } else {
                while ((a * x + b * y) < n) {
                    a++;
                }
                break;
            }
        }
        System.out.println(a + b);*/
 
 
    }
}
