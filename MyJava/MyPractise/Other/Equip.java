public abstract class Equip {
    int amount = 0;

    public Equip(int a) {
        amount = a;
    }

    public int getAmount() {
        return amount;
    }

    public abstract boolean isDamage();

    public abstract double getPrice();

    public abstract String toString();
}
