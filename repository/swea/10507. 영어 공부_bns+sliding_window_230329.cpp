#include <iostream>

using namespace std;

int arr[200000];

int n, p;

bool chk(int plus) {

	for (int left = 0, right = 0; left < n && right <n; left++) {
		int tar = arr[left] + plus - 1;
		while (right < n && arr[right] <= tar) right++;
		if (tar- arr[left] - (right - left - 1) <= p) return true;
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T; cin >> T;
	for (int tt = 1; tt <= T; tt++) {
		cin >> n >> p;

		for (int i = 0; i < n; i++) cin >> arr[i];

		int left = p + 1, right = 1e6 + 1;
		while (left + 1 < right) {
			int mid = (left + right) >> 1;
			
			// mid일 만큼 연속 공부가 가능했으면
			// 날짜를 늘려본다
			if (chk(mid)) left = mid;
			else right = mid;
		}
		cout << "#" << tt << " " << left << "\n";
	}
}