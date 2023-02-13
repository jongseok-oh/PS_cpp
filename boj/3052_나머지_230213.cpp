#include <iostream>

using namespace std;

bool visit[42];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int num, ans = 0;
	for (int i = 0; i < 10; i++)
	{
		cin >> num;
		if (!visit[num % 42]) {
			ans++;
			visit[num % 42] = true;
		}
	}
	cout << ans;
}
