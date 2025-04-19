#include <iostream>
using namespace std;

int n;

int play[50][9];

int answ = -1;

int order[9];
bool visit[9] = { false, };

void playBaseBall() {
	int inning = 0;
	int score = 0;
	int idx = 0;
	while (true) {
		int out = 0;
		bool base[3] = { false, false, false};
		while (out < 3) {
			int player = order[idx];
			
			int swing = play[inning][player];
			int cnt = 0;
			switch (swing) {
				case 0:
					out++; break;
				case 1:
					if (base[2]) { base[2] = false; score++;}
					if (base[1]) { base[2] = true; base[1] = false;}
					if (base[0]) { base[1] = true; base[0] = false;}
					base[0] = true; break;
				case 2:
					if (base[2]) { base[2] = false; score++; }
					if (base[1]) { base[1] = false; score++; }
					if (base[0]) { base[2] = true; base[0] = false; }
					base[1] = true; break;
				case 3:
					for (int i = 0; i < 3; i++)
						if (base[i]) {base[i] = false; cnt++;}
					score += cnt;
					base[2] = true; break;
				case 4:
					for (int i = 0; i < 3; i++)
						if (base[i]) {base[i] = false; cnt++;}
					score += (cnt + 1);
			}
			idx = (idx + 1) % 9;
		}
		inning++;
		if (inning == n) break;
	}
	answ = score > answ ? score : answ;
}

void makeOrder(int cnt) {
	if (cnt == 3) { makeOrder(cnt + 1); return;}
	if (cnt == 9) {
		playBaseBall();
		return;
	}
	for (int i = 1; i < 9; i++) {
		if (!visit[i]) {
			visit[i] = true;
			order[cnt] = i;
			makeOrder(cnt + 1);
			visit[i] = false;
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;

	for (int i = 0; i < n; i++) for (int j = 0; j < 9; j++) cin >> play[i][j];

	order[3] = 0;
	makeOrder(0);
	cout << answ;
}