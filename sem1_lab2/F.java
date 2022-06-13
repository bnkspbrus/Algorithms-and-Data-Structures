import java.io.BufferedOutputStream;
import java.io.DataInputStream;
import java.io.IOException;
import java.io.OutputStream;
import java.util.Stack;
 
public class F {
    static byte[] buffer = new byte[(int) Math.pow(2, 16)];
    static int mark, size;
    static DataInputStream din = new DataInputStream(System.in);
    public static void main(String[] args) throws IOException {
        OutputStream out = new BufferedOutputStream(System.out);
        int n = nextInt();
        Stack<Integer> stack = new Stack<>();
        int prev = Integer.MIN_VALUE;
        for (int i = 0; i < n; i++) {
            if (stack.empty()) {
                stack.push(nextInt());
            } else {
                int tmp = nextInt();
                int pop = prev;
                while ((!stack.isEmpty()) && (stack.peek() < tmp))  {
                    pop = stack.pop();
                    if (pop < prev) {
                        System.out.println("impossible");
                        return;
                    }
                    out.write("pop\n".getBytes());
                }
                prev = pop;
                stack.push(tmp);
            }
            out.write("push\n".getBytes());
        }
        while (!stack.empty()) {
            int pop = stack.pop();
            if (pop < prev) {
                System.out.println("impossible");
                return;
            }
            out.write("pop\n".getBytes());
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
            size = din.read(buffer, mark = 0, buffer.length);
            if (size == -1) {
                buffer[0] = -1;
            }
        }
        return buffer[mark++];
    }
}
