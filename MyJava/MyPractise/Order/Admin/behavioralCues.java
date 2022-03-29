public class behavioralCues {
    public static void selectMode() {
        System.out.println("---------------------------");
        System.out.println("Please select mode or exit");
        System.out.println("0.exit");
        System.out.println("1.Merchant");
        System.out.println("2.Client");
        System.out.println("---------------------------");
    }

    public static void merchantActionTip() {
        System.out.println("---------------------------");
        System.out.println("Please select a merchant action");
        System.out.println("0.Back to select mode");
        System.out.println("1.Show menu");
        System.out.println("2.Add a dishes or a list");
        System.out.println("3.Set dish's price");
        System.out.println("4.Delete what you don't want");
        System.out.println("---------------------------");
    }

    public static void clientActionTip() {
        System.out.println("---------------------------");
        System.out.println("Please select a customer action");
        System.out.println("0.Back to select mode");
        System.out.println("1.Show menu");
        System.out.println("2.Show added");
        System.out.println("3.Show added(Ascending)");
        System.out.println("4.Show added(Descending)");
        System.out.println("5.Add dishes to cart");
        System.out.println("6.Empty cart");
        System.out.println("7.Delete what you don't want");
        System.out.println("---------------------------");
    }
}