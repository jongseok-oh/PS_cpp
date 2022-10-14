#include <iostream>

using namespace std;

int blue[6][4];
int green[6][4];

int n;
int score = 0;

int tcon[3] = { 0,2,1 };

void printBlue() {
	cout << "\nBlue\n";
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 6; j++) {
			cout << blue[j][i] << " ";
		}
		cout << "\n";
	}
}

void printGreen() {
	cout << "\nGreen\n";
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 4; j++) {
			cout << green[i][j] << " ";
		}
		cout << "\n";
	}
}

void gravity(int map[][4]) {
	for (int i = 4; i >= 0; i--) {
		for (int j = 0; j < 4; j++) {
			if (map[i][j]) {
				int num = map[i][j];
				if (num < 0) {
					int x2;
					if (j - 1 >= 0 && map[i][j - 1] == num) x2 = j - 1;
					else if (j < 3 && map[i][j + 1] == num) x2 = j + 1;
					int ty = i;
					while (ty < 5 && !map[ty + 1][j] && !map[ty + 1][x2]) ty++;
					if (ty != i) {
						map[i][j] = 0;
						map[i][x2] = 0;
						map[ty][j] = num;
						map[ty][x2] = num;
					}
				}
				else {
					int ty = i;
					while (ty < 5 && !map[ty + 1][j]) ty++;
					if (ty != i) {
						map[i][j] = 0;
						map[ty][j] = num;
					}
				}
			}
		}
	}

}

bool lineCheck(int map[][4]) {
	bool lineboom = false;
	for (int i = 5; i >= 2; i--) {
		bool isLine = true;
		for (int j = 0; j < 4; j++) {
			if (!map[i][j]) {
				isLine = false; break;
			}
		}
		if (isLine) {
			for (int k = 0; k < 4; k++) map[i][k] = false;
			score++;
			lineboom = true;
		}
	}
	if (lineboom) gravity(map);
	return lineboom;
}

void lightlineCheck(int map[][4]) {
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 4; j++) {
			if (map[i][j]) {
				for (int r = 4; r >= 0; r--) for (int c = 0; c < 4; c++)
					map[r + 1][c] = map[r][c];
				for (int c = 0; c < 4; c++)
					map[0][c] = 0;
				break;
			}
		}
	}
}

void simulation(int map[][4], int t, int x, int num) {
	int y = 0;
	if (t == 1) {
		num *= -1;
		int x2 = x + 1;
		while (y < 5 && !map[y + 1][x] && !map[y + 1][x2]) y++;
		map[y][x2] = num;
	}
	else {
		while (y < 5 && !map[y + 1][x]) y++;
	}

	map[y][x] = num;
	if (t == 2) map[y - 1][x] = num;

	while (lineCheck(map));
	lightlineCheck(map);
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i <=n; i++) {
		int t, y, x;
		cin >> t >> y >> x; t--;
		simulation(blue, tcon[t], y, i);
		simulation(green, t, x,i);
		//printBlue();
		//printGreen();
	}
	cout << score << "\n";

	int cnt = 0;

	for (int i = 0; i < 6; i++) for (int j = 0; j < 4; j++) {
		if (blue[i][j]) cnt++;
		if (green[i][j]) cnt++;
	}
	cout << cnt;
}