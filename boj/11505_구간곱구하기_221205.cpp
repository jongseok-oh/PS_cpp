#include <iostream>

using namespace std;

typedef long long ll;
int n,m,k;

int mod = 1e9 + 7;

int arr[1000000];
int tree[4000001];

int init(int start, int end, int node) {
	if (start == end) return tree[node] = arr[start];
	int mid = (start + end) >> 1;
	return tree[node] = (ll)init(start, mid, node * 2) * init(mid + 1, end, node * 2 + 1) % mod;
}
int a, b, c;

int getMult(int start, int end, int node) {
	if (start > c || end < b) return 1;
	if (start >= b && end <= c) return tree[node];

	int mid = (start + end) >> 1;
	return (ll)getMult(start, mid, node * 2) * getMult(mid + 1, end, node * 2 + 1) % mod;
}

void change(int start, int end, int node) {
	if (start > b || end < b) return;
	if (start == end) {tree[node] = c; return;}
	int mid = (start + end) >> 1;
	change(start, mid, node * 2);
	change(mid+1, end, node * 2 + 1);
	tree[node] = (ll)tree[node * 2] * tree[node * 2 + 1] % mod;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m>>k;
	for (int i = 0; i < n; i++) cin >> arr[i];
	init(0, n - 1, 1);
	
	for (int i = 0; i < m + k; i++) {
		cin >> a >> b >> c;
		b--;
		if (a == 1) {
			change(0, n - 1, 1);
		}
		else {
			c--;
			cout << getMult(0, n - 1, 1) << "\n";
		}
	}
}