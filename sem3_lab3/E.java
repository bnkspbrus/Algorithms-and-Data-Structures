import java.io.*;
import java.util.StringTokenizer;

public class E {
    static char[] s;
    static int[] p;
    static final BufferedWriter out = new BufferedWriter(new OutputStreamWriter(System.out));

    public static void main(String[] args) throws IOException {
        s = Reader.next().toCharArray();
        getPF();
        int min = s.length - p[s.length];
        if (p[s.length] * 2 < s.length) {
            min = s.length;
        }
        out.write(Integer.toString(min));
        out.flush();
    }

    static void getPF() {
        p = new int[s.length + 1];
        p[0] = -1;
        for (int i = 1; i <= s.length; i++) {
            int k = p[i - 1];
            while (k != -1 && s[k] != s[i - 1]) {
                k = p[k];
            }
            p[i] = k + 1;
        }
    }

    static class Reader {
        static final BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        static StringTokenizer tokenizer = new StringTokenizer("");

        static String next() throws IOException {
            while (!tokenizer.hasMoreTokens()) {
                tokenizer = new StringTokenizer(reader.readLine());
            }
            return tokenizer.nextToken();
        }

        static int nextInt() throws IOException {
            return Integer.parseInt(next());
        }

        static double nextDouble() throws IOException {
            return Double.parseDouble(next());
        }
    }
}
