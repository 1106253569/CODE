#include <iostream>
#include <vector>
using namespace std;
int main()
{
	vector<int> a{1, 2, 3, 4, 5};
	for (auto it = a.begin(); it != a.end();++it)
		cout << *it<< ' ' ;
	cout << endl;
	for (int i = 1; i <= 5;i++)
	{
		a.push_back(i);
	}
	cout << a.size() << endl;
	cout << a.capacity() << endl;
	cout << a.max_size() << endl;
	for (auto it = a.begin(); it != a.end();++it)
		cout << *it << ' ';
	return 0;
}