#include <iostream>
#include <algorithm>

using namespace std;

struct node {
	int num, nred, nblue = -1;
};

// start = 0, end = 21
node board[] = {
	{-1,1,-1},{2,2,-1},{4,3,-1},{6,4,-1},{8,5,-1},{10,6, 22},
	{12,7,-1},{14,8,-1},{16,9,-1},{18,10,-1},{20,11,28},
	{22,12,-1,},{24,13,-1},{26,14,-1},{28,15,-1},{30,16,30},
	{32,17,-1},{34,18,-1},{36,19,-1},{38,20,-1},{40,21,-1},{0,-2,-2},
	{13,23,-1},{16,24,-1},{19,25,-1},{25,26,-1},{30,27,-1},{35,20, -1},
	{22,29,-1},{24,25,-1}, {28,31,-1},{27,32,-1},{26,25,-1}
};

int cube[10];

int peice[4] = {0,0,0,0};

int _max = -1;

void solve(int score, int idx) {
	if(idx == 10) { _max = max(_max, score); return;}

	int nmove = cube[idx];
	for (int i = 0; i < 4; i++) {
		if (peice[i] == 21) continue;
		int tmove = nmove;
		int tloc = peice[i];
		int nloc = tloc;
		if (board[peice[i]].nblue != -1) {
			nloc = board[peice[i]].nblue;
			tmove--;
		}
		while (nloc != 21 && tmove--) nloc = board[nloc].nred;

		bool colision = false;
		for (int j = 0; j < 4; j++) {
			if (i == j) continue;
			if (peice[j] == 21) continue;
			if (peice[j] == nloc) {
				colision = true; break;
			}
		}
		
		if (!colision) {
			peice[i] = nloc;
			solve(score + board[nloc].num, idx + 1);
			peice[i] = tloc;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	for (int i = 0; i < 10; i++) cin >> cube[i];
	solve(0,0);
	cout << _max;
}