#include <iostream>

using namespace std;

bool board[10][10];

int score = 0;

bool blueCheck(int x) {
	bool chk = true;
	for(int y = 0; y<4; y++)
		if (!board[y][x]) {
			chk = false; break;
		}
	
	if (chk) {
		score++;
		for (int i = x - 1; i >= 4; i--) {
			for (int j = 0; j < 4; j++) {
				board[j][i + 1] = board[j][i];
			}
		}
		for (int j = 0; j < 4; j++) board[j][4] = false;
	}
	return chk;
}

bool greenCheck(int y) {
	bool chk = true;
	
	for (int x = 0; x < 4; x++) {
		if (!board[y][x]) {
			chk = false; break;
		}
	}

	if (chk) {
		score++;
		for (int i = y - 1; i >= 4; i--) {
			for (int j = 0; j < 4; j++) {
				board[i+1][j] = board[i][j];
			}
		}
		for (int j = 0; j < 4; j++) board[4][j] = false;
	}
	return chk;
}

void printBlue() {
	cout << "Blue" << "\n";
	for (int i = 0; i < 4; i++) {
		for (int j = 4; j < 10; j++) {
			cout << board[i][j] << " ";
		}
		cout << "\n";
	}
}

void printGreen() {
	cout << "Green" << "\n";

	for (int i = 4; i < 10; i++) {
		for (int j = 0; j < 4; j++)
			cout << board[i][j] << " ";
		cout << "\n";
	}
}

void blue(int t, int y, int x) {
	if (t == 1) {
		while (x +1 < 10 && !board[y][x + 1]) x++;
	}
	else if (t == 2) {
		x++;
		while (x + 1 < 10 && !board[y][x + 1]) x++;
		board[y][x-1] = true;
	}
	else {
		int y2 = y + 1;
		while (x + 1 < 10 && !board[y][x + 1] && !board[y2][x + 1]) x++;
		board[y2][x] = true;
	}
	board[y][x] = true;

	// check line
	for (int i = 9; i >= 4;) {
		if (!blueCheck(i)) i--;
	}

	// check light line
	for (int i = 4; i <= 5; i++) {
		bool chk = false;
		for(int j = 0; j<4; j++)
			if (board[j][i]) {
				chk = true; break;
			}
		
		if (chk) {
			for (int i = 8; i >= 4; i--) {
				for (int j = 0; j < 4; j++) {
					board[j][i + 1] = board[j][i];
				}
			}
			for (int j = 0; j < 4; j++) board[j][4] = false;
		}
	}
}

void green(int t, int y, int x) {
	if (t == 1) {
		while (y + 1 < 10 && !board[y+1][x]) y++;
	}
	else if (t == 2) {
		int x2 = x + 1;
		while (y + 1 < 10 && !board[y+1][x] && !board[y + 1][x2]) y++;
		board[y][x2] = true;
	}
	else {
		y++;
		while (y + 1 < 10 && !board[y + 1][x]) y++;
		board[y - 1][x] = true;
	}
	board[y][x] = true;

	// check line
	for (int i = 9; i >= 4;) {
		if (!greenCheck(i)) i--;
	}

	// check light line
	for (int i = 4; i <= 5; i++) {
		bool chk = false;
		for (int j = 0; j < 4; j++)
			if (board[i][j]) {
				chk = true; break;
			}
		if (chk) {
			for (int i = 8; i >= 4; i--) {
				for (int j = 0; j < 4; j++) {
					board[i+1][j] = board[i][j];
				}
			}
			for (int j = 0; j < 4; j++) board[4][j] = false;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	while (n--) {
		int t, x, y; cin >> t >> x >> y;
		blue(t, x, y);
		green(t,x,y);
		//printBlue();
		//printGreen();
	}
	cout << score << "\n";
	int block = 0;
	for (int i = 0; i < 10; i++) for (int j = 0; j < 10; j++)
		if (board[i][j])  block++;
	cout << block;
}
