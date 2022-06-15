import java.io.*;
import java.util.StringTokenizer;

public class A {
    static final int p = 31;
    static long[] p_pow, h;
    static final int[] bounds = new int[4];
    static final BufferedWriter out = new BufferedWriter(new OutputStreamWriter(System.out));

    public static void main(String[] args) throws IOException {
        String s = Reader.next();
        p_pow = new long[s.length() + 1];
        h = new long[s.length() + 1];
        p_pow[0] = 1;
        for (int i = 1; i < p_pow.length; i++) {
            p_pow[i] = p_pow[i - 1] * p;
        }
        for (int i = 1; i < h.length; i++) {
            char c = s.charAt(i - 1);
            h[i] = h[i - 1] * p + c;
        }
        int m = Reader.nextInt();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < 4; j++) {
                bounds[j] = Reader.nextInt();
            }
            long h1 = h[bounds[1]] - h[bounds[0] - 1] * p_pow[bounds[1] - bounds[0] + 1];
            long h2 = h[bounds[3]] - h[bounds[2] - 1] * p_pow[bounds[3] - bounds[2] + 1];
            if (h1 == h2) {
                out.write("Yes\n");
            } else {
                out.write("No\n");
            }
        }
        out.flush();
    }

    static long hash(String s) {
        long hash = 0;
        int i = 0;
        for (char c : s.toCharArray()) {
            hash += (c - 'a' + 1) * p_pow[i++];
        }
        return hash;
    }
}

/**
 * Class for buffered reading int and double values
 */
class Reader {
    static final BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer tokenizer = new StringTokenizer("");

    /**
     * get next word
     */
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
