#include <iostream>
#include <queue>
#include <unordered_map>
#include <math.h>

using namespace std;

int s,t;

unordered_map<int, char> visit;

void trace(int temp) {
	if (temp == s) return;
	if (visit[temp] == '*') {
		trace(sqrt(temp));
		cout << '*';
	}else if (visit[temp] == '+') {
		trace(temp/2);
		cout << '+';
	}
	else {
		trace(temp * s);
		cout << '/';
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> s>>t;
	if (s == t) {
		cout << 0; return 0;
	}
	queue<int> q;

	q.push(s);
	
	visit[s] = 'a';
	bool find = false;
	while (q.size()) {
		int tt = q.front(); q.pop();

		if (tt == t) {
			find = true; break;
		}

		if ((long long)tt * tt <= t && visit.find((long long)tt * tt) == visit.end()) {
			visit[tt * tt] = '*';
			q.push(tt * tt);
		}
		if (tt * 2 <= t && visit.find(tt * 2) == visit.end()) {
			visit[tt * 2] = '+';
			q.push(tt * 2);
		}
		if (visit.find(1) == visit.end()) {
			visit[1] = '/';
			q.push(1);
		}
	}
	if (!find) cout << -1;
	else {
		trace(t);
	}
}