#include <iostream>

using namespace std;

int T,n,m, movie;

int height[100001];
int tHeight;

int tree[800000];

void init(int node, int left, int right) {
	if (left == right) {
		if (left <= n) tree[node] = 1;
		else tree[node] = 0;
		return;
	}
	int mid = (left + right) >> 1;
	init(node * 2, left, mid);
	init(node * 2 + 1, mid + 1, right);
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

// height[movie] ~ tHeight
int getCnt(int node, int left, int right) {
	if (left > tHeight || right < height[movie] + 1) return 0;
	if (left >= height[movie] + 1 && right <= tHeight) return tree[node];
	int mid = (left + right) >> 1;
	return getCnt(node * 2, left, mid) + getCnt(node * 2 + 1, mid + 1, right);
}

void Update(int node, int left, int right, int tar, int num) {
	if (left > tar || right < tar) return;
	if (left == right) { tree[node] = num; return; }
	int mid = (left + right) >> 1;
	Update(node * 2, left, mid, tar, num);
	Update(node * 2 + 1, mid + 1, right, tar, num);
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> T;
	while (T--) {
		cin >> n >> m;
		tHeight = n;
		for (int i = 1; i <= n; i++) height[i] = n - i + 1;
		init(1, 1, n + m);
		for(int i =0; i<m; i++){
			cin >> movie;
			cout << getCnt(1, 1, n + m)<< " ";
			Update(1, 1, n + m, height[movie], 0);
			height[movie] = ++tHeight;
			Update(1, 1, n + m, tHeight, 1);
		}
	}
}