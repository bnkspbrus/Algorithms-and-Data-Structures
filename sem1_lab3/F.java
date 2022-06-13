import java.io.BufferedOutputStream;
import java.io.DataInputStream;
import java.io.IOException;
import java.util.Arrays;
import java.util.Random;
import java.util.Stack;
 
public class F {
    static byte[] buffer = new byte[(int) Math.pow(2, 16)];
 
    static int mark, size, n;
    static final DataInputStream din = new DataInputStream(System.in);
 
    public static void main(String[] args) throws IOException {
        BufferedOutputStream out = new BufferedOutputStream(System.out);
        n = nextInt();
        if (n == 0) {
            out.write("0\n0 0".getBytes());
            out.flush();
            return;
        }
        int[] cost = new int[n + 1];
        for (int i = 1; i <= n; i++) {
            cost[i] = nextInt();
        }
        out.write("\n".getBytes());
        int[][] d = new int[n + 2][n + 1];
        for (int[] ints : d) {
            Arrays.fill(ints, -1);
        }
        int result, save;
        if (cost[1] > 100) {
            d[1][1] = cost[1];
            save = 1;
        } else {
            d[0][1] = cost[1];
            save = 0;
        }
        result = cost[1];
        boolean nach = true;
        for (int j = 2; j <= n; j++) {
            for (int i = 0; i <= n; i++) {
                if (cost[j] <= 100) {
                    if (d[i + 1][j - 1] != -1 || d[i][j - 1] != -1)
                        if (d[i + 1][j - 1] == -1) {
                            d[i][j] = d[i][j - 1] + cost[j];
                        } else if (d[i][j - 1] == -1) {
                            d[i][j] = d[i + 1][j - 1];
                        } else {
                            d[i][j] = Math.min(d[i][j - 1] + cost[j], d[i + 1][j - 1]);
                        }
                } else {
                    if (i > 0 && d[i - 1][j - 1] != -1 || d[i + 1][j - 1] != -1) {
                        if (i == 0 || d[i - 1][j - 1] == -1) {
                            d[i][j] = d[i + 1][j - 1];
                        } else if (d[i + 1][j - 1] == -1) {
                            d[i][j] = d[i - 1][j - 1] + cost[j];
                        } else {
                            d[i][j] = Math.min(d[i - 1][j - 1] + cost[j], d[i + 1][j - 1]);
                        }
                    }
                }
 
                if (j == n) {
                    if (nach && d[i][j] != -1) {
                        result = d[i][j];
                        nach = false;
                        save = i;
                    } else {
                        if (d[i][j] != -1 && d[i][j] <= result) {
                            save = i;
                            result = d[i][j];
                        }
                    }
                }
            }
        }
 
        int i = save;
        int j = n;
        Stack<Integer> stack = new Stack<>();
        while (j > 1) {
            if (cost[j] > 100) {
                if (i == 0 || d[i][j] == d[i + 1][j - 1]) {
                    i++;
                    stack.add(j);
                } else {
                    i--;
                }
            } else {
                if (d[i][j] == d[i + 1][j - 1]) {
                    i++;
                    stack.add(j);
                }
            }
            j--;
        }
        out.write((result + "\n").getBytes());
        out.write((save + " " + stack.size() + "\n").getBytes());
        while (!stack.isEmpty()) {
            out.write((stack.pop() + "\n").getBytes());
        }
        out.flush();
    }
 
    static int nextInt() throws IOException {
        int p = read();
        while (Character.isWhitespace(p)) {
            p = read();
        }
        int res = p - '0';
        while (!Character.isWhitespace(p = read())) {
            res = res * 10 + p - '0';
        }
        return res;
 
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
