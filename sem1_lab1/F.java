import java.util.Arrays;
import java.util.Scanner;
 
 
public class F {
    static int[] array;
    static int max;
    static int min;
 
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int size1 = sc.nextInt(), size2 = sc.nextInt();
        array = new int[size1];
        array[0] = sc.nextInt();
        min = max = array[0];
        for (int i = 1; i < size1; i++) {
            array[i] = sc.nextInt();
            if (array[i] < min) {
                min = array[i];
            }
            if (array[i] > max) {
                max = array[i];
            }
        }
        mergeSortIterative();
        //System.out.println(Arrays.toString(array));
        for (int i = 0; i < size2; i++) {
            int a = sc.nextInt();
            if (a <= min) {
                System.out.println(min);
                continue;
            }
            if (a >= max) {
                System.out.println(max);
                continue;
            }
 
            int max = binSearch(a, true);
            //System.out.println("max: " + array[max]);
 
            int min = binSearch(a, false);
            //System.out.println("min: " + array[min]);
            if (Math.abs(a - array[min]) < Math.abs(a - array[max])) {
                System.out.println(array[min]);
            } else {
                System.out.println(array[max]);
            }
 
        }
    }
 
    private static void merge(int left, int mid, int right) {
        int i;
        int it1 = 0;
        int it2 = 0;
        int[] result = new int[right - left];
 
        while ((left + it1 < mid) && (mid + it2 < right)) {
            if (array[left + it1] < array[mid + it2]) {
                result[it1 + it2] = array[left + it1];
                it1++;
            } else {
                result[it1 + it2] = array[mid + it2];
                it2++;
            }
        }
        while (left + it1 < mid) {
            result[it1 + it2] = array[left + it1];
            it1++;
        }
 
        while (mid + it2 < right) {
            result[it1 + it2] = array[mid + it2];
            it2++;
        }
 
        for (i = 0; i < it1 + it2; i++) {
            array[left + i] = result[i];
        }
    }
 
    private static void mergeSortIterative() {
        int i, j;
        for (i = 1; i < array.length; i *= 2) {
 
            for (j = 0; j < array.length - i; j += 2 * i)
                merge(j, j + i, Math.min(j + 2 * i, array.length));
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
        if (flag) {
            return l;
        } else {
            return r;
        }
    }
}
