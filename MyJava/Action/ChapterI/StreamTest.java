import java.util.ArrayList;
import java.util.List;

public class StreamTest {
    public static void main(String[] args) {
        var inventory = new ArrayList<Apple>();
        List<Apple> heavyApples =
                inventory.parallelStream().filter((Apple a) -> a.getWeight() > 150).toList();
        //parallelStream()可替换为stream()

    }
}
