public class Dishes {
    private final String name;
    private double price;

    public Dishes(String n, double p) {
        name = n;
        setPrice(p);
    }

    public double getPrice() {
        return price;
    }

    public void setPrice(double p) {
        price = p;
    }

    public String getName() {
        return name;
    }
}


