#include <iostream>

using namespace std;

int n;

int nums[10001];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	int num;
	for (int i = 0; i < n; i++) {
		cin >> num;
		nums[num]++;
	}
	for (int i = 1; i <= 10000; i++)
		while (nums[i]--) cout << i << "\n";
}