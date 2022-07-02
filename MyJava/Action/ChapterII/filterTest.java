import java.util.ArrayList;
import java.util.List;

public class filterTest {
    private List<Apple> inventory;
    List<Apple> redApples1 = filterApples(inventory, apple -> "red".equals(apple.getColor()));
    /*
    // 匿名类写法
    List<Apple> redApples = filterApples(inventory, new ApplePredicate() {
        public boolean test(Apple apple) {
            return "red".equals(apple.getColor());
        }
    });
    */

    List<Apple> redApples2 = filter(inventory, (Apple apple) -> "red".equals(apple.getColor()));

    public static <T> List<T> filter(List<T> list, Predicate<T> p) {
        List<T> result = new ArrayList<>();
        for (T e : list) {
            if (p.test(e))
                result.add(e);
        }
        return result;
    }

    public static List<Apple> filterApples(List<Apple> inventory, ApplePredicate p) {
        List<Apple> result = new ArrayList<>();
        for (Apple apple : inventory) {
            if (p.test(apple))
                result.add(apple);
        }
        return result;
    }

    public static void prettyPrintApple(List<Apple> inventory, AppleFormatter p) {
        for (Apple apple : inventory) {
            String output = p.toString(apple);
            System.out.println(output);
        }
    }

    public interface Predicate<T> {
        boolean test(T t);
    }

    public interface ApplePredicate {
        boolean test(Apple apple);
    }

    public interface AppleFormatter {
        String toString(Apple apple);
    }

    public class AppleHeavyWeightPredicate implements ApplePredicate {
        public boolean test(Apple apple) {
            return apple.getWeight() > 150;
        }
    }

    public class AppleGreenColorPredicate implements ApplePredicate {
        public boolean test(Apple apple) {
            return "green".equals(apple.getColor());
        }
    }

    public class MakeWeightToString implements AppleFormatter {
        public String toString(Apple apple) {
            return String.valueOf(apple.getWeight());
        }
    }

    public class MakeWeightAndHeavyToString implements AppleFormatter {
        public String toString(Apple apple) {
            String result = String.valueOf(apple.getWeight());
            if (apple.getWeight() > 150)
                result = result + "\t" + "Heavy";
            else
                result = result + "\t" + "light";
            return result;
        }
    }
}
