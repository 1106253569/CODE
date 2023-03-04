public class RunTest {
    static Equip[] equipList = new Equip[]{new Computer(100, 400), new Desk(50, 100), new Switchboard(10, 500)};

    public static void main(String[] args) {
        double sum = 0;
        for (Equip i : equipList) {
            System.out.println(i.toString());
            sum += i.getAmount() * i.getPrice();
        }
        System.out.println("总价为: " + sum);
    }
}

class Computer extends Equip {
    double price;

    public Computer(int a, double p) {
        super(a);
        price = p;
    }

    @Override
    public boolean isDamage() {
        return false;
    }

    @Override
    public double getPrice() {
        return price;
    }

    @Override
    public String toString() {
        return "Computer:" + "account=" + getAmount() + "  price=" + getPrice();
    }
}

class Desk extends Equip {
    double price;

    public Desk(int a, double p) {
        super(a);
        price = p;

    }

    @Override
    public boolean isDamage() {
        return false;
    }

    @Override
    public double getPrice() {
        return price;
    }

    @Override
    public String toString() {
        return "Desk:" + "account=" + getAmount() + "  price=" + getPrice();
    }
}

class Switchboard extends Equip {
    double price;

    public Switchboard(int a, double p) {
        super(a);
        price = p;
    }

    @Override
    public boolean isDamage() {
        return false;
    }

    @Override
    public double getPrice() {
        return price;
    }

    @Override
    public String toString() {
        return "Switchboard:" + "account=" + getAmount() + "  price=" + getPrice();
    }
}

