#include <iostream>
#include <cstring>

using namespace std;

int n;

int visit[15];

// 3800ms?.. 뭔가 잘못 푼 듯하다.

int solve(int r) {
	
	if (r == n) return 1;

	int ret = 0;

	for (int i = 0; i <n; i++) {
			bool flag = true;
			
			for (int j = 0; j < r; j++) {
				if (visit[j] == i || visit[j] + j == i + r || visit[j] - j == i - r) {
					flag = false; break;
				}
			}
			if (flag) {
				visit[r] = i;
				ret += solve(r + 1);
				visit[r] = -1;
			}
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	memset(visit, -1, sizeof(visit));
	cout<<solve(0);
}