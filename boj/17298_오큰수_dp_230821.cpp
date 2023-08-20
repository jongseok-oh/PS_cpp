#include <iostream>

using namespace std;

int n;

int arr[1000001];
int cache[1000001];

int nge(int idx) {
	if (idx == n) return n;
	int& ret = cache[idx];

	if (ret) return ret;

	int nIdx = idx + 1;

	while (true) {
		if (nIdx == n || arr[nIdx] > arr[idx]) {
			ret = nIdx; break;
		}
		nIdx = nge(nIdx);
	}

	return ret;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;

	for (int i = 0; i < n; i++) cin >> arr[i];

	arr[n] = -1;
	for (int i = 0; i < n; i++) cout << arr[nge(i)] << " ";
}