#include <iostream>
#include <algorithm>

typedef long long ll;

using namespace std;

int n, leafDepth = 0;
int pk[1<<18],w[1<<18], d[1<<18];

int id = 1;
void dfs(int node, int depth){
	if(node * 2 <= n) dfs(node*2, depth + 1);
	pk[id] = node;
	d[id++] = depth;
	if(node * 2 + 1 <= n) dfs(node*2 + 1, depth + 1);
	leafDepth = max(depth, leafDepth);
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin>>n; dfs(1, 0);
	ll ret = -1e9;
	for(int i =1; i<=n; ++i) {
		cin>>w[i];
		ret = max(ret, (ll)w[i]);
	}
	if(ret <= 0) {cout<<ret; return 0;}
	for(int i = 0; i<=leafDepth; ++i) for(int j = i; j<=leafDepth; ++j){
		ll prev = 0;
		for(int k = 1; k<=n; ++k){
			if(d[k] < i || d[k] > j) continue;
			prev = max(prev + w[pk[k]], 0LL);
			ret = max(ret, prev);
		}
	}
	cout<<ret;
}