#include <iostream>
#include <algorithm>

using namespace std;

int n, num;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int _max = -1e9, _min = 1e9;
	cin >> n;
	while (n--)
	{
		cin >> num;
		_max = max(num, _max);
		_min = min(num, _min);
	}
	cout << _min << " " << _max;
}
