#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int n,d;

struct ho {
	int h, o;
}p[100000];

bool cmp(int a, int b) {
	return p[a].h > p[b].h;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	int _h, _o;
	for (int i = 0; i < n; ++i) {
		cin >> _h >> _o;
		if (_h > _o) swap(_h, _o);
		p[i].h = _h; p[i].o = _o;
	}
	cin >> d;
	sort(p, p + n, [&](auto& a, auto& b) {
		return a.o < b.o;
	});
	
	priority_queue<int, vector<int>, decltype(&cmp)> q(cmp);

	int ret = 0;
	for (int i = 0; i < n; ++i) {
		auto& tt = p[i];

		while (q.size() && p[q.top()].h < tt.o - d) q.pop();

		if (tt.h + d >= tt.o) q.push(i);
		if (ret < q.size()) ret = q.size();
	}
	cout << ret;
}