#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

int t;

int n;
int arr1[1000];
int sum1[500500];

int m;
int arr2[1000];
int sum2[500500];

int lowerBound(int tar, int end) {
	int left = -1, right = end;

	while (left + 1 < right) {
		int mid = (left + right) >> 1;
		
		if (sum2[mid] >= tar) right = mid;
		else left = mid;
	}

	return right;
}

int upperBound(int tar, int end) {
	int left = -1, right = end;

	while (left + 1 < right) {
		int mid = (left + right) >> 1;

		if (sum2[mid] > tar) right = mid;
		else left = mid;
	}

	return right;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >>t>> n;
	for (int i = 0; i < n; i++) cin >> arr1[i];

	cin >> m;
	for (int i = 0; i < m; i++) cin >> arr2[i];

	int idx1 = 0;
	for (int i = 0; i < n; i++) {
		sum1[idx1++] = arr1[i];
		for (int j = i + 1; j < n; j++){
			sum1[idx1] = sum1[idx1 - 1] + arr1[j];
			idx1++;
		}
	}

	int idx2 = 0;
	for (int i = 0; i < m; i++) {
		sum2[idx2++] = arr2[i];
		for (int j = i + 1; j < m; j++) {
			sum2[idx2] = sum2[idx2 - 1] + arr2[j];
			idx2++;
		}
	}

	sort(sum2, sum2 + idx2);

	long long ans = 0;
	unordered_map<int, int> cache;

	for (int i = 0; i < idx1; i++) {
		int tar = t - sum1[i];

		if (cache.find(tar) != cache.end()) ans += cache[tar];
		else {
			int lbIdx = lowerBound(tar, idx2);
			if (lbIdx == idx2 || sum2[lbIdx] != tar) continue;

			int cnt = upperBound(tar, idx2) - lbIdx;
			ans += cnt;

			cache[tar] = cnt;
		}
	}

	cout << ans;
}