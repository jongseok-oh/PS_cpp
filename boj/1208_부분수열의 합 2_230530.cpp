#include <iostream>
#include <algorithm>

using namespace std;


int arr[40];
int sum1[1 << 20];
int sum2[1 << 20];

int n, s;

int equalOrBigger(int tar, int end) {
	int left = 0, right = end;

	while (left + 1 < right) {
		int mid = (left + right) >> 1;

		if (sum2[mid] >= tar) right = mid;
		else left = mid;
	}

	return right;
}

int bigger(int tar, int end) {
	int left = 0, right = end;

	while (left + 1 < right) {
		int mid = (left + right) >> 1;

		if (sum2[mid] > tar) right = mid;
		else left = mid;
	}

	return right;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> s;

	for (int i = 0; i < n; i++) cin >> arr[i];

	int half = n / 2;

	long long ans = 0;
	for (int i = 1; i < (1 << half); i++) {
		int sum = 0;
		
		for (int j = 0; j < half; j++)
			if (i & (1 << j)) sum += arr[j];

		sum1[i] = sum;

		if (sum == s) ans++;
	}

	int len = n - half;
	for (int i = 1; i < (1 << len); i++) {
		int sum = 0;
		for (int j = 0; j < len; j++)
			if (i & (1 << j)) sum += arr[j + half];
		sum2[i] = sum;

		if (sum == s) ans++;
	}

	sort(sum2 + 1, sum2 + (1 << len));
	
	for (int i = 1; i < (1 << half); i++) {
		int tar = s - sum1[i];

		int idx = equalOrBigger(tar, (1 << len));

		if (idx && sum2[idx] == tar) {
			int idx2 = bigger(tar, (1 << len));

			ans += idx2 - idx;
		}
	}
	cout << ans;
}