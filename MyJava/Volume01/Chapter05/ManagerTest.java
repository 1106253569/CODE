public class ManagerTest {
    public static void main(String[] args) {
        Manager boss = new Manager("MaYun", 1, 1978, 12, 12);
        Employee[] staff = new Employee[3];
        staff[0] = boss;
        staff[1] = new Employee("LiSi", 50000, 1988, 3, 6);
        staff[2] = new Employee("WangWu", 60000, 1968, 5, 8);
        boss.setBonus(500000000);
        for (Employee e : staff) {
            e.raiseSalary(5);
        }

        for (Employee e : staff) {
            System.out.println(e.toString());
        }
        if (staff[1].equals(staff[2])) {
            System.out.println("There are same name");
        } else {
            System.out.println("That no one people");
        }
    }
}

