#include <iostream>
#include <algorithm>

using namespace std;

int n,x;

int arr[100000];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;

	for (int i = 0; i < n; i++) cin >> arr[i];
	cin >> x;

	sort(arr, arr + n);

	int ans = 0;

	for (int i = 0; i < n; i++) {
		if (arr[i] > x / 2) break;
		int tarnum = x - arr[i];
		int low = i, high = n;

		while (low + 1 < high) {
			int mid = (low + high) >> 1;
			
			if (arr[mid] >= tarnum)high = mid;
			else low = mid;
		}
		if (high == n) continue;
		if (arr[high] == tarnum) ans++;
	}
	cout << ans;
}