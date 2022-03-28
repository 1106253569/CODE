public class QueueTest {
    public static void main(String[] args) {
        Queue<Employee> expressLane1 = new CircularArrayQueue<>(100);
        expressLane1.add(new Employee("a", 100, 1, 1, 1));
        Queue<Employee> expressLane2 = new LinkedListQueue<>();
        expressLane2.add(new Employee("a", 100, 1, 1, 1));
    }
}
