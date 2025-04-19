#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>

using namespace std;

int n;
int peopleCnt[10];
int sum = 0;

int answer = 1e9;

vector<int> connect[10];

bool selected[10] = { false,};

bool visit[10];
bool isConnect(const set<int> s) {
	for (int i = 0; i < n; i++) visit[i] = false;

	queue<int> q; q.push(*s.begin());
	visit[*s.begin()] = true;
	
	int cnt = 1;
	while (q.size()) {
		int node = q.front(); q.pop();
		for (int nNode : connect[node]) {
			if (s.find(nNode) != s.end() && !visit[nNode]) {
				visit[nNode] = true;
				q.push(nNode); cnt++;
			}
		}
	}
	if (cnt == s.size()) return true;
	return false;
}

void johap(int cnt, int r, int idx) {
	if (cnt == r) {
		set<int> s, otherS;

		for (int i = 0; i < n; i++) {
			if (selected[i]) s.insert(i);
			else otherS.insert(i);
		}
		if (isConnect(s)) {
			if (isConnect(otherS)) {
				int tSum = 0;
				for (int node : s) tSum += peopleCnt[node];
				int cal = abs(sum - tSum - tSum);
				answer = answer > cal ? cal : answer;
			}
		}
		return;
	}

	for (int i = idx; i < n; i++) {
		selected[i] = true;
		johap(cnt + 1, r, i + 1);
		selected[i] = false;
	}
}


int main(void) {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> peopleCnt[i];
		sum += peopleCnt[i];
	}
	
	for (int i = 0; i < n; i++) {
		int num; cin >> num;
		for (int j = 0; j < num; j++) {
			int b; cin >> b;
			connect[i].push_back(--b);
		}
	}

	for (int r = 1; r < n; r++) {
		johap(0, r, 0);
	}
	cout << (answer == 1e9 ? -1 : answer);
}