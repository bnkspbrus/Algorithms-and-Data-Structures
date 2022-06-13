import java.util.Scanner;

public class H {
    static long h, w, n;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        h = sc.nextInt();
        w = sc.nextInt();
        n = sc.nextInt();
        //System.out.println(h + " " + w);
        long l = 0, r = Math.max(h, w) * n;
        while (r - l > 1) {
            long m = (l + r) / 2;
            if (good(m)) {
                r = m;
            } else {
                l = m;
            }
        }
        System.out.println(r);


    }

    private static boolean good(long x) {
        return (x / h) * (x / w) >= n;
    }
}
