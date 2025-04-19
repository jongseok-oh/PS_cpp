#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n;

// 내 몸으로 들어오는 간선의 수
int inDegree[10001];

// 일하는데 걸리는 시간
int time[10001];

// i번 작업을 마무리하는데 걸리는 시간
int dp[10001];

vector<int> edge[10001];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;

	for (int i = 1; i <=n; i++) {
		cin >> time[i] >> inDegree[i];

		// 간선 정보 저장
		for (int j = 0; j < inDegree[i]; j++) {
			int node; cin >> node;
			edge[node].push_back(i);
		}
	}

	queue<int> q;

	// 내 몸으로 들어오는 간선 수가
	// 0인 친구들을 queue에 삽입
	// 과 동시에 dp 배열 초기화
	for (int i = 1; i <= n; i++) 
		if (!inDegree[i]){
			q.push(i);
			dp[i] = time[i];
		}

	int ans = -1;
	while (q.size()) {
		// q에서 꺼낸 순간
		// 선행 작업이 완료됐음이 보장 됨
		int t = q.front(); q.pop();
		ans = max(ans, dp[t]);

		for (int i = 0, len = edge[t].size(); i < len; i++) {
			int nNode = edge[t][i];
			
			// 현재 내 작업이 끝나는 시간은
			// 선행 작업의 시간 + 현재 작업의 걸리는 시간
			// 그 중 선행 작업이 제일 늦게 끝나는 시간이
			// 내 작업의 걸리는 시간이 됨
			dp[nNode] = max(dp[nNode], time[nNode] + dp[t]);
			inDegree[nNode]--;

			// 내 몸으로 들어오는
			// 선행 작업이 더 이상 없으면
			if (!inDegree[nNode]) q.push(nNode);
		}
	}
	cout << ans;
}