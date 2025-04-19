#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

const int _MAX = 200000 * 30 + 50;
const int ROOT = 1;
const int INF = 0x7fffffff;

int unused = 2;
int n;

int Node[200000];

int Trie[_MAX][2];

bool bitSet[30];

void setBit(int t) {
	for (int i = 29; i >= 0; i--) {
		bitSet[i] = t & 1;
		t >>= 1;
	}
}

void insertTrie(int t) {
	setBit(t);
	int cur = ROOT;
	for (int i = 0; i < 30; i++) {
		if (!Trie[cur][bitSet[i]]) Trie[cur][bitSet[i]] = unused++;
		cur = Trie[cur][bitSet[i]];
	}
}

int findMinXor(int t) {
	setBit(t);
	int cur = ROOT;
	int ret = 0;
	for (int i = 0; i < 30; i++) {
		ret <<= 1;
		if (Trie[cur][bitSet[i]]) cur = Trie[cur][bitSet[i]];
		else {
			cur = Trie[cur][!bitSet[i]];
			ret |= 1;
		}
	}
	return ret;
}

// idx start ~ end까지 집합의
// MST 반환
ll solve(int start, int end, int depth = 29) {
	if (Node[start] == Node[end]){
		insertTrie(Node[start]);
		return 0;
	}

	int mid = start;
	while (mid <= end && !(Node[mid] & (1 << depth))) mid++;

	// 트리가 depth bit로 분해되지 않으면
	if (start == mid || end + 1 == mid) return solve(start, end, depth - 1);

	// 좌측 트리는 Trie에 전부 담겨있다.
	ll leftSum = solve(start, mid - 1, depth - 1);
	
	// 좌측 트리와 우측 트리를 연결하는
	// 가장 작은 수 반환
	int minEdge = 0x7fffffff;
	for (int i = mid; i <= end; i++) minEdge = min(minEdge, findMinXor(Node[i]));

	return leftSum + minEdge + solve(mid, end, depth - 1);
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> Node[i];
	sort(Node, Node + n);

	cout << solve(0, n - 1);
}