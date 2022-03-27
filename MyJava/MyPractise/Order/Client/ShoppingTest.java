import java.util.ArrayList;
import java.util.Scanner;

public class ShoppingTest {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        //初始化菜单
        var list = new ArrayList<Dishes>();
        list.add(new Dishes("table fee", 2));
        list.add(new Dishes("egg", 3));
        list.add(new Dishes("water", 1.5));
        list.add(new Dishes("meat", 10));
        list.add(new Dishes("vegetable", 6));
        list.add(new Dishes("paper", 1));
        //初始化购物车
        var cart = new ShoppingCart(list);
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
            case "3" -> {
                cart.setPrice();
                anyKeyToExit();
            }
            case "4" -> {
                cart.removeMenuDishes();
                anyKeyToExit();
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


    private static void anyKeyToExit() {
        Scanner in = new Scanner(System.in);
        System.out.print("Enter '0' to exit");
        in.next();
    }
}



