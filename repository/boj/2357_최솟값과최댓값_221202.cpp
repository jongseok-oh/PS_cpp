#include <iostream>
#include <algorithm>

using namespace std;

int n, m;

int arr[100001];
int mintree[400001];
int maxtree[400001];

int minInit(int start, int end, int node) {
	if (start == end) return mintree[node] = arr[start];
	
	int mid = (start + end) >> 1;

	return mintree[node] = min(minInit(start, mid, node * 2), minInit(mid + 1, end, node * 2 + 1));
}

int maxInit(int start, int end, int node) {
	if (start == end) return maxtree[node] = arr[start];

	int mid = (start + end) >> 1;

	return maxtree[node] = max(maxInit(start, mid, node * 2), maxInit(mid + 1, end, node * 2 + 1));
}

int a, b;

int getMin(int start, int end, int node) {
	if (start > b || end < a) return 1e9;
	
	if (start >= a && end <= b) return mintree[node];
	
	int mid = (start + end) >> 1;
	return min(getMin(start, mid, node * 2), getMin(mid + 1, end, node * 2 + 1));
}

int getMax(int start, int end, int node) {
	if (start > b || end < a) return 0;

	if (start >= a && end <= b) return maxtree[node];

	int mid = (start + end) >> 1;
	return max(getMax(start, mid, node * 2), getMax(mid + 1, end, node * 2 + 1));
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> arr[i];
	minInit(1, n, 1);
	maxInit(1, n, 1);

	while (m--)
	{
		cin >> a >> b;
		cout << getMin(1, n, 1) << " " << getMax(1, n, 1) << "\n";
	}
}