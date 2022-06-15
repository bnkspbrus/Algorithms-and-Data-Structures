import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class H {
    static int n;
    static int[][] g;
    static List<List<Integer>> newG, newGR;
    static List<Integer> order;
    static final BufferedReader bi = new BufferedReader(new InputStreamReader(System.in));
    static boolean[] mark;

    public static void main(String[] args) throws IOException {
        n = Integer.parseInt(bi.readLine().strip());
        g = new int[n][n];
        int smin = Integer.MAX_VALUE;
        int smax = 0;
        for (int i = 0; i < n; i++) {
            int j = 0;
            for (String numStr : bi.readLine().split("\\s")) {
                g[i][j] = Integer.parseInt(numStr);
                if (i != j) {
                    smin = Math.min(smin, g[i][j]);
                }
                smax = Math.max(smax, g[i][j]);
                j++;
            }
        }
        System.out.println(binSearch(smin - 1, smax));
    }

    static int binSearch(int l, int r) {
        while (l < r - 1) {
            int m = (l + r) / 2;
            if (!isComp(m)) {
                l = m;
            } else {
                r = m;
            }
        }
        return r;
    }

    static boolean isComp(int m) {
        newG = new ArrayList<>(n);
        newGR = new ArrayList<>(n);
        for (int i = 0; i < n; i++) {
            newG.add(new ArrayList<>());
            newGR.add(new ArrayList<>());
        }
        for (int v = 0; v < g.length; v++) {
            for (int u = 0; u < g.length; u++) {
                if (v != u && g[v][u] <= m) {
                    newG.get(v).add(u);
                    newGR.get(u).add(v);
                }
            }
        }
        order = new ArrayList<>(n);
        mark = new boolean[n];
        for (int i = 0; i < n; i++) {
            if (!mark[i]) {
                dfs1(i);
            }
        }
        Arrays.fill(mark, false);
        boolean define = false;
        for (int i = 0; i < n; i++) {
            int v = order.get(n - 1 - i);
            if (!mark[v]) {
                if (define) {
                    return false;
                }
                dfs2(v);
                define = true;
            }
        }
        return true;
    }

    static void dfs1(int v) {
        mark[v] = true;
        for (int i = 0; i < newG.get(v).size(); i++) {
            if (!mark[newG.get(v).get(i)]) {
                dfs1(newG.get(v).get(i));
            }
        }
        order.add(v);
    }

    static void dfs2(int v) {
        mark[v] = true;
        for (int i = 0; i < newGR.get(v).size(); i++) {
            if (!mark[newGR.get(v).get(i)]) {
                dfs2(newGR.get(v).get(i));
            }
        }
    }
}

