import java.io.BufferedOutputStream;
import java.io.DataInputStream;
import java.io.IOException;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.List;
import java.util.Queue;
 
public class G {
 
 
    static byte[] buffer = new byte[(int) Math.pow(2, 16)];
 
    static int mark, size;
    static final DataInputStream din = new DataInputStream(System.in);
 
    public static void main(String[] args) throws IOException {
        BufferedOutputStream out = new BufferedOutputStream(System.out);
        String str = next();
        din.close();
        List<List<Queue<Character>>> good = new ArrayList<>();
        for (int i = 0; i < str.length(); i++) {
            good.add(new ArrayList<>());
            for (int j = 0; j < str.length(); j++) {
                good.get(i).add(new ArrayDeque<>());
            }
        }
        for (int j = 1; j < str.length(); j++) {
            char c = str.charAt(j);
            for (int i = j - 1; i >= 0; i--) {
                char p = str.charAt(i);
                int a = -1, b = -1;
                if (p == '(' && c == ')' || p == '[' && c == ']' || p == '{' && c == '}') {
                    a = i;
                    b = j;
                }
                if (a != -1) {
                    good.get(i).get(j).add(str.charAt(a));
                }
                if (j > i + 1) {
                    if (a != -1) {
                        good.get(i).get(j).addAll(good.get(i + 1).get(j - 1));
                    } else {
                        good.get(i).get(j).addAll(good.get(i).get(j - 1));
                    }
                }
                if (b != -1) {
                    good.get(i).get(j).add(str.charAt(b));
                }
                for (int bord = i; bord < j; bord++) {
                    if (good.get(i).get(j).size() < good.get(i).get(bord).size() + good.get(bord + 1).get(j).size()) {
                        Queue<Character> tmp = new ArrayDeque<>(good.get(i).get(bord));
                        tmp.addAll(good.get(bord + 1).get(j));
                        good.get(i).set(j, tmp);
                    }
                }
            }
        }
        while (!good.get(0).get(str.length() - 1).isEmpty()) {
            out.write((good.get(0).get(str.length() - 1).poll() + "").getBytes());
 
        }
        out.flush();
    }
 
    static String next() throws IOException {
        int p = read();
        while (Character.isWhitespace(p)) {
            p = read();
        }
        int len = 1;
        while (!Character.isWhitespace(read())) {
            len++;
        }
        return new String(buffer, mark - 1 - len, len);
    }
 
    static byte read() throws IOException {
        if (mark == size) {
            size = din.read(buffer, mark = 0, (int) Math.pow(2, 16));
            if (size == -1) {
                buffer[0] = -1;
            }
        }
        return buffer[mark++];
    }
}
