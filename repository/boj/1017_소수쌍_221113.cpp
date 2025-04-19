#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int n;

int even[50], odd[50];
int _even, _odd;
int* _left; int* _right;

bool etoche[2001];

vector<int> con[25];

bool visit[25];
int choose[25];

bool dfs(int t) {
	for (int i = 0, len = con[t].size(); i < len; i++) {
		int rr = con[t][i];
		if (visit[rr]) continue;
		visit[rr] = true;
		if (!choose[rr]) continue;
		if (choose[rr] == -1 || dfs(choose[rr])) {
			choose[rr] = t;
			return true;
		}
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;

	bool first;
	for (int i = 0; i < n; i++) {
		int num; cin >> num;
		if (num & 1) odd[_odd++] = num;
		else even[_even++] = num;
		if (i == 0) {
			first = num & 1;
		}
	}
	if (_even != _odd) {
		cout << -1; return 0;
	}
	
	for (int i = 2; i < 45; i++) {
		if (etoche[i]) continue;
		for (int j = i + i; j < 2001; j += i)
			etoche[j] = true;
	}

	if (first) {
		_left = odd; _right = even;
	}
	else {
		_left = even; _right = odd;
	}

	for (int i = 0; i < _even; i++) {
		for (int j = 0; j < _even; j++) {
			if (!etoche[_left[i] + _right[j]])
				con[i].push_back({ j });
		}
	}

	vector<int> ans;

	for (int i = 0, len = con[0].size(); i < len; i++) {
		memset(choose, -1, 4 * _even);
		choose[con[0][i]] = 0;
		bool chk = true;
		for (int j = 1; j < _even; j++) {
			memset(visit, 0, _even);
			if (!dfs(j)) {
				chk = false; break;
			}
		}
		if (chk) ans.push_back(_right[con[0][i]]);
	}
	if (!ans.size()) {
		cout << -1;
	}
	else {
		sort(ans.begin(), ans.end());
		for (auto it = ans.begin(); it != ans.end(); it++)
			cout << *it << " ";
	}
}