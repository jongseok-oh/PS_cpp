#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

string num;
int n,k;
char ans[500001];
int unuse;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n>>k>>num;

	int idx = 0;
	while (true) {
		if (idx + k >=n) break;
		int max_idx = -1;
		char max_value = -1;
		for (int i = idx; i <= idx + k; i++) {
			if (max_value < num[i]) {
				max_value = num[i];
				max_idx = i;
			}
			if (max_value == '9') break;
		}
		ans[unuse++] = max_value;
		k -= max_idx - idx;
		idx = max_idx + 1;
	}
	puts(ans);
}