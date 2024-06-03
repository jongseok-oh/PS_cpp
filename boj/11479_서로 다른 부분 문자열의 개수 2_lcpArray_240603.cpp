#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> getSuffixArray(string& s) {
	int n = s.size(), m = max(256, n) + 1;

	vector<int> sa(n), rank(n + n), nRank(n + n), cnt(m), idx(n);

	for (int i = 0; i < n; ++i) rank[i] = s[i];
	for (int d = 1; d < n; d <<= 1) {
		auto cmp = [&](int i, int j) {
			return rank[i] < rank[j] || (rank[i] == rank[j] && rank[i + d] < rank[j + d]);
		};

		// cnt 배열 순회는 m으로 하자..
		for (int i = 0; i < m; ++i) cnt[i] = 0;
		for (int i = 0; i < n; ++i) ++cnt[rank[i + d]];
		for (int i = 1; i < m; ++i) cnt[i] += cnt[i - 1];
		for (int i = n - 1; i >= 0; --i) idx[--cnt[rank[i + d]]] = i;

		for (int i = 0; i < m; ++i) cnt[i] = 0;
		for (int i = 0; i < n; ++i) ++cnt[rank[i]];
		for (int i = 1; i < m; ++i) cnt[i] += cnt[i - 1];
		for (int i = n - 1; i >= 0; --i) sa[--cnt[rank[idx[i]]]] = idx[i];

		if (rank[sa[n - 1]] == n) break; // short cut

		nRank[sa[0]] = 1;
		for (int i = 1; i < n; ++i)
			nRank[sa[i]] = nRank[sa[i - 1]] + cmp(sa[i - 1], sa[i]); // cmp 순서 중요

		rank = nRank;
	}

	return sa;
}

vector<int> getLcpArray(vector<int>& sa, string& s) {
	int n = s.size();
	vector<int> lcp(n), isa(n);

	for (int i = 0; i < n; ++i) isa[sa[i]] = i;

	// banana 원본 문자열 순으로 순회
	for (int i = 0, k = 0; i < n; ++i) {
		if (isa[i] == 0) continue;
		for (int j = sa[isa[i] - 1]; s[i + k] == s[j + k]; ++k);
		lcp[i] = k;
		if (k) --k;
	}
	return lcp;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	string s; cin >> s;
	vector<int> sa = getSuffixArray(s);
	vector<int> lcp = getLcpArray(sa, s);

	int n = s.size(); long long ret = 0;
	for (int i = 0; i < n; ++i) {
		ret += n - i - lcp[i];
	}
	cout << ret;
}