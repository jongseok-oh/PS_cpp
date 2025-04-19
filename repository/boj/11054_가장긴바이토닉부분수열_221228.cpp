#include <iostream>
#include <cstring>

using namespace std;

int n;
int arr[1000];

int dpl[1001], dpr[1001];

int solvel(int idx) {
	int& ret = dpl[idx];
	if (ret != -1) return ret;
	
	ret = 0;

	int t = idx == n ? 1001 : arr[idx];
	for (int i = idx - 1; i >= 0; i--) {
		if (t > arr[i])
			ret = max(ret, solvel(i) + 1);
	}
	return ret;
}

int solver(int idx) {
	int& ret = dpr[idx + 1];
	if (ret != -1) return ret;
	
	ret = 0;

	int t = idx == -1 ? 1001 : arr[idx];

	for (int i = idx + 1; i < n; i++) {
		if (t > arr[i]) {
			ret = max(ret, solver(i) + 1);
		}
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];

	memset(dpl, -1, sizeof(dpl));
	memset(dpr, -1, sizeof(dpr));
	solvel(n);
	solver(-1);
	
	int _max = -1;

	for (int i = 0; i < n; i++) {
		int right = dpr[i + 1];
		int left = dpl[i];
		_max = max(_max, right + left + 1);
	}
	cout << _max;
}