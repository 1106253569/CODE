public class REFLECTION {
    public static void main(String[] args) {
        var e = new Employee("LiSi", 50000, 1988, 3, 6);
    }

    public static void doSomethingWithClass(String name)
            throws ReflectiveOperationException {
        Class cl = Class.forName(name);
        if (cl == Employee.class) {
            System.out.println(cl.getName());
        }
    }
}
