#include <iostream>

using namespace std;

int n;
int arr[100000];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];

	int low = 0, high = n - 1;

	int _min = 0x7fffffff;
	int ans1 = -1, ans2 = -1;

	while (low + 1<= high) {
		int sum = arr[low] + arr[high];

		if (abs(sum) < _min) {
			_min = abs(sum);
			ans1 = low, ans2 = high;
		}

		if (sum < 0) low++;
		else if (sum > 0) high--;
		else break;
	}

	cout << arr[ans1] << " " << arr[ans2];
}