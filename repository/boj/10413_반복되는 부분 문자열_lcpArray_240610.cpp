#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int T;

vector<int> getSuffixArray(const string& s) {
	int n = s.size(), m = max(256, n) + 1;
	vector<int> sa(n), rank(n + n), nRank(n + n), cnt(m), idx(n);
	
	// suffix들의 첫 문자로 rank 선정
	for (int i = 0; i < n; ++i) rank[i] = s[i];

	for (int d = 1; d < n; d <<= 1) {
		auto cmp = [&](int i, int j) {
			return rank[i] < rank[j] || (rank[i] == rank[j] && rank[i + d] < rank[j + d]);
		};

		// rank[i+d]를 기준으로 stable sort
		for (int i = 0; i < m; ++i) cnt[i] = 0;
		for (int i = 0; i < n; ++i) ++cnt[rank[i + d]];
		for (int i = 1; i < m; ++i) cnt[i] += cnt[i - 1];
		// 뒤에서 부터 보는 이유
		// 같은 값을 가져도 더 뒤에 있는 놈이 뒤에 오게
		// idx의 인덱스는 정렬 된 순서 : 0, 1, 3.. -> 올바른 순서
		for (int i = n - 1; i >= 0; --i) idx[--cnt[rank[i + d]]] = i;

		// rank[i]로 rank[i+d] 기반 pair sort
		for (int i = 0; i < m; ++i) cnt[i] = 0;
		for (int i = 0; i < n; ++i) ++cnt[rank[i]];
		for (int i = 1; i < m; ++i) cnt[i] += cnt[i - 1];

		// idx에는 rank[i+d] 기준 정렬시 재조합한 인덱스가 존재
		// 마찬가지로 더 뒤에 있는 놈부터 보면서 pair sort
		for (int i = n - 1; i >= 0; --i) sa[--cnt[rank[idx[i]]]] = idx[i];

		nRank[sa[0]] = 1;

		for (int i = 1; i < n; ++i)
			nRank[sa[i]] = nRank[sa[i - 1]] + cmp(sa[i - 1], sa[i]);

		rank = nRank;
		// sort cut
		// sa가 정렬된 상태라면
		// 마지막 문자열의 rank가 n이다
		if (rank[sa[n - 1]] == n) break;
		// 이거 맨 밑에 안쓰면 틀리는데 이유는
		// 문자열 길이가 아스키 코드 값 중 하나면
		// sort를 진행하기 전에 loop 탈출할 수 있다
		// 밑에 쓰거나 지우자
	}
	// sa의 0,1,2,3..
	// a
	// ana
	// anana
	// banana
	// na
	// nana
	return sa;
}

vector<int> getLcpArray(const vector<int>& sa, const string& s) {
	int n = s.size();
	vector<int> isa(n), lcp(n);
	for (int i = 0; i < n; ++i) isa[sa[i]] = i;
	// banana
	for (int i = 0, k = 0; i < n; ++i) {
		if (isa[i] == 0) continue;
		for (int j = sa[isa[i] - 1]; s[i + k] == s[j + k]; ++k);
		lcp[isa[i]] = (k?k--:0);
	}
	// lcp의 0,1,2,3..
	// a
	// ana
	// anana
	// banana
	// na
	// nana
	return lcp;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> T;
	string s;
	while (T--) {
		cin >> s;
		vector<int> sa = getSuffixArray(s);
		vector<int> lcp = getLcpArray(sa, s);

		int ret = 0;
		for (int i = 1, n = lcp.size(); i < n; ++i) {
			if(lcp[i] > lcp[i - 1]) ret += lcp[i] - lcp[i - 1];
		}
		cout << ret << "\n";
	}
}