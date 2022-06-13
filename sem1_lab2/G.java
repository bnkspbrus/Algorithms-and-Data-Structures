import java.io.*;
import java.util.StringTokenizer;
 
public class G {
 
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static String str;
 
    public static void main(String[] args) throws IOException {
        OutputStream out = new BufferedOutputStream(System.out);
        //Scanner sc = new Scanner(System.in);
        //System.out.println(Character.isWhitespace(' '));
        String string = br.readLine().strip();
        int n = Integer.parseInt(string);
        int[][] a = new int[n + 1][3];
 
        while ((str = br.readLine()) != null) {
            StringTokenizer st = new StringTokenizer(str);
        //while (sc.hasNextLine()) {
            switch (st.nextToken()) {
                case ("union"):
                    int a1 = Integer.parseInt(st.nextToken());
                    int a2 = Integer.parseInt(st.nextToken());
                    for (int j = 0; j < 2; j++) {
                        a[a1][j] = a[a1][j] == 0 ? a1 : a[a1][j];
                        a[a2][j] = a[a2][j] == 0 ? a2 : a[a2][j];
                    }
                    a[a1][2] = a[a1][2] == 0 ? 1 : a[a1][2];
                    a[a2][2] = a[a2][2] == 0 ? 1 : a[a2][2];
                    int j = a[a1][0];
                    while (a[j][0] != j) {
                        j = a[j][0];
                    }
                    int k = a[a2][0];
                    while (a[k][0] != k) {
                        k = a[k][0];
                    }
                    if (k == j) {
                       break;
                    }
                    a[k][0] = a[j][0] = Math.max(a[k][0], a[j][0]);
                    a[k][1] = a[j][1] = Math.min(a[k][1], a[j][1]);
                    a[k][2] = a[j][2] = a[k][2] + a[j][2];
                    break;
                case ("get"):
                    int s = Integer.parseInt(st.nextToken());
                    for (j = 0; j < 2; j++) {
                        a[s][j] = a[s][j] == 0 ? s : a[s][j];
                        a[s][j] = a[s][j] == 0 ? s : a[s][j];
                    }
                    a[s][2] = a[s][2] == 0 ? 1 : a[s][2];
                    j = a[s][0];
                    while (a[j][0] != j) {
                        j = a[j][0];
                    }
                    out.write((a[j][1] + " ").getBytes());
                    out.write((a[j][0] + " ").getBytes());
                    out.write((a[j][2] + "\n").getBytes());
                    break;
 
 
            }
 
        }
        out.flush();
 
 
    }
 
}
