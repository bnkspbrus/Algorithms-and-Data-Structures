import java.io.BufferedOutputStream;
import java.io.DataInputStream;
import java.io.IOException;
import java.util.Arrays;
 
public class D {
 
    static byte[] buffer = new byte[(int) Math.pow(2, 16)];
 
    static int mark, size;
    static final DataInputStream din = new DataInputStream(System.in);
    //static long counter = 0;
    static int n;
    //final static int[] ways = new int[]{2, 2, 2, 2, 3, 0, 3, 2, 2, 2};
    static final int[][] next = new int[][]{{4, 6}, {8, 6}, {7, 9}, {4, 8}, {3, 9, 0}, null, {1, 7, 0}, {2, 6}, {1, 3}, {4, 2}};
 
    public static void main(String[] args) throws IOException {
        BufferedOutputStream out = new BufferedOutputStream(System.out);
        n = nextInt();
        din.close();
        long[][] d = new long[n + 1][10];
        Arrays.fill(d[1], 1);
        d[1][0] = d[1][8] = 0;
        long counter = 0;
        for (int i = 2; i <= n; i++) {
            if (i > 2) {
                for (int j : next[0]) {
                    d[i - 1][0] = (d[i - 1][0] + d[i - 2][j]) % (long) Math.pow(10, 9);
                }
                for (int j : next[8]) {
                    d[i - 1][8] = (d[i - 1][8] + d[i - 2][j]) % (long) Math.pow(10, 9);
                }
            } else {
                d[i - 1][0] = d[i - 1][8] = 1;
            }
            for (int j = 0; j <= 9; j++) {
                if (j != 0 && j != 8 && j != 5) {
                    for (int k : next[j]) {
                        d[i][j] = (d[i][j] + d[i - 1][k]) % (long) Math.pow(10, 9);
 
                    }
                }
            }
        }
        for (long l : d[n]) {
            counter = (l + counter) % (long) Math.pow(10, 9);
        }
        out.write((counter + "").getBytes());
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
