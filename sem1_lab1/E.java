import java.util.Scanner;
 
public class E {
    static int[] array;
 
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int dlina = sc.nextInt();
        array = new int[dlina];
        for (int i = 0; i < dlina; i++) {
            array[i] = sc.nextInt();
        }
        quickSort(0, dlina - 1);
        //System.out.print(Arrays.toString(array));
        dlina = sc.nextInt();
        for (int i = 0; i < dlina; i++) {
            boolean flag = false;
            int a = sc.nextInt();
            int b = sc.nextInt();
            int numA = binSearch(a, flag);
            flag = true;
            int numB = binSearch(b, flag);
            int res = numB - numA;
            System.out.print(res + " ");
 
        }
 
    }
 
    private static int binSearch(int key, boolean flag) {
        int l = -1;
        int r = array.length;
        int m;
        while (l < r - 1) {
            m = (l + r) / 2;
            if (((array[m] < key) && (!flag)) || ((array[m] <= key) && (flag))) {
                l = m;
            } else {
                r = m;
            }
        }
        return r;
    }
 
    private static void quickSort(int l, int r) {
 
 
        if (l < r) {
            int m = median(l, r, (l + r) / 2);
            int tmp = array[(l + r) / 2];
            array[(l + r) / 2] = array[m];
            array[m] = tmp;
            int j = partition(l, r);
            quickSort(l, j);
            quickSort(++j, r);
        }
    }
 
    private static int partition(int l, int r) {
        int x = array[(l + r) / 2];
        int i = l;
        int j = r;
        while (i <= j) {
            while (array[i] < x) {
                i++;
            }
            while (array[j] > x) {
                j--;
            }
            if (i >= j) {
                break;
            }
            int tmp = array[i];
            array[i] = array[j];
            array[j] = tmp;
            i++;
            j--;
 
        }
        return j;
    }
 
    private static int median(int a, int b, int c) {
        if (((array[a] <= array[b]) && (array[b] <= array[c])) || ((array[c] <= array[b]) && (array[b] <= array[a]))) {
            return b;
        } else if (((array[b] <= array[a]) && (array[a] <= array[c])) || ((array[c] <= array[a]) && (array[a] <= array[b]))) {
            return a;
        } else {
            return c;
        }
    }
 
}

