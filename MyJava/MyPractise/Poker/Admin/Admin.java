import java.util.ArrayList;
import java.util.Scanner;

public class Admin {
    private ArrayList<Player> playerList;
    private final Player LandlordCard;

    public Admin() {
        var deck = new CardDeck();
        deck.shuffle();
        playerList = new ArrayList<Player>();
        int i = 1;
        ArrayList<Card> group = new ArrayList<>();
        for (var card : deck.getDeck()) {
            group.add(card);
            if (group.size() == 17) {
                var player = new Player("Player" + i, group);
                playerList.add(player);
                group = new ArrayList<>();
                ++i;
            }
        }
        LandlordCard = new Player("LandlordCard", group);
        for (var a : playerList)
            a.showHand();
    }

    private int callLandlord() {
        Scanner in = new Scanner(System.in);
        System.out.print("Call the landlord? ");
        int i = in.nextInt();
        System.out.println("---------------------------");
        return i;
    }

    public void distributeLandlordRow() {
        int winner = callLandlord();
        var landLordHand = playerList.get(winner).getHand();
        landLordHand.addAll(LandlordCard.getHand());
        var landLord = new Player(playerList.get(winner).getName(), "Landlord", landLordHand);
        playerList.set(winner, landLord);
    }

    public void showAllPlayerHand() {
        for (var player : playerList) {
            player.showHand();
        }
    }


}
