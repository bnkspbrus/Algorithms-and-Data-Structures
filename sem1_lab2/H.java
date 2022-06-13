
import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;
 
 
public class H {
    static int[][] a;
 
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        OutputStream out = new BufferedOutputStream(System.out);
        StringTokenizer st = new StringTokenizer(br.readLine());
        String next;
        next = st.nextToken();
        int n = Integer.parseInt(next);
        a = new int[n + 1][3];
        next = st.nextToken();
        int m = Integer.parseInt(next);
        for (int i = 0; i < m; i++) {
            next = br.readLine();
            st = new StringTokenizer(next);
            switch (st.nextToken()) {
                case ("join"):
                    next = st.nextToken();
                    int a1 = Integer.parseInt(next);
                    a[a1][0] = a[a1][0] == 0 ? a1 : a[a1][0];
 
                    next = st.nextToken();
                    int a2 = Integer.parseInt(next);
                    a[a2][0] = a[a2][0] == 0 ? a2 : a[a2][0];
 
                    union(a1, a2);
                    break;
                case ("add"):
                    next = st.nextToken();
                    a1 = Integer.parseInt(next);
                    a[a1][0] = a[a1][0] == 0 ? a1 : a[a1][0];
 
                    int j = get(a1);
                    //System.out.println("addb: " + Arrays.toString(a[j]));
                    next = st.nextToken();
                    int v = Integer.parseInt(next);
                    a[j][2] += v;
                    //System.out.println("adda: " + Arrays.toString(a[j]));
                    break;
                case ("get"):
                    next = st.nextToken();
                    a1 = Integer.parseInt(next);
                    //System.out.println("geta: " + Arrays.toString(a[a1]));
                    a[a1][0] = a[a1][0] == 0 ? a1 : a[a1][0];
                    int counter = a[a1][2];
                    int x = a1;
                    while (a[x][0] != x) {
                        x = a[x][0];
                        counter += a[x][2];
                    }
 
                    out.write((counter + "\n").getBytes());
 
            }
        }
        out.flush();
    }
 
    static int get(int x) {
        while (a[x][0] != x) {
            x = a[x][0];
        }
        return x;
    }
 
    static void union(int x, int y) {
        x = get(x);
        y = get(y);
        //System.out.println("joinb: " + Arrays.toString(a[x]) + " " + Arrays.toString(a[y]));
        if (x == y) {
            return;
        }
 
        if (a[x][1] > a[y][1]) {
            int tmp = y;
            y = x;
            x = tmp;
        }
        a[x][0] = y;
        if (a[x][1] == a[y][1]) {
            a[y][1]++;
        }
        a[x][2] -= a[y][2];
 
 
        /*int i;
        a[x][2] = a[x][3];
        a[x][3] = 0;
        for (i = 4; a[y][i] != 0; i++) {
            a[a[y][i]][2] += a[y][3];
            //System.out.println("join i: " + Arrays.toString(a[a[y][i]]));
        }
        a[y][i] = x;
        a[y][3] = 0;*/
        //System.out.println("joina: " + Arrays.toString(a[x]) + " " + Arrays.toString(a[y]));
 
 
    }
 
}
