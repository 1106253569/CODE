import java.util.ArrayList;

public class Player {
    private final String name;
    private ArrayList<Card> hand;
    private String identity;

    public Player(String n, ArrayList<Card> c) {
        hand = c;
        name = n;
        setIdentity("Farmer");
    }

    public Player(String n, String identity, ArrayList<Card> c) {
        hand = c;
        name = n;
        setIdentity(identity);
    }

    public void showHand() {
        this.sortHand();
        System.out.println("<" + getIdentity() + ">" + name + "'s hand: ");
        System.out.println("Remainder=" + getRemainder());
        for (var h : hand)
            System.out.print(h.toString());
        System.out.println();
        System.out.println("---------------------------");
    }

    public ArrayList<Card> getHand() {
        return hand;
    }

    public String getName() {
        return name;
    }

    public String getIdentity() {
        return identity;
    }

    public void setIdentity(String s) {
        identity = s;
    }

    public int getRemainder() {
        return hand.size();
    }

    public void sortHand() {
        hand.sort(Card::compareTo);
    }

}
