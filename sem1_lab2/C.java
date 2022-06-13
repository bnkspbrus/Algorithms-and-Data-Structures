import java.io.BufferedOutputStream;
import java.io.DataInputStream;
import java.io.IOException;
import java.io.OutputStream;
import java.util.*;
 
public class C {
    static byte[] buffer = new byte[(int) Math.pow(2, 16)];
    static int mark, size;
    static DataInputStream din = new DataInputStream(System.in);
 
    public static void main(String[] args) throws IOException {
        OutputStream out = new BufferedOutputStream(System.out);
        int n = nextInt();
        Map<Integer, Integer> queue = new HashMap<>();
        int[] queue1 = new int[n];
        int head = 0, tail = 0;
        int tmp;
        for (int i = 0; i < n; i++) {
            switch (nextInt()) {
                case (1):
                    queue.put(tmp = nextInt(), tail);
                    queue1[tail++] = tmp;
                    break;
                case (2):
                    head++;
                    break;
                case (3):
                    tail--;
                    break;
                case (4):
                    int q = nextInt();
                    int pos = queue.get(q);
                    int res = pos - head;
                    out.write((res + "\n").getBytes());
                    break;
                case (5):
                    out.write((queue1[head] + "\n").getBytes());
            }
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
            size = din.read(buffer, mark = 0, buffer.length);
            if (size == -1) {
                buffer[0] = -1;
            }
        }
        return buffer[mark++];
    }
}
