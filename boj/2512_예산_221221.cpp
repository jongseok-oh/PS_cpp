#include <iostream>
#include <algorithm>

using namespace std;

int n,m;

int arr[10001];
int prefixSum[10001];

int search(int tar) {
	int low = 0, high = n + 1;
	while (low + 1 < high) {
		int mid = (low + high) >> 1;
		
		if (arr[mid] >= tar) high = mid;
		else low = mid;
	}
	return high;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> arr[i];
	sort(arr + 1, arr + n + 1);
	for (int i = 1; i <= n; i++) 
		prefixSum[i] += prefixSum[i - 1] + arr[i];
	
	cin >> m;
	int low = 0, high = arr[n] + 1;
	while (low + 1 < high)
	{
		int mid = (low + high) >> 1;
		
		int idx = search(mid);
		long long sum = 1LL * (n + 1 - idx) * mid + prefixSum[idx - 1];

		if (sum > m) high = mid;
		else low = mid;
	}
	cout << low;
}