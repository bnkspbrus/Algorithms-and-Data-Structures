import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;


public class K {
    final static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static int n, r;
    static String[] tokens;
    static int it;
    static List<List<Pair>> g;
    static int[] grundy;

    public static void main(String[] args) throws IOException {
        n = Reader.nextInt();
        r = Reader.nextInt() - 1;
        g = new ArrayList<>(n);
        grundy = new int[n];
        for (int i = 0; i < n; i++) {
            g.add(new ArrayList<>());
        }
        for (int i = 0; i < n - 1; i++) {
            int u = Reader.nextInt() - 1, v = Reader.nextInt() - 1;
            g.get(u).add(new Pair(v, i + 1));
            g.get(v).add(new Pair(u, i + 1));
        }
        dfs(r, -1);
        if (grundy[r] == 0) {
            System.out.println(2);
        } else {
            System.out.println(1);
            System.out.println(findEdge(r, -1, 0));
        }
//        int grundy = dfs(r, -1);
    }

    static int findEdge(int u, int p, int exp_grundy) {
        for (Pair pair : g.get(u)) {
            if (pair.v == p) {
                continue;
            }
            int v = pair.v;
            int new_grundy = grundy[u] ^ (grundy[v] + 1);
            if (new_grundy == exp_grundy) {
                return pair.num;
            } else {
                int res = findEdge(v, u, (exp_grundy ^ new_grundy) - 1);
                if (res != -1) {
                    return res;
                }
            }
        }
        return -1;
    }

    static void dfs(int u, int p) {
        grundy[u] = 0;
        for (Pair pair : g.get(u)) {
            if (pair.v != p) {
                dfs(pair.v, u);
                grundy[u] ^= (grundy[pair.v] + 1);
            }
        }
    }

    static void readLine() throws IOException {
        it = 0;
        tokens = br.readLine().split("\\s");
    }

    static int nextInt() throws IOException {
        if (tokens == null || it == tokens.length) {
            readLine();
        }
        return Integer.parseInt(tokens[it++]);
    }
}

class Pair {
    final int v, num;

    public Pair(int v, int num) {
        this.v = v;
        this.num = num;
    }
}

class Reader {
    static final BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer tokenizer = new StringTokenizer("");

    /**
     * get next word
     */
    static String next() throws IOException {
        while (!tokenizer.hasMoreTokens()) {
            //TODO add check for eof if necessary
            tokenizer = new StringTokenizer(reader.readLine());
        }
        return tokenizer.nextToken();
    }

    static int nextInt() throws IOException {
        return Integer.parseInt(next());
    }
}
