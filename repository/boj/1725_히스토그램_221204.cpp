#include <iostream>
#include <algorithm>

using namespace std;

int n;

int height[100000];

int solve(int left, int right) {
	if (left == right) return height[left];

	int mid = (left + right) >> 1;
	
	int ret = max(solve(left, mid), solve(mid + 1, right));

	int low = mid, high = mid + 1;

	int h = min(height[low], height[high]);

	ret = max(ret, h * 2);

	while (low > left || high < right) {

		if (high < right && (left == low || height[high + 1] > height[low - 1])) {
			high++;
			h = min(h, height[high]);
		}
		else {
			low--;
			h = min(h, height[low]);
		}

		ret = max(ret, h * (high - low + 1));
	}
	return ret;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i <n; i++) cin >> height[i];
	cout << solve(0, n - 1);
}