#include <string>
#include <iostream>
#include <vector>
#include <cstring>
#include <unordered_set>

using namespace std;

int N, M, S, T;

vector<int> con[10001];
vector<int> rcon[10001];

bool visit[10001];
vector<int> order;

void dfs(int v) {
	visit[v] = true;
	for (int next : con[v]) {
		if (!visit[next]) dfs(next);
	}
	order.push_back(v);
}

int s, t;
int sccCnt[10001];
int sccNum[10001];
void rdfs(int v, int k) {
	visit[v] = true;
	sccNum[v] = k; ++sccCnt[k];
	for (int next : rcon[v]) {
		if (!visit[next]) rdfs(next, k);
	}
}

vector<int> sccCon[10001];
void makeSccCon(int v) {
	visit[v] = true;
	unordered_set<int> tVisit;
	for (int next : con[v]) {
		if (sccNum[v] == sccNum[next]) continue;
		if (!tVisit.count(sccNum[next])) {
			sccCon[sccNum[v]].push_back(sccNum[next]);
			tVisit.insert(sccNum[next]);
		}
		if (!visit[next]) makeSccCon(next);
	}
}

void scc() {
	for (int i = 1; i <= N; ++i) {
		if (!visit[i]) dfs(i);
	}

	int k = 0;
	memset(visit, 0, sizeof visit);
	for (int i = N - 1; i >= 0; --i) {
		int v = order[i];
		if (!visit[v]) rdfs(v, k++);
	}

	memset(visit, 0, sizeof visit);
	s = sccNum[S]; t = sccNum[T];
	for (int i = 1; i <= N; ++i) {
		if (!visit[i]) makeSccCon(i);
	}
}

int dp[10001];
int solve(int v) {
	if (v == t) return sccCnt[t];
	int& ret = dp[v];
	if (ret != -1) return ret;
	int _max = 0;
	for (int next : sccCon[v]) {
		_max = max(_max, solve(next));
	}

	return ret = (_max == 0 ? 0 : sccCnt[v] + _max);
}

int main() {
	cin >> N >> M >> S >> T;
	int a, b;
	for (int i = 0; i < M; ++i) {
		cin >> a >> b;
		con[a].push_back(b);
		rcon[b].push_back(a);
	}
	scc();
	memset(dp, -1, sizeof dp);
	cout << solve(s);
}