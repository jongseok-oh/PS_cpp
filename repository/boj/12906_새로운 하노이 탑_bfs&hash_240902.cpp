#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <queue>

using namespace std;

bool check(int state,const string& board) {
	for (char c : board) {
		if (c - 'A' != state) return false;
	}
	return true;
}

int calcHash(const vector<string>& sticks) {
	int _hash = 0;
	hash<string> func;
	for (const string& stick : sticks) {
		_hash *= 31;
		_hash += (int)func(stick);
	}
	return _hash;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int cnt; string board;
	vector<string> sticks(3);
	for (int i = 0; i < 3; ++i) {
		cin >> cnt;
		if (!cnt) continue;
		cin>>sticks[i];
	}

	queue<vector<string>> q;
	unordered_set<int> visit;

	q.push(sticks);
	visit.insert(calcHash(sticks));

	int ret = 0;
	while (q.size()) {
		int qsize = q.size();
		while (qsize--) {
			auto tStick = q.front(); q.pop();

			bool allDone = true;
			for (int i = 0; i < 3; ++i) {
				allDone &= check(i, tStick[i]);
			}
			if (allDone) {
				cout << ret; return 0;
			}

			for (int i = 0; i < 3; ++i) {
				if (check(i, tStick[i])) continue;
				for (int j = 0; j < 3; ++j) {
					if (i == j) continue;
					auto temp = tStick;
					char moveVal = temp[i].back();
					temp[i].pop_back();
					temp[j].push_back(moveVal);

					int _hash = calcHash(temp);
					if (visit.count(_hash)) continue;
					visit.insert(_hash);
					q.push(temp);
				}
			}
		}
		++ret;
	}
	cout << -1;
};
