import java.io.BufferedOutputStream;
import java.io.DataInputStream;
import java.io.IOException;
import java.io.OutputStream;
import java.util.ArrayList;

public class A {
    //static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static final int BUFFER_SIZE = (int) Math.pow(2, 16);
    static byte[] buffer = new byte[BUFFER_SIZE];

    static int mark, size;
    static DataInputStream din = new DataInputStream(System.in);
    //static StringTokenizer st;
    //static String string;


    public static void main(String[] args) throws IOException {
        OutputStream out = new BufferedOutputStream( System.out );
        //Scanner sc = new Scanner(System.in);
        //Parser p = new Parser(System.in);
        //int n = sc.nextInt();
        int n = nextInt();
        ArrayList<int[]> stack = new ArrayList<>();
        //int top = -1;

        for (int i = 0; i < n; i++) {
            switch (nextInt()) {
                case (1):
                    int tmp;
                    //int tmp1 = stack.get(stack.size() - 1)[1];
                    stack.add(new int[]{tmp = nextInt(), stack.isEmpty() ? tmp : Math.min(tmp, stack.get(stack.size() - 1)[1])});
                    break;
                case (2):
                    stack.remove(stack.size() - 1);
                    break;
                case (3):
                    //System.out.println(stack.get(stack.size() - 1)[1]);
                    out.write((stack.get(stack.size() - 1)[1] + "\n").getBytes());
                    break;
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
            size = din.read(buffer, mark = 0, BUFFER_SIZE);
            if (size == -1) {
                buffer[0] = -1;
            }
        }
        return buffer[mark++];
    }


}
