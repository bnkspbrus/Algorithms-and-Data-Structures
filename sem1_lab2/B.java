import java.io.*;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class B {

    static int mark, size;
    //static BufferedReader br = new BufferedReader(new InputStreamReader(System.in), 200001);
    static final int BUFFER_SIZE = (int) Math.pow(2, 16);
    static byte[] buffer = new byte[BUFFER_SIZE];
    static DataInputStream din = new DataInputStream(System.in);
    static boolean hasNext = true;

    public static void main(String[] args) throws IOException {
        //System.out.println(Character.isWhitespace('\n'));
        //System.out.println("(" + (char) 10 + ")");
        /*Scanner sc = new Scanner(System.in);
        String str = sc.nextLine();
        Scanner sc1 = new Scanner(str);*/
        //p = br.read();
        List<int[]> stack = new ArrayList<>();
        int colour, del = -1, counter = 0;
        while ((colour = nextInt()) != -1) {
            if (colour == del) {
                counter++;
                continue;
            }
            del = -1;
            if ((stack.size() > 0) && (stack.get(stack.size() - 1)[0] == colour)) {
                stack.get(stack.size() - 1)[1]++;
                if (stack.get(stack.size() - 1)[1] == 3) {
                    counter += 3;
                    stack.remove(stack.size() - 1);
                    del = colour;
                }
            } else {
                stack.add(new int[]{colour, 1});
            }
        }
        /*for (int[] i : stack) {
            for (int j : i) {
                System.out.print(j + " ");
            }
            System.out.println();
        }*/
        System.out.println(counter);
    }

    static int nextInt() throws IOException {
        if (!hasNext) {
            return -1;
        }
        int p = read();
        while (p == ' ') {
            p = read();
        }
        if (p == '\n') {
            return -1;
        }
        boolean minus = p == '-';
        int res = minus ? 0 : p - '0';
        while (!Character.isWhitespace(p = read())) {
            res = res * 10 + p - '0';
        }
        hasNext = p != '\n';
        return minus ? -res : res;

    }


    static byte read() throws IOException {
        if (mark == size) {
            size = din.read(buffer, mark = 0, BUFFER_SIZE);
            if (size == -1) {
                buffer[0] = -1;
            }
        }
        return buffer[mark++];
    }
}
