import java.util.ArrayList;
import java.util.Objects;
import java.util.Scanner;

public class ShoppingTest {
    public static void main(String[] args) {
        var m = new ArrayList<Dishes>();
        Scanner in = new Scanner(System.in);
        String i = "Y";
        while (Objects.equals(i, "Y") || Objects.equals(i, "y")) {
            System.out.print("please enter dish's name: ");
            String dishName = in.next();
            System.out.print("please enter dish's price: ");
            double dishPrice = in.nextInt();
            m.add(new Dishes(dishName, dishPrice));
            System.out.print("Do you want to continue?(Y or N)");
            i = in.next();
        }
        var cart = new ShoppingCart(m);
        cart.addMenu(new Dishes("egg", 5));
        cart.showMenu();
        System.out.println("Please select the food you want!");
        i = "Y";
        while (Objects.equals(i, "Y") || Objects.equals(i, "y")) {
            System.out.print("please enter dish's name: ");
            String dishName = in.next();
            System.out.print("please enter number: ");
            int dishNumber = in.nextInt();
            cart.add(dishName, dishNumber);
            System.out.print("Do you want to continue?(Y or N)");
            i = in.next();
        }
        cart.ShowAdded();
        cart.emptyCart();
    }
}
