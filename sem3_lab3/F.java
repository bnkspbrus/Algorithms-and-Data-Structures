import java.io.*;
import java.util.*;

import static java.lang.Math.*;

public class F {
    static final int x = 31;
    static long[][] p;
    static final List<Long> x_pow = new ArrayList<>();
    static int max = Integer.MAX_VALUE;

    static {
        x_pow.add(1L);
    }

    static String[] strings;

    static int k;
    static final BufferedWriter out = new BufferedWriter(new OutputStreamWriter(System.out));

    public static void main(String[] args) throws IOException {
        k = Reader.nextInt();
        strings = new String[k];
        for (int i = 0; i < k; i++) {
            strings[i] = Reader.next();
            max = min(strings[i].length(), max);
        }
        p = new long[k][];
        for (int i = 0; i < k; i++) {
            p[i] = getPref(strings[i].toCharArray());
        }
        String s = substr();
        out.write(s);
        out.flush();
    }

    private static String substr() {
        int l = 0;
        int r = max + 1;
        String s = strings[0];
        long[] pref = getPref(s.toCharArray());
        Set<Long> set = new HashSet<>();
        long hash = 0;
        int length = 0;
        while (l < r - 1) {
            int m = (l + r) / 2;
            while (x_pow.size() <= m) {
                x_pow.add(x_pow.get(x_pow.size() - 1) * x);
            }
            fillSet(set, pref, m);
            for (int i = 1; i < k; i++) {
                Set<Long> set2 = new HashSet<>();
                fillSet(set2, p[i], m);
                set.retainAll(set2);
            }
            if (!set.isEmpty()) {
                hash = set.iterator().next();
                length = m;
                l = m;
            } else {
                r = m;
            }
        }
        return find(pref, s, hash, length);
    }

    static String find(long[] pref, String s, long hash, int length) {
        String ans = null;
        for (int i = 0; i < pref.length - length; i++) {
            if (pref[i + length] - pref[i] * x_pow.get(length) == hash) {
                ans = s.substring(i, i + length);
            }
        }
        return ans;
    }

    static void fillSet(Set<Long> set, long[] pref, int m) {
        for (int i = 0; i < pref.length - m; i++) {
            set.add(pref[i + m] - pref[i] * x_pow.get(m));
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
