import java.io.*;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.StringTokenizer;

import static java.lang.Math.*;

public class I {
    static int n;
    static final Node root = new Node();
    static Node[] nodes;
    static final BufferedWriter out = new BufferedWriter(new OutputStreamWriter(System.out));
    static List<Node> q;

    static {
        root.p = root;
//        root.s = "";
    }

    static int cnt = 0;

    public static void main(String[] args) throws IOException {
        n = Reader.nextInt();
        nodes = new Node[n];
        int[] last = new int[n];
        while (cnt < n) {
            String s = Reader.next();
            last[cnt] = s.length() - 1;
            add_string(s);
        }
        bfs();
        Node v = root;
        String t = Reader.next();
        for (int i = 0; i < t.length(); i++) {
            int c = t.charAt(i) - 'a';
            v = v.go[c];
            if (v.min == Integer.MAX_VALUE) {
                v.min = i;
            }
            v.max = i;
        }
        reverse_bfs();
        for (int i = 0; i < nodes.length; i++) {
            Node n = nodes[i];
            if (n.min == Integer.MAX_VALUE) {
                out.write("-1 -1\n");
            } else {
                out.write((n.min - last[i]) + " " + (n.max - last[i]) + "\n");
            }
        } out.flush();
    }

    static void reverse_bfs() {
        Collections.reverse(q);
        for (Node v : q) {
            v.link.min = min(v.link.min, v.min);
            v.link.max = max(v.link.max, v.max);
        }
    }

    static void bfs() {
        q = new ArrayList<>();
        q.add(root);
        int pos = 0;
        while (pos != q.size()) {
            Node v = q.get(pos++);
            if (v == root || v.p == root) {
                v.link = root;
            } else {
                v.link = v.p.link.go[v.pch];
            }
            for (char c = 0; c < 26; c++) {
                if (v.next[c] != null) {
                    v.go[c] = v.next[c];
                    q.add(v.next[c]);
                } else {
                    v.go[c] = v == root ? root : v.link.go[c];
                }
            }
        }
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
        int min = Integer.MAX_VALUE, max = -1;
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
