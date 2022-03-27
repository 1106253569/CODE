import java.util.ArrayList;
import java.util.InputMismatchException;
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

    public void showMenu() {
        foodList.showMenu();
    }

    /**
     * Added option
     */

    public void showAdded() {
        System.out.println("---------------------------\nSHOPPING CART");
        if (added == null || added.size() == 0)
            System.out.println("---------------------------\nCart is empty");
        else {
            for (var dishes : added) {
                System.out.println("---------------------------");
                System.out.println("name: " + dishes.getName() + "    \tnumber= " + dishes.getNumber() + "\nTotal price(of a single product)=" + dishes.getTotalPrice());
            }
            System.out.println("---------------------------");
            System.out.println("Total price=" + getTotal());
        }
        System.out.println("---------------------------");

    }

    public void add() {
        try {
            Scanner in = new Scanner(System.in);
            String i = "y";
            while (i.equals("Y") || i.equals("y")) {
                System.out.print("please enter dish's name: ");
                String dishName = in.next();
                System.out.print("please enter number: ");
                int dishNumber = in.nextInt();
                this.addOneToCart(dishName, dishNumber);
                System.out.print("Do you want to continue?(Y or N)");
                i = in.next();
            }
        } catch (InputMismatchException e) {
            System.out.println("Added fail, please enter right number or name!");
            System.out.print("Do you want to continue?(Y or N)");
            Scanner in = new Scanner(System.in);
            String i = in.next();
            if (i.equals("y") || i.equals("Y"))
                this.add();
        }
    }

    private double getTotal() {
        double total = 0.0;
        if (added != null)
            for (var one : added) {
                total += one.getPrice() * one.getNumber();
            }
        return total;
    }

    private void addOneToCart(String want, int n) {
        if (added == null)
            added = new ArrayList<>();
        boolean isExist = false;
        if (n > 0 && foodList.contains(want)) {
            for (var one : added) {
                if (want.equals(one.getName())) {
                    isExist = true;
                    Scanner in = new Scanner(System.in);
                    System.out.print("<" + want + "> is exist\n 1.Add up or 2.Overwrite, please enter: ");
                    String i;
                    do {
                        i = in.next();
                        if (i.equals("1")) {
                            n += one.getNumber();
                            System.out.println("Add up success");
                        } else if (i.equals("2"))
                            System.out.println("Overwrite success");
                        else
                            System.out.print("please enter right choose\n 1.Add up or 2.Overwrite");
                    } while (!i.equals("1") && !i.equals("2"));
                    one.setNumber(n);
                }
            }
            //存在就不再添加新的项
            if (!isExist)
                added.add(new AddDishes(foodList.DishesInformation(want), n));
        } else {
            System.out.println("Added fail, please enter right number or dishes!");
        }
    }


    /**
     * Menu option
     */

    public void emptyCart() {
        if (added.isEmpty()) {
            System.out.println("Your cart is empty!");
            return;
        }
        System.out.print("Are you sure you want to empty the cart?(Y or N)");
        Scanner in = new Scanner(System.in);
        String i = in.next();
        if (i.equals("Y") || i.equals("y")) {
            added.clear();
            System.out.println("Success");
        } else {
            System.out.println("Clear fail! Please try again.");
        }
        this.showAdded();
    }

    public void addMenu() {
        try {
            String i = "Y";
            Scanner in = new Scanner(System.in);
            while (Objects.equals(i, "Y") || Objects.equals(i, "y")) {
                System.out.print("please enter dish's name: ");
                String dishName = in.next();
                System.out.print("please enter dish's price: ");
                double dishPrice = in.nextDouble();
                foodList.add(new Dishes(dishName, dishPrice));
                System.out.print("Do you want to continue?(Y or N)");
                i = in.next();
            }
        } catch (InputMismatchException e) {
            System.out.println("Added fail, please enter right number or dishes!");
            System.out.print("Do you want to continue?(Y or N)");
            Scanner in = new Scanner(System.in);
            String i = in.next();
            if (i.equals("y") || i.equals("Y"))
                this.addMenu();
        }
    }

    public void setPrice() {
        try {
            String i = "Y";
            while (Objects.equals(i, "Y") || Objects.equals(i, "y")) {
                Scanner in = new Scanner(System.in);
                System.out.print("Enter the name of the dish you want to set the price for: ");
                String dishName = in.next();
                System.out.print("Please enter price: ");
                double dishPrice = in.nextDouble();
                foodList.setPrice(dishName, dishPrice);
                System.out.print("Do you want to continue?(Y or N)");
                i = in.next();
            }
        } catch (InputMismatchException e) {
            System.out.println("Added fail, please enter right number or name!");
            System.out.print("Do you want to continue?(Y or N)");
            Scanner in = new Scanner(System.in);
            String i = in.next();
            if (i.equals("y") || i.equals("Y"))
                this.addMenu();
        }
    }

    public void removeMenuDishes() {
        try {
            String i = "Y";
            Scanner in = new Scanner(System.in);
            while (Objects.equals(i, "Y") || Objects.equals(i, "y")) {
                System.out.print("please enter dish's name: ");
                String dishName = in.next();
                foodList.removeDishes(dishName);
                System.out.print("Do you want to continue?(Y or N)");
                i = in.next();
            }
        } catch (InputMismatchException e) {
            System.out.println("Added fail, please enter right dish's name!");
            System.out.print("Do you want to continue?(Y or N)");
            Scanner in = new Scanner(System.in);
            String i = in.next();
            if (i.equals("y") || i.equals("Y"))
                this.removeMenuDishes();
        }
    }
}


class AddDishes extends Dishes {
    private int number;

    public AddDishes(Dishes want, int i) {
        super(want.getName(), want.getPrice());
        setNumber(i);
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

    public void setNumber(int i) {
        number = i;
    }
}
