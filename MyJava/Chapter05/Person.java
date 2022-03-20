public abstract class Person {
    private final String name;

    public Person(String n) {
        name = n;
    }

    public String getName() {
        return name;
    }

    public abstract String getDescription();

    public abstract String toString();
}