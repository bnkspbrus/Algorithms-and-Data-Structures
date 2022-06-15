import java.io.BufferedWriter;
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.util.Scanner;

public class B {
    static final Scanner sc = new Scanner(System.in);
    static int[] p;
    static final BufferedWriter out = new BufferedWriter(new OutputStreamWriter(System.out));

    public static void main(String[] args) throws IOException {
        String s = sc.next();
        p = new int[s.length() + 1];
        p[0] = -1;
        for (int i = 1; i <= s.length(); i++) {
            int k = p[i - 1];
            while (k != -1 && s.charAt(k) != s.charAt(i - 1)) {
                k = p[k];
            }
            p[i] = k + 1;
        }
        for (int i = 1; i < p.length; i++) {
            out.write(String.format("%d ", p[i]));
        }
        out.flush();
    }
}
