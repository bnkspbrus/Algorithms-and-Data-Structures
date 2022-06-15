import java.io.*;
import java.util.*;

import static java.lang.Math.*;

public class M {
    static final int x = 31;
    static long[] p1, p2;
    static long[] x_pow;
    static final BufferedWriter out = new BufferedWriter(new OutputStreamWriter(System.out));

    public static void main(String[] args) throws IOException {
        String s1 = Reader.next(), s2 = Reader.next();
        int max = max(s1.length(), s2.length());
        x_pow = new long[max + 1];
        x_pow[0] = 1;
        for (int i = 1; i <= max; i++) {
            x_pow[i] = x_pow[i - 1] * x;
        }
        p1 = getPref(s1.toCharArray());
        p2 = getPref(s2.toCharArray());
        int l = 0, r = min(s1.length(), s2.length()) + 1;
        Set<Long> set = new HashSet<>();
        int begin = 0, length = 0;
        while (l < r - 1) {
            int m = (l + r) / 2;
            fillSet(set, m);
            long minHash = Long.MAX_VALUE;
            int pos = -1;
            for (int i = 0; i < p2.length - m; i++) {
                long hash = p2[i + m] - p2[i] * x_pow[m];
                if (set.contains(hash)) {
                    if (pos == -1 || minHash > hash) {
                        minHash = hash;
                        pos = i;
                    }
                }
            }
            if (pos != -1) {
                begin = pos;
                length = m;
                l = m;
            } else {
                r = m;
            }
        }
        out.write(s2.substring(begin, begin + length));
        out.flush();
    }

    static void fillSet(Set<Long> set, int m) {
        for (int i = 0; i < p1.length - m; i++) {
            set.add(p1[i + m] - p1[i] * x_pow[m]);
        }
    }

    private static long[] getPref(char[] s) {
        long[] h = new long[s.length + 1];
        for (int i = 1; i < h.length; i++) {
            h[i] = h[i - 1] * x + s[i - 1];
        }
        return h;
    }

    static class Reader {
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
}
