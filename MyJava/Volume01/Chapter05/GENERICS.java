import java.util.ArrayList;

public class GENERICS {

    public static void main(String[] args) {
        /*Scanner in = new Scanner(System.in);
        System.out.println("How long do you want to create?");
        int actualSize = in.nextInt();
        var staff = new Employee[actualSize];*/
        //ArrayList<Employee> staff=new ArrayList<Employee>();
        var staff = new ArrayList<Employee>();
        staff.ensureCapacity(100);
        for (int i = 1; i < 100; i++)
            staff.add(new Employee("LiSi", 50000, 1988, 3, 6));
        System.out.println(staff.size());
        staff.set(3, new Employee("WangWu", 60000, 1968, 5, 8));
        var list = new ArrayList<Integer>();
        list.add(2);
        Integer n = 1;
        Double x = 2.0;
        System.out.println(true ? n : x);
        Size S = Enum.valueOf(Size.class, "Small");
        System.out.println(S);
    }

    public enum Size {
        Small("S"), Medium("M"), Large("L");

        private final String abbreviation;

        private Size(String abbreviation) {
            this.abbreviation = abbreviation;
        }

        public String getAbbreviation() {
            return abbreviation;
        }

    }
}