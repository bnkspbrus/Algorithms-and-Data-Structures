import java.io.BufferedOutputStream;
import java.io.DataInputStream;
import java.io.IOException;
import java.io.OutputStream;
import java.util.ArrayList;
import java.util.List;
import java.util.Stack;

public class E {
    static byte[] buffer = new byte[(int) Math.pow(2, 16)];
    static int mark, size;
    static DataInputStream din = new DataInputStream(System.in);
    static int sym;

    public static void main(String[] args) throws IOException {
        OutputStream out = new BufferedOutputStream(System.out);
        Stack<Integer> stack = new Stack<>();
        while ((sym = nextSym()) != -1) {
            if (!Character.isDigit(sym)) {
                int a2 = stack.pop();
                int a1 = stack.pop();
                switch (sym) {
                    case ('+'):
                        stack.push(a1 + a2);
                        break;
                    case ('*'):
                        stack.push(a1 * a2);
                        break;
                    case ('-'):
                        stack.push(a1 - a2);
                        break;
                }
            } else {
                stack.push(nextInt());
            }

        }
        out.write((stack.pop()).toString().getBytes());
        out.flush();
    }

    static int nextInt() throws IOException {
        //boolean minus = p == '-';
        int p = sym;
        int res = p - '0';
        while (!Character.isWhitespace(p = read())) {
            res = res * 10 + p - '0';
        }
        return res;
    }

    static int nextSym() throws IOException {
        int p = read();
        if (p == '\n') {
            return -1;
        }
        while (Character.isWhitespace(p)) {
            p = read();
        }
        return p;
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
