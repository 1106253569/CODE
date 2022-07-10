import java.util.ArrayList;
import java.util.Comparator;
import java.util.function.Function;

public class ComparingTest {
    ArrayList<Apple> inventory = new ArrayList<>();
    Comparator<Apple> c = Comparator.comparing(Apple::getWeight);
    Comparator<Apple> d = Comparator.comparing(Apple::getWeight).reversed().thenComparing(Apple::getColor);
    Function<Integer, Integer> f = x -> x + 1;
    Function<Integer, Integer> g = x -> x * 2;
    Function<Integer, Integer> h = f.andThen(g);
    int result = h.apply(1);
    Function<String, String> addHeader = Letter::addHeader;
    Function<String, String> transformationPipeline =
            addHeader.andThen(Letter::checkSpelling).andThen(Letter::addFooter);
}

class Letter {
    public static String addHeader(String text) {
        return "From Raoul,Mario and Alan: " + text;
    }

    public static String addFooter(String text) {
        return text + " Kind regards";
    }

    public static String checkSpelling(String text) {
        return text.replaceAll("labda", "lambda");
    }
}

