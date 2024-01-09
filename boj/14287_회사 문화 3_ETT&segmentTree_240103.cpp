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
			cin>>w; _update(1, 1, n, dfsRange[i].s, w);
		}else cout<<query(1, 1, n, dfsRange[i].s, dfsRange[i].e)<<"\n";
	}
}