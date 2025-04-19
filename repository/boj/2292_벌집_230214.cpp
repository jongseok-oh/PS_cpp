#include <iostream>

using namespace std;

int n;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	
	int i = 0;
	int start = 0, end = 1;
	while (true) {
		if (n >= start && n <= end)
		{
			cout << i + 1; return 0;
		}
		i++;
		start = end + 1;
		end += i * 6;
	}
}
