import java.util.ArrayList;
import java.util.Objects;
import java.util.Scanner;

public class ShoppingCart {
    private final Menu foodList;
    private ArrayList<AddDishes> added;

    public ShoppingCart(ArrayList<Dishes> m) {
        added = null;
        if (m != null)
            foodList = new Menu(m);
        else
            foodList = new Menu();
    }

    public double getTotal() {
        double total = 0.0;
        if (added != null)
            for (var one : added) {
                total += one.getPrice() * one.getNumber();
            }
        return total;
    }

    public void ShowAdded() {
        System.out.println("---------------------------\nSHOPPING CART");
        if (added == null)
            System.out.println("---------------------------\nCart is empty");
        else {
            for (var dishes : added) {
                System.out.println("---------------------------");
                System.out.println("name: " + dishes.getName() + "\tnumber= " + dishes.getNumber() + "\nTotal price(of a single product)=" + dishes.getTotalPrice());
            }
            System.out.println("---------------------------");
            System.out.println("Total price=" + getTotal());
        }
        System.out.println("---------------------------");

    }

    public void add(String want, int n) {
        if (added == null)
            added = new ArrayList<>();
        if (n > 0 && foodList.contains(want)) {
            added.add(new AddDishes(foodList.DishesInformation(want), n));
        } else {
            System.out.println("Added fail, please enter right number or dishes!");
        }
    }

    public void addMenu(Dishes d) {
        foodList.add(d);
    }

    public void showMenu() {
        foodList.showMenu();
    }

    public void emptyCart() {
        System.out.print("Are you sure you want to empty the cart?(Y or N");
        Scanner in = new Scanner(System.in);
        String i = in.next();
        if (Objects.equals(i, "Y") || Objects.equals(i, "y")) {
            added.clear();
            System.out.println("Success");
        } else {
            System.out.println("Clear fail! Please try again.");
        }
    }
}


class AddDishes extends Dishes {
    private final int number;

    public AddDishes(Dishes want, int i) {
        super(want.getName(), want.getPrice());
        number = i;
    }

    public double getTotalPrice() {
        return super.getPrice() * number;
    }

    @Override
    public String getName() {
        return super.getName();
    }

    @Override
    //If you want to get the total price, use getTotalPrice()
    public double getPrice() {
        return super.getPrice();
    }

    public int getNumber() {
        return number;
    }
}
