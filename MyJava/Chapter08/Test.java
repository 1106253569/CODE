public class Test {
    public static void main(String[] args) {
        var thread = new Thread(Task.asRunnable(() -> {
            Thread.sleep(1000);
            System.out.println("Hello world!");
            throw new Exception("Check this out!");
        }));
        thread.start();
    }
}
