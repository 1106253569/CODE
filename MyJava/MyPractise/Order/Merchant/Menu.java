import java.util.ArrayList;
import java.util.Objects;
import java.util.Scanner;

public class Menu {
    private final ArrayList<Dishes> menu;

    public Menu() {
        menu = new ArrayList<>();
    }

    public Menu(ArrayList<Dishes> m) {
        menu = new ArrayList<>();
        menu.addAll(m);
    }

    public void showMenu() {
        System.out.println("---------------------------\nMENU");
        if (menu == null)
            System.out.println("---------------------------\nMenu is Empty");
        else
            for (var m : menu) {
                System.out.println("---------------------------");
                System.out.println("name: " + m.getName() + "\tPrice=" + m.getPrice());
            }
        System.out.println("---------------------------");
    }

    public void add(Dishes d) {
        if (d.getName().length() == 0) {
            System.out.println("uname, please retry!");
            return;
        }
        if (!contains(d.getName()))
            menu.add(d);
        else {
            System.out.println("<" + d.getName() + "> already exists, do you want to overwrite the original information?(Y or N) ");
            Scanner in = new Scanner(System.in);
            String i = in.next();
            if (Objects.equals(i, "Y") || Objects.equals(i, "y")) {
                ModifyPrice(d.getName(), d.getPrice());
                System.out.println("Success");
            } else {
                System.out.println("Added fail! Please try again.");
            }
        }
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

    public void removeDishes(String name) {
        if (!contains(name))
            System.out.println("<" + name + "> no exist, remove failed");
        else {
            menu.removeIf(m -> m.getName().equals(name));
            System.out.println("<" + name + "> remove success!");
        }
    }

    public void setPrice(String name, double price) {
        if (!contains(name)) {
            System.out.println("<" + name + "> no exist, change failed");
        } else {
            ModifyPrice(name, price);
            System.out.println("Change success");
        }
    }

    private void ModifyPrice(String name, double price) {
        for (var m : menu) {
            if (name.equals(m.getName()))
                m.setPrice(price);
        }
    }
}


