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

int tree[400000];
void _update(int node, int l, int r, int t, int w){
	if(l > t || r < t) return;
	if(l == r) {tree[node] += w; return;}
	int mid = (l + r) >>1;
	_update(node*2, l, mid, t, w);
	_update(node*2+1, mid+1, r, t, w);
	tree[node] = tree[node*2] + tree[node*2 + 1];
}

int query(int node, int l, int r, int s, int e){
	if(l > e || r < s) return 0;
	if(s <= l && e >= r) return tree[node];
	int mid = (l + r) >>1;
	return query(node * 2, l, mid, s, e) + query(node * 2 + 1, mid+1, r, s, e);
}

int lazyTree[400000];
void updateLazy(int node, int l, int r){
	if(lazyTree[node]){
		if(l != r){
			lazyTree[node * 2] += lazyTree[node];
			lazyTree[node * 2 + 1] += lazyTree[node];
			lazyTree[node] = 0;
		}
	}
}

void supUpdate(int node, int l, int r, int idx, int w){
	int s = dfsRange[idx].s, e = dfsRange[idx].e;
	if(l > e || r < s) return;
	if(s <= l && e >= r){
		lazyTree[node] += w; return;
	}
	updateLazy(node, l, r);
	int mid = (l + r) >>1;
	supUpdate(node*2, l, mid, idx, w);
	supUpdate(node*2+1, mid+1, r, idx, w);
}

int supQuery(int node, int l, int r, int idx){
	int t = dfsRange[idx].s;
	if(l > t || r < t) return 0;
	updateLazy(node, l, r);
	if(l == r) return lazyTree[node];
	int mid = (l + r) >>1;
	return supQuery(node * 2, l, mid, idx) + supQuery(node * 2 + 1, mid+1, r, idx);
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

	bool mode = false; 
	int q, i, w;
	while(m--){
		cin>>q;
		if(q == 1){
			cin>>i>>w;
			if(mode) {
				if(dfsRange[i].s != dfsRange[i].e) _update(1, 1, n, dfsRange[i].s, w);
			}else {
				if(i != 1) supUpdate(1, 1,n, i, w);
			}
		}else if(q == 2){
			cin>>i;
			cout<<query(1, 1, n, dfsRange[i].s, dfsRange[i].e) + supQuery(1, 1, n, i)<<"\n";
		}else mode ^= 1;
	}
}