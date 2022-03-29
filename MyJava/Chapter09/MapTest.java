import java.util.EnumMap;
import java.util.EnumSet;
import java.util.HashMap;
import java.util.Map;

public class MapTest {
    public static void main(String[] args) {
        var staff = new HashMap<String, Employee>();
        staff.put("1", new Employee("Amy"));
        staff.put("2", new Employee("Hack"));
        staff.put("3", new Employee("Gary"));
        staff.put("4", new Employee("Cruz"));

        System.out.println(staff);

        staff.remove("2");

        staff.put("5", new Employee("Miller"));

        System.out.println(staff.get("5"));

        staff.forEach((k, v) ->
                System.out.println("key= " + k + ", value= " + v));

        for (var entry : staff.entrySet()) {
            System.out.println(entry.getKey());
            System.out.println(entry.getValue());
        }

        EnumSet<Weekday> always = EnumSet.allOf(Weekday.class);
        EnumSet<Weekday> never = EnumSet.noneOf(Weekday.class);
        EnumSet<Weekday> workday = EnumSet.range(Weekday.Monday, Weekday.Friday);
        EnumSet<Weekday> mwf = EnumSet.of(Weekday.Monday, Weekday.Wednesday, Weekday.Friday);
        var personInCharge = new EnumMap<Weekday, Employee>(Weekday.class);

        var dish = Map.entry("water", 9.0);
    }

    enum Weekday {Monday, Tuesday, Wednesday, Thursday, Friday, Saturday, Sunday}
}
