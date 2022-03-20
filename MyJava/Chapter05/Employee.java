import java.time.LocalDate;

public class Employee extends Person {
    private static int nextId = 1;
    private final int id;
    private final LocalDate hireDay;
    private double salary;


    public Employee(String n, double s, int year, int month, int day) {
        super(n);
        salary = s;
        id = nextId;
        nextId++;
        hireDay = LocalDate.of(year, month, day);
    }

    public int getId() {
        return id;
    }

    public String getName() {
        return super.getName();
    }

    public double getSalary() {
        return salary;
    }

    public LocalDate getHireDay() {
        return hireDay;
    }

    @Override
    public String getDescription() {
        return "Employee";
    }

    @Override
    public String toString() {
        return "[id=" + getId() + ",name=" + getName() + ",salary=" + getSalary() + ",Date=" + getHireDay() + "]";
    }

    public void raiseSalary(double byPercent) {
        double raise = salary * byPercent / 100;
        salary += raise;
    }

    public boolean equals(Employee other) {
        return getName().equals(other.getName());
    }
}
