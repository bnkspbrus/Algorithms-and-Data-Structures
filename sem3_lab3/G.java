import java.io.*;
import java.util.*;

public class G {
    static int n;
    static final Node root = new Node();
    static Node[] nodes;
    static final BufferedWriter out = new BufferedWriter(new OutputStreamWriter(System.out));

    static {
        root.p = root;
//        root.s = "";
    }

    static int cnt = 0;

    public static void main(String[] args) throws IOException {
        n = Reader.nextInt();
        nodes = new Node[n];
        while (cnt < n) {
            add_string(Reader.next());
        }
        Node v = root;
        for (char c : Reader.next().toCharArray()) {
            c -= 'a';
            v = go(v, c);
            Node u = v;
            while (!u.used) {
                u.used = true;
                u = get_link(u);
            }
        }
        for (Node n: nodes) {
            if (n.used) {
                out.write("YES\n");
            } else {
                out.write("NO\n");
            }
        }
        out.flush();
    }

    static Node get_link(Node v) {
        if (v.link == null) {
            if (v == root || v.p == root) {
                v.link = root;
            } else {
                v.link = go(get_link(v.p), v.pch);
            }
        }
        return v.link;
    }

    static Node go(Node v, char c) {
        if (v.go[c] == null) {
            if (v.next[c] != null) {
                v.go[c] = v.next[c];
            } else {
                v.go[c] = v == root ? root : go(get_link(v), c);
            }
        }
        return v.go[c];
    }

    static void add_string(String s) {
        Node v = root;
        for (char c : s.toCharArray()) {
            c -= 'a';
            if (v.next[c] == null) {
                Node next = new Node();
//                next.s = v.s + Character.toString(c + 'a');
                next.p = v;
                next.pch = c;
                v.next[c] = next;
            }
            v = v.next[c];
        }
        v.leaf = true;
        nodes[cnt++] = v;
    }

    static class Node {
        Node[] next = new Node[26], go = new Node[26];
        boolean leaf;
        Node p, link;
        char pch;
        boolean used;
//        String s;
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
