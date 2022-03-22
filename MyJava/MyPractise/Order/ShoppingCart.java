import java.util.ArrayList;

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
        if (added == null)
            System.out.println("Nothing");
        else
            for (var dishes : added) {
                System.out.println("name: " + dishes.getName() + "\tnumber= " + dishes.getNumber() + "\nTotal price(of a single product)=" + dishes.getTotalPrice());
            }
        System.out.println("Total price=" + getTotal());
    }

    public void add(String want, int n) {
        if (n > 0 && foodList.contains(want)) {
            added = new ArrayList<>();
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

class Menu {
    private final ArrayList<Dishes> menu;

    public Menu() {
        menu = new ArrayList<>();
    }

    public Menu(ArrayList<Dishes> m) {
        menu = new ArrayList<>();
        menu.addAll(m);
    }

    public void showMenu() {
        for (var m : menu) {
            System.out.println("name: " + m.getName() + "\tPrice=" + m.getPrice());
        }
    }

    public void add(Dishes d) {
        menu.add(d);
    }

    public boolean contains(String name) {
        for (var m : menu) {
            if (name.equals(m.getName()))
                return true;
        }
        return false;
    }

    public Dishes DishesInformation(String name) {
        for (var m : menu)
            if (name.equals(m.getName()))
                return m;
        return null;
    }
}