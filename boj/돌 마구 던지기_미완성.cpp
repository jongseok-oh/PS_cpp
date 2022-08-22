#include <iostream>
#include <cstring>
#include <set>

using namespace std;

int r, c,n;

string map[30000];
set<int> balpan[31];

int cache[30000][30];

int getStopLoc(int startR,int locC) {
	int& locR = cache[startR][locC];
	if (locR != -1) {
		while (map[locR][locC] != '.') --locR;
		return locR;
	}
	else {
		locR = startR;
		locR = *balpan[locC].lower_bound(locR);
		return --locR;
	}
}

void move(int startR, int locC) {
	int locR = getStopLoc(startR, locC);
	if (locR == r - 1 || map[locR + 1][locC] == 'X') {
		map[locR][locC] = 'O';
		balpan[locC].insert(locR);
	}
	else if (map[locR + 1][locC] == 'O') {
		if (locC != 0 && map[locR][locC - 1] == '.' && map[locR + 1][locC - 1] == '.') move(locR, locC - 1);
		else if (locC != c - 1 && map[locR][locC + 1] == '.' && map[locR + 1][locC + 1] == '.') move(locR, locC + 1);
		else { map[locR][locC] = 'O'; balpan[locC].insert(locR);}
	}
}

int main(void) {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> r >> c;
	for (int i = 0; i < r; i++)
	{
		cin >> map[i];
		for (int j = 0; j < c; j++) if (map[i][j] == 'X') balpan[j].insert(i);
	}

	for (int i = 0; i < c; i++) balpan[i].insert(r);

	cin >> n;

	memset(cache, -1, sizeof(cache));

	while (n--) {
		int locC; cin >> locC; locC--;
		move(0, locC);
	}

	for (int i = 0; i < r; i++) cout << map[i] << "\n";
}