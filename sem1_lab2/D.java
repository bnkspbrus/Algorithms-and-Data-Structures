import java.io.BufferedOutputStream;
import java.io.DataInputStream;
import java.io.IOException;
import java.io.OutputStream;

public class D {
    static byte[] buffer = new byte[(int) Math.pow(2, 16)];
    static int mark, size;
    static DataInputStream din = new DataInputStream(System.in);

    public static void main(String[] args) throws IOException {
        OutputStream out = new BufferedOutputStream(System.out);
        int n = nextInt();
        int[] a1 = new int[n], a2 = new int[2 * n];
        int h1 = 0, h2 = n, t1 = 0, t2 = n;
        for (int i = 0; i < n; i++) {
            switch ((char) nextSym()) {
                case ('+'):
                    a2[t2++] = nextInt();
                    if ((t1 - h1 + t2 - h2) % 2 == 1) {
                        a1[t1++] = a2[h2++];
                    }
                    break;
                case ('*'):
                    a2[--h2] = nextInt();
                    if ((t1 - h1 + t2 - h2) % 2 == 1) {
                        a1[t1++] = a2[h2++];
                    }
                    break;
                case('-'):
                    out.write((a1[h1++] + "\n").getBytes());
                    if ((t1 - h1 + t2 - h2) % 2 == 1) {
                        a1[t1++] = a2[h2++];
                    }
                    break; }
        }

        out.flush();
    }

    static int nextSym() throws IOException {
        int p = read();
        while (Character.isWhitespace(p)) {
            p = read();
        }
        return p;
    }

    static int nextInt() throws IOException {
        int p = read();
        while (Character.isWhitespace(p)) {
            p = read();
        }
        //boolean minus = p == '-';
        int res = p - '0';
        while (!Character.isWhitespace(p = read())) {
            res = res * 10 + p - '0';
        }
        return res;
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
