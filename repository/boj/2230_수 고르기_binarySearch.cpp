#include <iostream>
#include <algorithm>

using namespace std;

int arr[100000];
int n;
long long m;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> arr[i];
	sort(arr, arr + n);

	// m이 20억이라 answer를 20보다 크게 해야됨
	// 야무지게 100억 넣음 ㅎㅎ
	// 이분탐색은 까불지 말고 그냥 전부 8바이트쓰자
	long long answer = 1e10;

	for (int i = 0; i < n; i++) {
		long long target = 1L*arr[i] + m;

		int low = i-1, high = n;
		while (low + 1 < high) {
			int mid = (low + high) >> 1;
			if (arr[mid] >= target) high = mid;
			else low = mid;
		}
		if (high == n) break;
		int diff = arr[high] - arr[i];
		answer = answer > diff ? diff : answer;
		if (answer == m) break;
	}
	cout << answer;
}