#include <iostream>
#include <stdio.h>

using namespace std;

int n, m;

char buffer[20];

bool visit[9] = { false, };

void solve(int cnt) {
	if (cnt == m) {
		puts(buffer); return;
	}
	for (int i = 1; i <= n; i++) {
		if (!visit[i]) {
			visit[i] = true;
			buffer[cnt * 2] = i + '0';
			buffer[cnt * 2 + 1] = ' ';
			solve(cnt + 1);
			visit[i] = false;
		}
	}
}

int main() {
	cin >> n >> m;
	solve(0);
}