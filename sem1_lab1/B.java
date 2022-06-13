import java.util.Scanner;

public class B {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int dlina = Integer.parseInt(sc.next());
        int[] array = new int[dlina];
        array[0] = sc.nextInt();
        int min = array[0];
        int max = array[0];
        for (int i = 1; i < dlina; i++) {
            array[i] = Integer.parseInt(sc.next());
            if (array[i] < min) {
                min = array[i];
            }
            if (array[i] > max) {
                max = array[i];
            }
        }
        dlina = max - min + 1;
        simpleCountingSort(array, dlina, min);
    }

    private static void simpleCountingSort(int[] array, int dlina, int min) {

        int[] C = new int[dlina];
        for (int j : array) {
            C[j - min]++;
        }

        for (int number = 0; number < dlina; number++) {
            for (int i = 0; i < C[number]; i++) {
                System.out.print(number + min + " ");
            }
        }
    }
}
