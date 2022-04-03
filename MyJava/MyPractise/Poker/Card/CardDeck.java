import java.util.ArrayList;
import java.util.Collections;

public class CardDeck {
    private ArrayList<Card> deck;

    public CardDeck() {
        //梅花(Club)为C，方块(Diamond)为D，红心(Hearts)为H，黑桃(Spade)为S
        //大王代表太阳、小王代表月亮
        deck = new ArrayList<>();
        deck.add(new Card("Joker", "Sun", 20));
        deck.add(new Card("Joker", "Moon", 20));

        String[] color = {"C", "D", "H", "S"};
        String[] numberName = {"3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A", "2"};
        for (int i = 0; i < numberName.length; i++)
            for (var c : color)
                deck.add(new Card(c, numberName[i], i));
    }

    public void shuffle() {
        Collections.shuffle(deck);
    }

    public ArrayList<Card> getDeck() {
        return deck;
    }


}
