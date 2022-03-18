import java.util.Arrays;

public class ARRAY {
    public static void main(String[] args) {
        int[] a = new int[100];
        for (int i = 0; i < 100; i++) {
            a[i] = i;
        }
        for (int n : a) {
            System.out.println(n);
            if (n == a[10]) {
                break;
            }
        }
        int[] copied = Arrays.copyOf(a, a.length);


    }
}
