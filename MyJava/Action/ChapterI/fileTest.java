import java.io.File;
import java.util.ArrayList;
import java.util.List;

public class fileTest {
    File[] hiddenFile1 = new File(".").listFiles(file -> file.isHidden());
    File[] hiddenFile2 = new File(".").listFiles(File::isHidden);

    public static List<Apple> filterGreenApples(List<Apple> inventory) {
        List<Apple> result = new ArrayList<>();
        for (Apple apple : inventory) {
            if ("green".equals(apple.getColor()))
                result.add(apple);
        }
        return result;
    }

    public static List<Apple> filterHeavyApples(List<Apple> inventory) {
        List<Apple> result = new ArrayList<>();
        for (Apple apple : inventory) {
            if (apple.getWeight() > 150)
                result.add(apple);
        }
        return result;
    }

    public interface Predicate<T> {
        boolean test(T t);
    }
}
