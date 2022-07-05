import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class interfaceTest {
    Predicate<String> nonEmptyStringPredicate = (String s) -> !s.isEmpty();
    List<Integer> l = map(Arrays.asList("lambdas", "in", "action"),
            (String s) -> s.length());
    //原始类型特化
    IntPredicate evenNumbers = (int i) -> i % 2 == 0;
    //evenNumbers.test(1000);
    Predicate<Integer> oddNumbers = (Integer i) -> i % 2 == i;
    private List<String> listOfStrings;
    List<String> nonEmpty = filter(listOfStrings, nonEmptyStringPredicate);

    public static <T> List<T> filter(List<T> list, Predicate<T> p) {
        List<T> result = new ArrayList<>();
        for (T s : list) {
            if (p.test(s))
                result.add(s);
        }
        return result;
    }

    public static <T> void forEach(List<T> list, Consumer<T> c) {
        for (T i : list)
            c.accept(i);
    }

    public static <T, R> List<R> map(List<T> list,
                                     Function<T, R> f) {
        List<R> result = new ArrayList<>();
        for (T s : list)
            result.add(f.apply(s));
        return result;
    }

    public static void main(String[] args) {
        forEach(Arrays.asList(1, 2, 3, 4, 5),
                (Integer i) -> System.out.print(i));
    }

    @FunctionalInterface
    public interface Predicate<T> {
        //筛选
        boolean test(T t);
    }

    @FunctionalInterface
    public interface Consumer<T> {
        //访问并操作
        void accept(T t);
    }

    @FunctionalInterface
    public interface Function<T, R> {
        //获取T的某些R类型的参数
        R apply(T t);
    }

    public interface IntPredicate {
        boolean test(int t);
    }
    //oddNumbers.test(1000)
}