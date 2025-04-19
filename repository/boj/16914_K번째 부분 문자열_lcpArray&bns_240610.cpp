#include <iostream>
#include <vector>

using namespace std;

vector<int> suffixArray(const string& s) {
	int n = s.size(), m = max(256, n) + 1;
	vector<int> sa(n), rank(n + n), temp(n + n), cnt(m), idx(n);

	for (int i = 0; i < n; ++i) rank[i] = s[i];
	for (int d = 1; d < n; d <<= 1) {
		fill(cnt.begin(), cnt.end(), 0);
		for (int i = 0; i < n; ++i) ++cnt[rank[i + d]];
		for (int i = 1; i < m; ++i) cnt[i] += cnt[i - 1];
		for (int i = n - 1; i >= 0; --i) idx[--cnt[rank[i + d]]] = i;

		fill(cnt.begin(), cnt.end(), 0);
		for (int i = 0; i < n; ++i) ++cnt[rank[i]];
		for (int i = 1; i < m; ++i) cnt[i] += cnt[i - 1];
		for (int i = n - 1; i >= 0; --i) sa[--cnt[rank[idx[i]]]] = idx[i];

		int r = temp[sa[0]] = 1;
		for (int i = 1; i < n; ++i) {
			temp[sa[i]] = r += (rank[sa[i - 1]] < rank[sa[i]] ||
				(rank[sa[i - 1]] == rank[sa[i]] && rank[sa[i - 1] + d] < rank[sa[i] + d]));
		}
		if (r == n) break;
		rank.swap(temp);
	}

	return sa;
}

vector<int> lcpArray(const vector<int>& sa, const string& s) {
	int n = s.size();
	vector<int> pos(n), lcp(n);
	for (int i = 0; i < n; ++i) pos[sa[i]] = i;

	for (int i = 0, k =0; i < n; ++i) {
		if (!pos[i]) continue;
		for (int j = sa[pos[i]-1]; s[i + k] == s[j + k]; ++k);
		lcp[pos[i]] = k?k--:0;
	}

	return lcp;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	string s; cin >> s;

	int n = s.size();
	vector<int> sa = suffixArray(s), lcp = lcpArray(sa, s);
	vector<long long> prefixSum(n);

	prefixSum[0] = n - sa[0] - lcp[0];
	for (int i = 1; i < n; ++i) {
		int uniqCnt = n - sa[i] - lcp[i];
		prefixSum[i] = prefixSum[i-1] + uniqCnt;
	}

	int q, k; cin >> q;
	while (q--) {
		cin >> k;
		if (k > prefixSum[n - 1]) {
			cout << "-1\n"; continue;
		}
		int low = -1, high = n;
		while (low + 1 < high) {
			int mid = (low + high) >> 1;
			if (prefixSum[mid] >= k) high = mid;
			else low = mid;
		}
		int len = lcp[high] + k - (high?prefixSum[high-1]:0);
		cout << s.substr(sa[high], len) << "\n";
	}
}