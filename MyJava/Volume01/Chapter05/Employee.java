import java.time.LocalDate;

public class Employee extends Person implements Comparable<Employee> {
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

    public Employee(String n) {
        super(n);
        salary = 0;
        id = nextId;
        nextId++;
        hireDay = LocalDate.of(2000, 1, 1);
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

    @Override
    //接口
    public int compareTo(Employee other) {
        return Double.compare(salary, other.salary);
    }


}


