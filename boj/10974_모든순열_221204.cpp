#include <iostream>

using namespace std;

int n;

bool visit[9];
int temp[8];

void print(int idx) {
	if (idx == n) {
		for (int i = 0; i < n; i++)
			cout << temp[i] << " ";
		cout << "\n";
	}

	for (int i = 1; i <= n; i++) {
		if (visit[i]) continue;
		visit[i] = true;
		temp[idx] = i;
		print(idx + 1);
		visit[i] = false;
	}
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	print(0);
}