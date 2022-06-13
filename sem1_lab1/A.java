import java.util.Scanner;

public class A {
    static int[] array;
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        int dlina = sc.nextInt();
        array = new int[dlina];
        for (int i = 0; i < dlina; i++) {
            array[i] = sc.nextInt();
        }
        mergeSortIterative();
        for (int x : array) {
            System.out.print(x + " ");
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
}
