public class AddDishes extends Dishes implements Comparable<AddDishes> {
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

    @Override
    public int compareTo(AddDishes other) {
        if (this.getTotalPrice() > other.getTotalPrice())
            return 1;
        else
            return 0;
    }
}
