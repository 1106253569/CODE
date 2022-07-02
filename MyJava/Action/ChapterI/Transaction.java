public class Transaction {
    double price;
    String currency;

    Transaction(double p) {
        price = p;
    }

    public double getPrice() {
        return price;
    }

    public String getCurrency() {
        return currency;
    }
}
