import java.io.BufferedOutputStream;
import java.io.DataInputStream;
import java.io.IOException;
 
public class B {
 
    static byte[] buffer = new byte[(int) Math.pow(2, 16)];
 
    static int mark, size;
    static final DataInputStream din = new DataInputStream(System.in);
 
    public static void main(String[] args) throws IOException {
        BufferedOutputStream out = new BufferedOutputStream(System.out);
        int n = nextInt(), m = nextInt();
        int[][] d = new int[n][m];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i == 0 && j == 0) {
                    d[i][j] = nextInt();
                } else {
                    int cost = nextInt();
                    d[i][j] = Integer.MIN_VALUE;
                    if (j > 0) {
                        d[i][j] = Math.max(d[i][j], d[i][j - 1] + cost);
                    }
                    if (i > 0) {
                        d[i][j] = Math.max(d[i][j], d[i - 1][j] + cost);
                    }
                }
            }
        }
        din.close();
        out.write((d[n - 1][m - 1] + "\n").getBytes());
        StringBuilder sb = new StringBuilder();
        int i = n - 1, j = m - 1;
        while (i != 0 || j != 0) {
            if (i == 0) {
                sb.append("R");
                j--;
            } else if (j == 0) {
                sb.append("D");
                i--;
            } else {
                if (d[i - 1][j] > d[i][j - 1]) {
                    i--;
                    sb.append("D");
                } else {
                    j--;
                    sb.append("R");
                }
            }
        }
        out.write(sb.reverse().toString().getBytes());
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
