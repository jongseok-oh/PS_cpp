#include <iostream>

using namespace std;

int emptyCnt = 0;

struct Loc{
	int y, x;
}emptyLoc[81];

int board[9][9];

int rVisit[9], cVisit[9], sVisit[3][3];

bool fillBoard(int emptyNum) {
	if (emptyNum == emptyCnt) return true;

	for (int num = 1; num < 10; num++) {
		int y = emptyLoc[emptyNum].y;
		int x = emptyLoc[emptyNum].x;

		if (!(rVisit[y] & (1 << num)) && !(cVisit[x] & (1 << num))
			&& !(sVisit[y / 3][x / 3] & (1 << num))) {
			rVisit[y] |= (1 << num);
			cVisit[x] |= (1 << num);
			sVisit[y / 3][x / 3] |= (1 << num);

			board[y][x] = num;

			if (fillBoard(emptyNum + 1)) return true;
			else {
				rVisit[y] ^= (1 << num);
				cVisit[x] ^= (1 << num);
				sVisit[y / 3][x / 3] ^= (1 << num);
			}
		}
	}

	return false;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	for (int i = 0; i < 9; i++) for (int j = 0; j < 9; j++)
	{
		cin >> board[i][j];
		if (!board[i][j]) emptyLoc[emptyCnt++] = { i,j };
		else {
			rVisit[i] |= (1 << board[i][j]);
			cVisit[j] |= (1 << board[i][j]);
			sVisit[i/3][j/3] |= (1 << board[i][j]);
		}
	}

	fillBoard(0);

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++)
			cout << board[i][j] << " ";
		cout << "\n";
	}
}