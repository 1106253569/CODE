import java.util.*;
import java.util.stream.Collectors;
import java.util.stream.Stream;

import static java.util.stream.Collectors.groupingBy;


public class StreamTest {
    public static void main(String[] args) {
        var inventory = new ArrayList<Apple>();
        List<Apple> heavyApples =
                inventory.parallelStream().filter((Apple a) -> a.getWeight() > 150).toList();
        //parallelStream()可替换为stream()
        List<Dish> lowCaloricDishes = new ArrayList<>();
        List<Dish> menu = new ArrayList<>();
        for (Dish d : menu) {
            if (d.getCalories() < 400)
                lowCaloricDishes.add(d);
        }
        lowCaloricDishes.sort((o1, o2) -> Integer.compare(o1.getCalories(), o2.getCalories()));
        List<String> lowCaloricDishesName1 = new ArrayList<>();
        for (Dish d : lowCaloricDishes) {
            lowCaloricDishesName1.add(d.getName());
        }
        List<String> lowCaloricDishesName2 = menu.stream()
                .filter(d -> d.getCalories() < 400)
                .sorted(Comparator.comparing(Dish::getCalories))
                .map(Dish::getName)
                .toList();
        Map<Dish.Type, List<Dish>> dishesByType = menu.stream().collect(groupingBy(Dish::getType));
        List<String> threeHighCaloricDishNames =
                menu.stream()
                        .filter(d -> d.getCalories() > 300).map(Dish::getName).limit(3).collect(Collectors.toList());
        System.out.println(threeHighCaloricDishNames);

        List<String> title = Arrays.asList("Java8", "In", "Action");
        Stream<String> s = title.stream();
        //流只可消费一次
        s.forEach(System.out::println);


        List<String> names = new ArrayList<>();
        //利用for-each外部迭代
        for (Dish d : menu)
            names.add(d.getName());

        //利用迭代器外部迭代
        Iterator<Dish> iterator = (Iterator<Dish>) menu.iterator();
        while (iterator.hasNext()) {
            Dish d = iterator.next();
            names.add(d.getName());
        }

        //利用stream内部迭代
        List<String> name1 = menu.stream().map(Dish::getName).toList();
    }
}

