import java.util.Arrays;
import java.util.Scanner;

public class C {
    static int[] array;
    static long counter = 0;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int kolvo = sc.nextInt();
        array = new int[kolvo];
        //System.out.println(kolvo);
        for (int i = 0; i < kolvo; i++) {
            array[i] = sc.nextInt();
        }
        mergeSortRecursive(0, array.length);
        System.out.println(counter);

    }

    private static void merge(int left, int mid, int right) {
        int i;
        int it1 = 0;
        int it2 = 0;
        int[] result = new int[right - left];


        while ((left + it1 < mid) && (mid + it2 < right)) {
            if (array[left + it1] > array[mid + it2]) {
                counter += mid - left - it1;
                result[it1 + it2] = array[mid + it2];
                it2++;
            } else {
                result[it1 + it2] = array[left + it1];
                it1++;
                /*if ((mid + it2 < right) && (array[mid + it2] > array[mid + it2 - 1])) {
                    schet ++;
                }*/

            }
        }
        //System.out.print("it2: " + it2 + " " + "mid: " + mid + " " + "right: " + right + " ");
        while (left + it1 < mid) {

            result[it1 + it2] = array[left + it1];

            it1++;

        }

        while (mid + it2 < right) {

            result[it1 + it2] = array[mid + it2];
            it2++;
        }
        //System.out.print("array: " + Arrays.toString(result) + " " + "counter: " + counter + '\n');

        for (i = 0; i < it1 + it2; i++) {
            array[left + i] = result[i];
        }
        //counter += it2;
    }

    /*private static void mergeSortIterative() {
        int i, j;
        for (i = 1; i < array.length; i *=2) {

            for (j = 0; j < array.length - i; j += 2 * i)
            merge(j, j + i, Math.min(j + 2 * i, array.length));
        }
    }*/
    private static void mergeSortRecursive(int left, int right) {
        if (left + 1 >= right) {
            return;
        }
        int mid = (left + right) / 2;
        mergeSortRecursive(left, mid);
        mergeSortRecursive(mid, right);
        merge(left, mid, right);
    }
}
