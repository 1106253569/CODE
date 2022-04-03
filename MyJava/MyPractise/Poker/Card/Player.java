import java.util.ArrayList;

public class Player {
    private String name;
    private ArrayList<Card> hand;
    private String identity = "farmer";

    public Player(String n, ArrayList<Card> c) {
        hand = c;
        name = n;
    }

    public void showHand() {
        this.sortHand();
        System.out.println(name + "'s hand: ");
        for (var h : hand)
            System.out.print(h.toString());
        System.out.println();
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

    public void sortHand() {
        hand.sort(Card::compareTo);
    }

};
