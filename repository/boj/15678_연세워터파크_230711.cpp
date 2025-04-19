#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>

using namespace std;

typedef long long ll;

const ll INF = LLONG_MIN;

int n, d;

int arr[100001];
vector<int> plusIdx;

ll dp[100001];
ll getMaxSum(int t, int start, int end) {
	if (t >= end) return 0;
	ll& ret = dp[t];
	if (ret != INF) return ret;

	if (t == start) ret = 0;
	else ret = arr[t];

	ll calc = INF;
	for (int i = 1; i <= d; i++)
		calc = max(calc, getMaxSum(t + i, start, end));

	return ret += calc;
}


int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> d;

	int _max = -1e9;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		_max = max(_max, arr[i]);
		if (arr[i] > 0) plusIdx.push_back(i);
	}

	if (!plusIdx.size()) {
		cout << _max; return 0;
	}

	for (int i = 0; i <= n; i++) dp[i] = INF;

	ll ans = 0, tSum = 0, tIdx = 0;
	for (int& next : plusIdx) {
		if (tIdx + d >= next) tSum += arr[next];
		else {
			ll calc = getMaxSum(tIdx, tIdx, next);
			if (tSum + calc < 0) tSum = arr[next];
			else tSum += arr[next] + calc;
		}
		tIdx = next;
		ans = max(ans, tSum);
	}

	cout << ans;
}