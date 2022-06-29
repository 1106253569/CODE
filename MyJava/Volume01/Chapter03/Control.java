import java.util.Scanner;

public class Control {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        System.out.println("a=");
        int a = in.nextInt();
        System.out.println("b=");
        int b = in.nextInt();
        if (a < b) {
            System.out.println("a<b");
        } else if (a > b) {
            System.out.println("a>b");
        } else {
            System.out.println("a=b");
        }
        int i = 0;
        System.out.println("when will you stop?");
        int j = in.nextInt();
        while (i < j) {
            System.out.println("h".repeat(i + 1));
            ++i;
        }
        for (int i1 = 0; i1 < 10; i1++) {
            System.out.println("h".repeat(i1 + 1));
            if (i1 == 6) {
                break;
            }
        }

    }
}