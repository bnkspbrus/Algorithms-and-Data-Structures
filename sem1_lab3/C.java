import java.io.BufferedOutputStream;
import java.io.DataInputStream;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
 
public class C {
    static byte[] buffer = new byte[(int) Math.pow(2, 16)];
 
    static int mark, size;
    static final DataInputStream din = new DataInputStream(System.in);
 
    public static void main(String[] args) throws IOException {
        BufferedOutputStream out = new BufferedOutputStream(System.out);
        int n = nextInt();
        int[] a = new int[n];
        int[] d = new int[n + 1];
        int[] pos = new int[n + 1];
        int[] prev = new int[n];
        int length = 0;
 
        pos[0] = -1;
        Arrays.fill(d, Integer.MAX_VALUE);
        d[0] = Integer.MIN_VALUE;
        for (int i = 0; i < n; i++) {
            int j = binSearch(d, a[i] = nextInt());
            if (d[j - 1] < a[i] && a[i] <d[j]) {
                d[j] = a[i];
                pos[j] = i;
                prev[i] = pos[j - 1];
                length = Math.max(length, j);
            }
        }
        //System.out.println(Arrays.toString(a));
        //System.out.println(Arrays.toString(d));
        din.close();
        List<Integer> list = new ArrayList<>();
        int p = pos[length];
        while (p != -1) {
            list.add(a[p]);
            p = prev[p];
        }
        //System.out.println(list);
        out.write((list.size() + "\n").getBytes());
        for (int i = list.size() - 1; i >= 0; i--) {
            out.write((list.get(i) + " ").getBytes());
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
 
    static int binSearch(int[] a, int key) {
        int l = -1;
        int r = a.length;
        int m;
        while (l < r - 1) {
            m = (l + r) / 2;
            if (a[m] < key) {
                l = m;
            } else {
                r = m;
            }
        }
        return r;
    }
}
