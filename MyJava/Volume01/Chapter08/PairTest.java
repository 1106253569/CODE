public class PairTest {
    public static void main(String[] args) {
        var ceo = new Manager("MaYun", 80000000, 2003, 12, 15);
        var cfo = new Manager("LeiJun", 600000000, 2004, 12, 13);
        var buddies = new Pair<Manager>(ceo, cfo);
        printBuddies(buddies);

        ceo.setBonus(10000);
        cfo.setBonus(15000);
        Manager[] managers = {ceo, cfo};

        var result = new Pair<Employee>();
        minMaxBonus(managers, result);
        System.out.println("first: " + result.getFirst().getName() + ", second: " + result.getSecond().getName());
        maxMinBonus(managers, result);
        System.out.println("first: " + result.getFirst().getName() + ", second: " + result.getSecond().getName());
    }

    public static void printBuddies(Pair<? extends Employee> p) {
        Employee first = p.getFirst();
        Employee second = p.getSecond();
        System.out.println(first.getName() + " and " + second.getName() + " are buddies.");
    }

    public static void minMaxBonus(Manager[] a, Pair<? super Manager> result) {
        if (a.length == 0)
            return;
        Manager min = a[0];
        Manager max = a[0];
        for (int i = 1; i < a.length; i++) {
            if (min.getBonus() > a[i].getBonus())
                min = a[i];
            if (min.getBonus() < a[i].getBonus())
                max = a[i];
        }
        result.setFirst(min);
        result.setSecond(max);
    }

    public static void maxMinBonus(Manager[] a, Pair<? super Manager> result) {
        minMaxBonus(a, result);
        PairAlg.swapHelper(result);
    }

}

class PairAlg {
    public static boolean hasNulls(Pair<?> p) {
        return p.getFirst() == null || p.getSecond() == null;
    }

    public static <T> void swapHelper(Pair<T> p) {
        T t = p.getFirst();
        p.setFirst(p.getSecond());
        p.setSecond(t);
    }

    public static void swap(Pair<?> p) {
        swapHelper(p);
    }
}

