#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int L; string s;

// nlogn^2
vector<int> getSuffixArray(string& s) {
	int n = s.size();
	vector<int> sa(n), rank(n + 1), nRank(n + 1);
	
	for (int i = 0; i < n; ++i) sa[i] = i, rank[i] = s[i];
	
	for (int d = 1; d < n; d <<= 1) {
		auto cmp = [&](int i, int j) {
			return rank[i] < rank[j] || (rank[i] == rank[j] && rank[i + d] < rank[j + d]);
		};
		sort(sa.begin(), sa.end(), cmp);

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
	cin >> L>> s;
	vector<int> suffixArray = getSuffixArray(s);
	cout << getMaxLcp(suffixArray, s);
}