public class ClassCreate {
    public static void main(String[] args) {
        Employee[] staff = new Employee[3];

        staff[0] = new Employee("ZhangSan", 75000, 1987, 12, 15);
        staff[1] = new Employee("LiSi", 50000, 1988, 3, 6);
        staff[2] = new Employee("WangWu", 60000, 1968, 5, 8);

        for (Employee e : staff) {
            e.raiseSalary(5);
        }

        for (Employee e : staff) {
            System.out.println("id=" + e.getId() + ",name=" + e.getName() + ",salary=" + e.getSalary() + ",Date=" + e.getHireDay()+",He is a "+ e.getDescription());
        }
        if (staff[1].equals(staff[2])) {
            System.out.println("There are same name");
        } else {
            System.out.println("That no one people");
        }
    }
}
