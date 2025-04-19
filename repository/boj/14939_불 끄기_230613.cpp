#include <iostream>

using namespace std;

int map[12];
int tempMap[12];

int dy[] = { -1,0,0,0,1 }, dx[] = { 0,-1,0,1,0 };

void click(int y, int x) {
	for (int dir = 0; dir < 5; dir++) {
		int ny = y + dy[dir],
			nx = x + dx[dir];

		tempMap[ny] ^= (1 << nx);
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int mask = 0x03ff << 1;

	for (int i = 1; i <= 10; i++) {
		int line = 0;
		for (int j = 1; j <=10; j++) {
			char state; cin >> state;
			if (state == 'O') line |= (1 << j);
		}
		map[i] = line;
	}

	int ans = 101;
	for (int bt = 0; bt < (1 << 10); bt++) {

		int bbt = bt << 1;


		int cnt = 0;
		for (int i = 1; i <= 10; i++)
			tempMap[i] = map[i];

		for (int i = 1; i <= 10; i++)
			if (bbt & (1 << i)) {
				click(1, i); cnt++;
			}

		for(int i = 2; i<=10; i++) for(int j = 1; j<=10; j++)
			if (tempMap[i - 1] & (1 << j)) {
				click(i, j); cnt++;
			}

		if (!(tempMap[10] & mask))
			ans = min(ans, cnt);
	}

	cout << (ans == 101 ? -1 : ans);
}