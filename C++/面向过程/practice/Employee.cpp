#include <iostream>

struct time
{
    int year = 0;
    int month = 0;
    int day = 0;
    time() = default;
    time(int y, int m, int d) : year(y), month(m), day(d) {}
};

class Employee
{
protected:
    int num;
    std::string name;
    time birth_month;
    float salary = 0.0;

public:
    Employee(int _num, std::string _name, int year, int month, int day)
        : num(_num), name(_name), birth_month(year, month, day) {}

    virtual int get_num() { return num; }
    virtual std::string get_name() { return name; }
    virtual void set_salary()
    {
        float x;
        std::cout << "please enter salary: ";
        std::cin >> x;
        salary = x;
    }
    virtual float get_salary(time t)
    {
        if (birth_month.day == t.day && birth_month.month == t.month &&
            birth_month.year == t.year)
            return salary + 100.0;
        else
            return salary;
    }
    void showInformation()
    {
        time date;
        std::cout << "please enter date: ";
        std::cin >> date.year >> date.month >> date.day;
        std::cout << "num=" << get_num() << '\n';
        std::cout << "name=" << get_name() << '\n';
        std::cout << "salary=" << get_salary(date) << '\n';
    }
};

class HourlyEmployee : public Employee
{
private:
    float hourSalary;
    int workTime;

public:
    HourlyEmployee(int _num, std::string _name, int year, int month, int day, float _hourSalary, int _workTime)
        : Employee(_num, _name, year, month, day), hourSalary(_hourSalary), workTime(_workTime) { set_salary(); }
    void set_salary() { salary = hourSalary * workTime; }
};

class salesEmployee : public Employee
{
private:
    float totalSales;
    double rate;

public:
    salesEmployee(int _num, std::string _name, int year, int month, int day, float _totalSales, double _rate)
        : Employee(_num, _name, year, month, day), totalSales(_totalSales), rate(_rate) { set_salary(); }
    void set_salary() { salary = totalSales * rate; }
};

int main()
{
    Employee *pt = NULL;
    Employee e(1, "Linlu", 2003, 6, 16);
    e.set_salary();
    pt = &e;
    pt->showInformation();
    HourlyEmployee e1(1, "Linlu", 2003, 6, 16, 5, 10);
    pt = &e1;
    pt->showInformation();
    salesEmployee e2(1, "Linlu", 2003, 6, 16, 3000, 0.1);
    pt = &e2;
    pt->showInformation();
    return 0;
}