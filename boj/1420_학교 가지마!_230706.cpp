#include <iostream>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

const int IN = 0, OUT = 1;

int n, m;
int s, t;

int unused = 0;

struct Edge {
	Edge* reverse;
	int cap, flow, nIdx;
}edges[60000];

Edge* getEdge(int cap, int flow, int nIdx) {
	edges[unused].reverse = 0;
	edges[unused].cap = cap;
	edges[unused].flow = flow;
	edges[unused].nIdx = nIdx;

	return &edges[unused++];
}

int calcIdx(int y, int x, int state) { return (y * m + x) * 2 + state;}

vector<Edge*> con[20000];

char map[100][100];
int dy[] = {1,0,-1,0}, dx[] = { 0,1,0,-1};

int level[20000];
bool bfs() {
	memset(level, -1, 8 * n * m);
	level[s] = 0;
	queue<int> q;
	q.push(s);

	while (q.size())
	{
		int tt = q.front(); q.pop();

		for (auto& edge : con[tt]) {
			if (level[edge->nIdx] == -1
				&& edge->cap - edge->flow > 0) {
				level[edge->nIdx] = level[tt] + 1;

				if (edge->nIdx == t) return true;

				q.push(edge->nIdx);
			}
		}
	}

	return false;
}

int w[20000];
bool dfs(int idx) {
	if (idx == t) return true;

	for (int& i = w[idx]; i < con[idx].size(); i++) {
		auto& edge = con[idx][i];

		if (level[idx] + 1 == level[edge->nIdx]
			&& edge->cap - edge->flow > 0) {

			if (dfs(edge->nIdx)) {
				edge->flow++;
				edge->reverse->flow--;
				return true;
			}
		}
	}

	return false;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;

	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++){
		cin >> map[i][j];
		if (map[i][j] == 'K') {
			s = calcIdx(i, j, OUT);
			continue;
		}
		else if (map[i][j] == 'H') {
			t = calcIdx(i, j, IN);
			continue;
		}
		else if (map[i][j] == '#') continue;

		int inIdx = calcIdx(i, j, IN);
		int outIdx = calcIdx(i, j, OUT);

		Edge* in2out = getEdge(1, 0, outIdx);
		Edge* out2in = getEdge(0, 0, inIdx);

		in2out->reverse = out2in;
		out2in->reverse = in2out;

		con[inIdx].push_back(in2out);
		con[outIdx].push_back(out2in);
	}

	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
		if (map[i][j] == '#') continue;

		int tIdx = calcIdx(i, j, OUT);
		for (int dir = 0; dir < 4; dir++) {
			int ny = i + dy[dir], nx = j + dx[dir];
			if (ny < 0 || ny >= n || nx < 0 || nx >= m || map[ny][nx] == '#') continue;
			
			if ((map[i][j] == 'K' && map[ny][nx] == 'H')
				|| (map[i][j] == 'H' && map[ny][nx] == 'K')) {
				cout << -1; return 0;
			}

			int nIdx = calcIdx(ny, nx, IN);

			Edge* out2in = getEdge(1, 0, nIdx);
			Edge* in2out = getEdge(0, 0, tIdx);

			out2in->reverse = in2out;
			in2out->reverse = out2in;

			con[tIdx].push_back(out2in);
			con[nIdx].push_back(in2out);
		}
	}

	int ans = 0;
	while (bfs())
	{
		memset(w, 0, 8 * n * m);

		while (true)
		{
			if (dfs(s)) ans++;
			else break;
		}
	}

	cout << ans;
}