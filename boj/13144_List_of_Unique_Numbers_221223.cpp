#include <iostream>

using namespace std;

int n;

int arr[100001];

bool visit[100001];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];

	long long ans = 0;

	for (int l = 0, r = -1; l < n; l++) {
		while (r + 1< n && !visit[arr[r+1]])
			visit[arr[++r]] = true;
		
		visit[arr[l]] = false;
		ans += r - l + 1;
	}
	cout << ans;
}