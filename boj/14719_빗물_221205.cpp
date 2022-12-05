#include <iostream>
#include <algorithm>

using namespace std;
int w,h;

int height[500];

int maxTree[2001];

int init(int start, int end, int node) {
	if (start == end) return maxTree[node] = height[start];

	int mid = (start + end) >> 1;
	
	return maxTree[node] = max(init(start, mid, node * 2), init(mid + 1, end, node * 2 + 1));
}


int getMax(int start, int end, int node, int _left, int _right) {
	if (start > _right || end < _left) return -1;
	
	if (start >= _left && end <= _right) return maxTree[node];
	
	int mid = (start + end) >> 1;

	return max(getMax(start, mid, node * 2, _left, _right), getMax(mid + 1, end, node * 2 + 1, _left, _right));
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> h >> w;
	
	for (int i = 0; i < w; i++) cin >> height[i];
	init(0, w - 1, 1);

	int ans = 0;
	for (int i = 1; i < w - 1; i++) {
		int minh = min(getMax(0, w - 1, 1, 0, i - 1), getMax(0, w - 1, 1, i + 1, w - 1));
		if (minh > height[i]) ans += minh - height[i];
	}
	cout << ans;
}