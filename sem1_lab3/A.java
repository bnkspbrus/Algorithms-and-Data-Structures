
import java.io.BufferedOutputStream;
import java.io.DataInputStream;
import java.io.IOException;
import java.nio.charset.StandardCharsets;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
 
public class A {
    static byte[] buffer = new byte[(int) Math.pow(2, 16)];
 
    static int mark, size;
    static final DataInputStream din = new DataInputStream(System.in);
 
    public static void main(String[] args) throws IOException {
        BufferedOutputStream out = new BufferedOutputStream(System.out);
        int n = nextInt(), k = nextInt();
        int[] dp = new int[n + 1];
        int[] p = new int[n + 1];
        dp[1] = 0;
        for (int i = 2; i <= n; i++) {
            dp[i] = Integer.MIN_VALUE;
            int cost = i != n? nextInt(): 0;
            for (int j = 1; j <= Math.min(i - 1, k); j++) {
                if (dp[i - j] + cost > dp[i]) {
                    dp[i] = dp[i - j] + cost;
                    p[i] = i - j;
                }
            }
        }
        din.close();
        out.write((dp[n] + "\n").getBytes());
        List<Integer> list = new ArrayList<>();
        list.add(n);
        int i = n;
        while (i != 1) {
            i = p[i];
            list.add(i);
        }
        out.write((list.size() - 1 + "\n").getBytes());
        for (int j = list.size() - 1; j >= 0; j--) {
            out.write((list.get(j) + " ").getBytes());
        }
        out.flush();
    }
 
    static int nextInt() throws IOException {
        int p = read();
        while (Character.isWhitespace(p)) {
            p = read();
        }
        boolean minus = p == '-';
        int res = minus ? 0 : p - '0';
        while (!Character.isWhitespace(p = read())) {
            res = res * 10 + p - '0';
        }
        return minus ? -res : res;
 
    }
 
    static byte read() throws IOException {
        if (mark == size) {
            size = din.read(buffer, mark = 0, (int) Math.pow(2, 16));
            if (size == -1) {
                buffer[0] = -1;
            }
        }
        return buffer[mark++];
    }
}
