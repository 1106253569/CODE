public class ThreadTest {
    public static final int DELAT = 10;
    public static final int STEPS = 100;
    public static final double MAX_AMOUNT = 1000;

    public static void main(String[] args) {
        var bank = new Bank(4, 1000);
        Runnable task = () -> {
            try {
                for (int i = 0; i < STEPS; i++) {
                    double amount = MAX_AMOUNT * Math.random();
                    bank.transfer(i % 2, (i + 2) % 3, amount);
                    Thread.sleep((int) (DELAT * Math.random()));
                }
            } catch (InterruptedException e) {

            }
        };
        for (int i = 0; i < 100; i++) {
            new Thread(task).start();
        }
    }

}
