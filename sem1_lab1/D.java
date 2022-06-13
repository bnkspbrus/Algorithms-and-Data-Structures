import java.util.Scanner;
 
public class D {
    static int[] heap;
    static int k = -1;
 
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int kolvo = sc.nextInt();
        heap = new int[kolvo];
        //System.out.println(Arrays.toString(heap));
        //int j = -1;
        for (int i = 0; i < kolvo; i++) {
            if (sc.nextInt() == 0) {
                heap[++k] = sc.nextInt();
                siftUp();
            } else {
                //int min = heap[0];
                System.out.println(heap[0]);
                heap[0] = heap[k];
                k--;
                siftDown(0);
                //System.out.println(min);
            }
        }
        //System.out.println(Arrays.toString(heap));
    }
 
    private static void siftUp() {
        int j = k;
        while ((j >= 0) && (heap[j] > heap[(j - 1) / 2])) {
            int tmp = heap[j];
            heap[j] = heap[(j - 1) / 2];
            heap[(j - 1) / 2] = tmp;
            j = (j - 1) / 2;
        }
    }
 
    private static void siftDown(int j) {
        while (2 * j + 1 <= k) {
            int left = 2 * j + 1;
            int right = 2 * j + 2;
            int m = left;
            if ((right <= k) && (heap[right] > heap[left])) {
                m = right;
            }
            if (heap[j] >= heap[m]) {
                break;
            }
            int tmp = heap[j];
            heap[j] = heap[m];
            heap[m] = tmp;
            j = m;
        }
    }
 
 
}
