import java.io.*;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class D {
    static char[] s;
    static int[] p;
    static final BufferedWriter out = new BufferedWriter(new OutputStreamWriter(System.out));

    public static void main(String[] args) throws IOException {
        String t = Reader.next();
        String concat = t + "#" + Reader.next();
        s = concat.toCharArray();
        getPF();
        int k = t.length();
        List<Integer> nums = new ArrayList<>();
        int shift = 2 * k + 1;
        for (int i = shift; i <= concat.length(); i++) {
            if (p[i] == k) {
                nums.add(i - shift + 1);
            }
        }
        out.write(nums.size() + "\n");
        for (int i : nums) {
            out.write(i + " ");
        }
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
