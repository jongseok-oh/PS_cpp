#include <iostream>

using namespace std;

int year;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> year;
	cout << ((!(year % 4) && (year % 100)) || !(year % 400));
}