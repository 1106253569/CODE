#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
struct student
{
    string name;
    int num;
} ;
int main()
{
    void input(student &x);
    void print(student * x);
    student *sort(student a[],int n);
    student std[50];
    student *f;
    f = std;
    int n;
    cout << "please enter number:";
    cin >> n;
    if(n>50)
        n = 50;
    for (int i=1; i <= n;i++)
        input(std[i]);
    f=sort(std,n);
    for (int i=1; i <= n;i++)
            print((f+i));        
}

void input(student &x)
{
    cin >> x.name >> x.num;
}
    
void print(student *x)
{
    cout << setfill('#') << setw(12) << x->name;
    cout << setfill('#') << setw(12) << x->num;
    cout << endl;
}

student *sort(student a[],int n)
{
    void print(student * x);
    for (int i = 0; i < n;i++)
    {
        for (int j = i; j < n;j++)
        if(a[i].name>a[j].name)
        {
            student temp;
            temp = a[i];
            a[i]=a[j];
            a[j] = temp;
        }
    }
    return (a);
}
        

