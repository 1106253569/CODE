import java.util.ArrayList;
import java.util.Objects;
import java.util.Scanner;

public class ShoppingTest {
    public static void main(String[] args) {
        var m = new ArrayList<Dishes>();
        Scanner in = new Scanner(System.in);
        System.out.println("Please initialize a menu");
        String i = "Y";
        //初始化菜单
        while (Objects.equals(i, "Y") || Objects.equals(i, "y")) {
            System.out.print("please enter dish's name: ");
            String dishName = in.next();
            System.out.print("please enter dish's price: ");
            double dishPrice = in.nextInt();
            m.add(new Dishes(dishName, dishPrice));
            System.out.print("Do you want to continue?(Y or N)");
            i = in.next();
        }
        //初始化购物车
        var cart = new ShoppingCart(m);
        String close = "1";
        while (!close.equals("0")) {
            behavioralCues.selectMode();
            close = in.next();
            String choose = "1";
            switch (close) {
                case "1" -> {
                    while (!choose.equals("0")) {
                        behavioralCues.merchantActionTip();
                        choose = in.next();
                        merchantAction(cart, choose);
                    }
                }
                case "2" -> {
                    while (!choose.equals("0")) {
                        behavioralCues.clientActionTip();
                        choose = in.next();
                        clientAction(cart, choose);
                    }
                }
                default -> {
                    if (close.equals("0"))
                        System.out.println("System close!");
                    else
                        System.out.println("Please enter right word");
                }
            }
        }
    }

    private static void clientAction(ShoppingCart cart, String i) {
        switch (i) {
            case "1" -> {
                cart.showMenu();
                anyKeyToExit();
            }
            case "2" -> {
                cart.showAdded();
                anyKeyToExit();
            }
            case "3" -> {
                cart.add();
                anyKeyToExit();
            }
            case "4" -> {
                cart.emptyCart();
                anyKeyToExit();
            }
        }
    }

    private static void merchantAction(ShoppingCart cart, String i) {
        switch (i) {
            case "1" -> {
                cart.showMenu();
                anyKeyToExit();
            }
            case "2" -> {
                cart.addMenu();
                anyKeyToExit();
            }
        }
    }

    private static void anyKeyToExit() {
        Scanner in = new Scanner(System.in);
        System.out.print("Press anything to exit");
        in.next();
    }
}



