import java.util.Scanner;

public class ioStream {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        System.out.print("What your name?");
        String name = in.nextLine();
        String firstName = in.next();
        System.out.print("How old are you?");
        int age = in.nextInt();
        System.out.println("Hello, " + firstName + name + ". Next year, you'll be " + (age + 1));
        /*!input password!
         *Console cons=System.console();
         *String username=cons.readLine("User name: ");
         *char[] passwd=cons.readPassword("Password: ");
         */
        double x = 10000.0 / 3.0;
        System.out.printf("Hello, %s. Next year, you'll be %d, x=%f", firstName + name, age, x);

    }
}