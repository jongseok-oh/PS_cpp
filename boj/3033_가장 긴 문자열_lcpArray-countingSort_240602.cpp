#include <iostream>
#include <cstring>
#include <string>
#include <vector>

using namespace std;

int L; string s;

// nlogn2
vector<int> getSuffixArray(string& s) {
	int n = s.size(), m = max(n, 256) + 1;
	vector<int> sa(n), rank(n + n), nRank(n + n), cnt(m), idx(n);

	for (int i = 0; i < n; ++i) sa[i] = i, rank[i] = s[i];

	for (int d = 1; d < n; d <<= 1) {
		auto cmp = [&](int i, int j) {
			return rank[i] < rank[j] || (rank[i] == rank[j] && rank[i + d] < rank[j + d]);
		};
		
		// rank[i+d] 기준 sort
		for (int i = 0; i < m; ++i) cnt[i] = 0;
		for (int i = 0; i < n; ++i) ++cnt[rank[i + d]];
		for (int i = 1; i < m; ++i) cnt[i] += cnt[i - 1];
		for (int i = n - 1; i >= 0; --i) idx[--cnt[rank[i+d]]] = i;

		// rank[i] 기준 sort
		for (int i = 0; i < m; ++i) cnt[i] = 0;
		for (int i = 0; i < n; ++i) ++cnt[rank[i]];
		for (int i = 1; i < m; ++i) cnt[i] += cnt[i - 1];
		for (int i = n - 1; i >= 0; --i) sa[--cnt[rank[idx[i]]]] = idx[i];


		nRank[sa[0]] = 1;
		for (int i = 1; i < n; ++i)
			nRank[sa[i]] = nRank[sa[i - 1]] + cmp(sa[i - 1], sa[i]);
		rank = nRank;
	}
	return sa;
}

int getMaxLcp(vector<int>& sa, string& s) {
	int n = sa.size();
	vector<int> isa(n);
	for (int i = 0; i < n; ++i) isa[sa[i]] = i;

	int ret = 0;
	for (int i = 0, k = 0; i < n; ++i) {
		if (!isa[i]) continue;
		for (int j = sa[isa[i] - 1]; s[j + k] == s[i + k]; ++k);
		ret = max(ret, k);
		if (k) --k;
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> L >> s;
	vector<int> suffixArray = getSuffixArray(s);
	cout << getMaxLcp(suffixArray, s);
}