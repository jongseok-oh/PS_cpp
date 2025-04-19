#include <iostream>
#include <algorithm>

using namespace std;

int n;

int arr[2000];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];
	sort(arr, arr + n);
	int ans = 0;
	for (int i = 0; i < n; i++) {
		int low = 0, high = n - 1;
		int sum, tar = arr[i];
		while (true) {
			if (low == i) low++;
			if (high == i) high--;
			if (low >= high) break;
			sum = arr[low] + arr[high];
			if (sum > tar) high--;
			else if (sum < tar) low++;
			else {
				ans++; break;
			}
		}
	}
	cout << ans;
}