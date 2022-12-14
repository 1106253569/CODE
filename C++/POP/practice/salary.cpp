#include <iostream>
using namespace std;
double getEarning(double salary, int absenceDays, int overtime)
{
    return salary - ((absenceDays - overtime) * salary) / 22;
}
double getEarning(double baseSalary, double salesSum, double minSales, double rate)
{
    if (salesSum > minSales)
        return baseSalary + (salesSum - minSales) * rate;
    else
        return baseSalary;
}
double getEarning(int workPieces, double wagePerPiece)
{
    return workPieces * wagePerPiece;
}
double getEarning(double hours, double wagePerHour)
{
    return hours * wagePerHour;
}
int main()
{
    cout << "Please select..." << endl;
    cout << "1: Manager." << endl;
    cout << "2: Sales Man." << endl;
    cout << "3: Pieces Worker." << endl;
    cout << "4: Hour-Worker." << endl;
    cout << "Others: Quit" << endl;
    int sel = 0;
    cin >> sel;
    switch (sel)
    {
    case 1:
        double salary;
        int sbsenceDays;
        cin >> salary;
        cin >> sbsenceDays;
        cout << getEarning(salary, sbsenceDays);
        cout << endl;
        break;
    case 2:
        double baseSalary, salesSum, minSales, rate;
        cin >> baseSalary;
        cin >> salesSum;
        cin >> minSales;
        cin >> rate;
        cout << getEarning(baseSalary, salesSum, minSales,rate);
        cout << endl;
        break;
    case 3:
        int workPieces;
        double wagePerPiece;
        cin >> workPieces;
        cin >> wagePerPiece;
        cout << getEarning(workPieces, wagePerPiece);
        cout << endl;
        break;
    case 4:
        double hours, wagePerHour;
        cin >> hours;
        cin >> wagePerHour;
        cout << getEarning(hours, wagePerHour);
        cout << endl;
        break;
    default:
        break;
    }
}
