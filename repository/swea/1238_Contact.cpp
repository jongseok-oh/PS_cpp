#include<iostream>
#include <cstring>
#include <queue>
using namespace std;

bool connect[101][101];
bool visit[101];

struct info
{
	int node, cnt;
};

int main(int argc, char** argv)
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int testCase = 0;
	while (1) {
		int num, start;
		cin >> num >> start;
		if (cin.eof()) break;
		testCase++;
		int cnt = num / 2;
		memset(connect, 0, sizeof(connect));
		while (cnt--) {
			int a, b; cin >> a >> b;
			connect[a][b] = true;
		}
		memset(visit, 0, sizeof(visit));
		
		queue<info> q; q.push({ start, 0 });
		visit[start] = true;
		int endNode = -1, endCnt = -1;
		while (q.size()) {
			info cur = q.front(); q.pop();
			if (endCnt < cur.cnt) {
				endNode = cur.node;
				endCnt = cur.cnt;
			}
			else if (endCnt == cur.cnt) {
				if (endNode < cur.node) {
					endNode = cur.node;
				}
			}
			for (int i = 1; i <= 100; i++) {
				if (connect[cur.node][i] && !visit[i]) {
					visit[i] = true;
					q.push({ i,cur.cnt + 1 });
				}
			}
		}
		cout << "#" << testCase << " " << endNode << "\n";
	}
}