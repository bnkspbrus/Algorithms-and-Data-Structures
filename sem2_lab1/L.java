import java.io.*;
import java.math.BigInteger;
 
public class L {
    static int n, size;
    static double[][] tree;
    static Reader reader;
    //    static boolean[] inArray;
    static final BufferedWriter output = new BufferedWriter(
            new OutputStreamWriter(System.out));
 
    public static void main(String[] args) throws IOException {
        reader = new Reader();
        n = reader.nextInt();
        int m = reader.nextInt();
        getSize();
        tree = new double[size][3];
        treeBuild();
        for (int i = 0; i < m; i++) {
            int id = reader.nextInt();
            int l = reader.nextInt();
            int r = reader.nextInt();
            if (id == 1) {
                int d = reader.nextInt();
                add(l - 1, r, d, 0, 0, (size + 1) / 2);
            } else {
                double res = sum(l - 1, r, 0, 0, (size + 1) / 2);
                output.write(String.format("%.0f", res) + "\n");
            }
        }
        output.flush();
    }
 
    static double sum(int l, int r, int x, int lx, int rx) {
        if (l >= rx || lx >= r) {
            return 0;
        }
        if (lx >= l && rx <= r) {
            double specSum = tree[x][1] + (double) (lx + 1 + rx) * (rx - lx) / 2 * tree[x][2];
            double sum = tree[x][0] + (rx - lx) * tree[x][2];
            return specSum - l * sum;
        }
        int m = (lx + rx) / 2;
        double s1 = sum(l, r, 2 * x + 1, lx, m);
        double s2 = sum(l, r, 2 * x + 2, m, rx);
        int begin = l >= lx ? 1 : lx - l + 1;
        int len = Math.min(r, rx) - Math.max(l, lx);
        int end = begin + len - 1;
        return s1 + s2 + (double) len * (begin + end) / 2 * tree[x][2];
 
    }
 
    static void treeBuild() throws IOException {
        for (int i = 0; i < n; i++) {
            tree[size / 2 + i][0] = reader.nextInt();
            tree[size / 2 + i][1] = (i + 1) * tree[size / 2 + i][0];
            tree[size / 2 + i][2] = 0;
        }
        for (int i = size / 2 - 1; i >= 0; i--) {
            tree[i][0] = tree[2 * i + 1][0] + tree[2 * i + 2][0];
            tree[i][1] = tree[2 * i + 1][1] + tree[2 * i + 2][1];
            tree[i][2] = 0;
        }
    }
 
    static void add(int l, int r, int d, int x, int lx, int rx) {
        if (l >= rx || lx >= r) {
            return;
        }
        if (lx >= l && rx <= r) {
            tree[x][2] = tree[x][2] + d;
            return;
        }
        int m = (lx + rx) / 2;
        add(l, r, d, 2 * x + 1, lx, m);
        add(l, r, d, 2 * x + 2, m, rx);
        tree[x][0] = tree[2 * x + 1][0] + tree[2 * x + 2][0] + (m - lx) * (tree[2 * x + 1][2] + tree[2 * x + 2][2]);
        tree[x][1] = tree[2 * x + 1][1] + tree[2 * x + 2][1] + (double) (lx + 1 + m) * (m - lx) / 2 * tree[2 * x + 1][2] + (double) (m + 1 + rx) * (rx - m) / 2 * tree[2 * x + 2][2];
    }
 
    static void getSize() {
        size = n - 1;
        size |= size >> 1;
        size |= size >> 2;
        size |= size >> 4;
        size |= size >> 8;
        size |= size >> 16;
        size = size * 2 + 1;
    }
}
 
class Reader {
    final private int BUFFER_SIZE = 1 << 16;
    private final DataInputStream din;
    private final byte[] buffer;
    private int bufferPointer, bytesRead;
 
    public Reader() {
        din = new DataInputStream(System.in);
        buffer = new byte[BUFFER_SIZE];
        bufferPointer = bytesRead = 0;
    }
 
    public int nextInt() throws IOException {
        int ret = 0;
        byte c = read();
        while (c <= ' ') {
            c = read();
        }
        boolean neg = (c == '-');
        if (neg)
            c = read();
        do {
            ret = ret * 10 + c - '0';
        } while ((c = read()) >= '0' && c <= '9');
 
        if (neg)
            return -ret;
        return ret;
    }
 
    private void fillBuffer() throws IOException {
        bytesRead = din.read(buffer, bufferPointer = 0,
                BUFFER_SIZE);
        if (bytesRead == -1)
            buffer[0] = -1;
    }
 
    private byte read() throws IOException {
        if (bufferPointer == bytesRead)
            fillBuffer();
        return buffer[bufferPointer++];
    }
 
    public void close() throws IOException {
        din.close();
    }
}

