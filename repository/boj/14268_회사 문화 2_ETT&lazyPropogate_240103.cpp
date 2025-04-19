#include <iostream>
#include <vector>

using namespace std;

int n,m;

vector<int> child[100001];

struct Range{
	int s,e;
}dfsRange[100001];

void dfs(int t, int& num){
	Range& range = dfsRange[t];
	range.s = ++num;
	for(int& nNode: child[t]) dfs(nNode, num);
	range.e = num;
}

int lazyTree[400000];
int val[100001];
void updateLazy(int node, int l, int r, int idx){
	if(lazyTree[node]){
		if(l != r){
			lazyTree[node * 2] += lazyTree[node];
			lazyTree[node * 2 + 1] += lazyTree[node];
		}else val[idx] += lazyTree[node];
		lazyTree[node] = 0;
	}
}

void _update(int node, int l, int r, int idx, int w){
	int s = dfsRange[idx].s, e = dfsRange[idx].e;
	if(l > e || r < s) return;
	if(s <= l && e >= r){
		lazyTree[node] += w; return;
	}
	updateLazy(node, l, r, idx);
	int mid = (l + r) >>1;
	_update(node*2, l, mid, idx, w);
	_update(node*2+1, mid+1, r, idx, w);
}

int query(int node, int l, int r, int idx){
	int t = dfsRange[idx].s;
	if(l > t || r < t) return 0;
	updateLazy(node, l, r, idx);
	if(l == r) return val[idx];
	int mid = (l + r) >>1;
	return query(node * 2, l, mid, idx) + query(node * 2 + 1, mid+1, r, idx);
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin>>n>>m;

	int p;
	for(int i = 1; i<=n; ++i){
		cin>>p;
		if(p != -1) child[p].push_back(i);
	}
	int num = 0;
	dfs(1, num);

	int mode, i, w;
	while(m--){
		cin>>mode>>i;
		if(mode == 1){
			cin>>w; _update(1, 1, n, i, w);
		}else cout<<query(1, 1, n, i)<<"\n";
	}
}