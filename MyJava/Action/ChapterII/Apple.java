public class Apple {
    String color;
    double weight;

    Apple(String c, double w) {
        color = c;
        weight = w;
    }

    public static boolean isGreenApple(Apple apple) {
        return "green".equals(apple.getColor());
    }

    public static boolean isHeavyApple(Apple apple) {
        return apple.getWeight() > 150;
    }

    public String getColor() {
        return color;
    }

    public double getWeight() {
        return weight;
    }
}
