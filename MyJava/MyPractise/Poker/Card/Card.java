import java.util.HashMap;
import java.util.Map;

public class Card
        implements Comparable<Card> {
    private final String color;
    private final String numberName;
    private final Map<String, Integer> number;

    public Card(String c, String n, int i) {
        color = c;
        numberName = n;
        number = new HashMap<>();
        number.put(numberName, i);
    }

    public String getColor() {
        return color;
    }

    public String toString() {
        return "[" + color + numberName + "] ";
    }

    public int getNumber() {
        return number.get(numberName);
    }

    public int compareTo(Card other) {
        if (this.getNumber() > other.getNumber())
            return 1;
        else
            return -1;
    }

}
