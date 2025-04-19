#include <iostream>

using namespace std;

int arr[200000];

int n, p;

bool chk(int plus) {

	// 앞에서 부터 보며 arr[i]부터
	// 연속으로 plus일 공부 가능한지 확인
	for (int i = 0; i < n -1; i++) {
		int left = i, right = n, tar = arr[i] + plus - 1;
		while (left + 1 < right) {
			int mid = (left + right) >> 1;
			if (arr[mid] <= tar) left = mid;
			else right = mid;
		}

		// tar 이하 중 가장 큰 수 arr[left]
		if (tar - arr[i] - (left - i) <= p) return true;
		// 틈새를 채우는데 필요한 p의 개수
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