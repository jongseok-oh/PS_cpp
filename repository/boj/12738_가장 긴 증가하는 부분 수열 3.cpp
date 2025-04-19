#include <iostream>
using namespace std;

int n;

int arr[1000000];
int cache[1000000];

int main(void) {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];
	
	cache[0] = arr[0];

	int idx = 1;

	// 증가하는 부분수열 -> lower_bound로 삽입 위치 결정해야 함
	for (int i = 1; i < n; i++) {
		int t = arr[i];
		if (cache[idx - 1] < t) cache[idx++] = t;
		else {
			int low = -1, high = idx - 1;
			while (low + 1 < high) {
				int mid = (low + high) >> 1;
				if (cache[mid] >= t) high = mid;
				else low = mid;
			}
			cache[high] = t;
		}
	}
	cout << idx;
}