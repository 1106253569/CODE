import java.util.ArrayList;

public class Admin {
    private ArrayList<Player> playerList;
    private Player LandlordCard;

    public Admin() {
        var deck = new CardDeck();
        deck.shuffle();
        var playerList = new ArrayList<Player>();
        var group = new ArrayList<Card>();
        int i = 1;
        for (var card : deck.getDeck()) {
            group.add(card);
            if (group.size() == 17) {
                var player = new Player("Player" + i, group);
                playerList.add(player);
                group.clear();
                ++i;
            }
        }
        LandlordCard = new Player("LandlordCard", group);
        for (var a : playerList)
            a.showHand();
    }
}
