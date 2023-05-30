#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;
bool board[10][10];

struct Loc { int y, x; };

int leftDiag[] = { 1, -1 }, rightDiag[] = { 1, 1 };

void saveMarking(int y, int x,vector<Loc>& marker) {
	
	int ly = y, lx = x;
	while (ly < n && lx >= 0) {
		if (board[ly][lx]) {
			marker.push_back({ ly,lx });
			board[ly][lx] = false;
		}
		ly += leftDiag[0], lx += leftDiag[1];
	}

	int ry = y, rx = x;
	while (ry < n && rx < n) {
		if (board[ry][rx]) {
			marker.push_back({ ry,rx });
			board[ry][rx] = false;
		}
		ry += rightDiag[0], rx += rightDiag[1];
	}
}

void removeMarking(vector<Loc>& marker) {
	for (auto& loc : marker) board[loc.y][loc.x] = true;
}

int solve(int y, int x, bool black) {
	
	int ret = 0;

	int j = x;
	for (int i = y; i < n; i++) {
		for (; j < n; j += 2) {
			if (board[i][j]) {
				vector<Loc> marker;
				
				saveMarking(i, j, marker);
				ret = max(ret, 1 + solve(i, j + 2, black));
				removeMarking(marker);
			}
		}
		j = (i & 1 ? 0 : 1);
		if (!black) j ^= 1;
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++)
		cin >> board[i][j];

	int black = solve(0, 0, true);
	int white = solve(0, 1, false);

	cout << black + white;
}