#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

int n;
	
int heights[500000];

int bns(vector<int>& st, int tar) {
	int n = st.size();
	int low = 0, high = n;
	while (low + 1 < high) {
		int mid = (low + high) >> 1;
		if (st[mid] > tar) low = mid;
		else high = mid;
	}
	return n - low;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; ++i) cin >> heights[i];

	vector<int> st;
	ll ret = 0;
	for (int i = n - 1; i >= 0; --i) {
		while (st.size() && st.back() < heights[i]) {
			st.pop_back();
			++ret;
		}

		ret += bns(st, heights[i]);
		st.push_back(heights[i]);
	}

	cout << ret;
}