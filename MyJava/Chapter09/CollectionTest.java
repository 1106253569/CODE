import java.util.HashMap;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.Map;

public class CollectionTest {
    public static void main(String[] args) {
        var staff1 = new LinkedList<String>();
        staff1.add("Amy");
        staff1.add("Bob");
        staff1.add("Carl");
        Iterator<String> Iter = staff1.iterator();
        String first = Iter.next();
        String second = Iter.next();
        Iter.remove();
        var staff2 = new HashMap<String, Employee>();
        var Harry = new Employee("Harry", 1, 1, 1, 1);
        staff2.put("999", Harry);
        var id = "999";
        Employee e = staff2.get(id);
        Map<String, Integer> scores = null;
        assert false;
        int score = scores.getOrDefault(id, 0);
    }
}
