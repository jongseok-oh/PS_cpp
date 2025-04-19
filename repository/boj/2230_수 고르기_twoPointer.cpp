#include <iostream>
#include <algorithm>

using namespace std;

int arr[100000];
int n, m;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> arr[i];
	sort(arr, arr + n);

	int answer = 0x7fffffff;

	// end point를 찾는데 n의 연산이 필요
	// binary search는 log n이라 시간상 더 유리
	for (int i = 0; i < n; i++) {
		int end = i;
		while (end < n && arr[end] - arr[i] < m) end++;
		if (end == n) break;
		answer = min(answer, arr[end] - arr[i]);
	}

	cout << answer;
}