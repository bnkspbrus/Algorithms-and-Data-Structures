import java.io.BufferedOutputStream;
//import java.io.DataInputStream;
import java.io.IOException;
import java.util.Scanner;
 
public class E {
    //static byte[] buffer = new byte[(int) Math.pow(2, 16)];
 
    //static int mark, size;
    //static final DataInputStream din = new DataInputStream(System.in);
 
    public static void main(String[] args) throws IOException {
        BufferedOutputStream out = new BufferedOutputStream(System.out);
        //String s1 = next(), s2 = next();
        //din.close();
        Scanner sc = new Scanner(System.in);
        String s1 = sc.next(), s2 = sc.next();
        int[][] d = new int[s1.length() + 1][s2.length() + 1];
        for (int i = 0; i <= s1.length(); i++) {
            for (int j = 0; j <= s2.length(); j++) {
                if (i == 0 || j == 0) {
                    d[i][j] = i + j;
                } else if (s1.charAt(i - 1) == s2.charAt(j - 1)) {
                    d[i][j] = d[i - 1][j - 1];
                } else {
                    d[i][j] = Math.min(Math.min(d[i - 1][j - 1] + 1, d[i - 1][j] + 1), d[i][j - 1] + 1);
                }
            }
        }
        out.write((d[s1.length()][s2.length()] + "").getBytes());
        out.flush();
 
    }
 
//    static String next() throws IOException {
//        int p = read();
//        while (Character.isWhitespace(p)) {
//            p = read();
//        }
//        int len = 1;
//        while (!Character.isWhitespace(read())) {
//            len++;
//        }
//        return new String(buffer, mark - 1 - len, len);
//    }
//
//    static byte read() throws IOException {
//        if (mark == size) {
//            size = din.read(buffer, mark = 0, (int) Math.pow(2, 16));
//            if (size == -1) {
//                buffer[0] = -1;
//            }
//        }
//        return buffer[mark++];
//    }
}
