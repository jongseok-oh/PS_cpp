#include <iostream>
#include <cstring>

using namespace std;

int n, m;
int ans = 0;

int map[49][49];
int bizz[2600];
int tempbizz[2600];

int half;

int dy[] = { -1,1,0,0 }, dx[] = { 0,0,-1,1 };
int rdy[] = { 0,1,0,-1 }, rdx[] = { -1,0,1,0 };

void Print() {
	cout << "\n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << map[i][j] << " ";
		}
		cout << "\n";
	}
}

void blizzard(int d, int s) {
	for (int i = 1; i <= s; i++) 
		map[half + i * dy[d]][half + i * dx[d]] = 0;
	
	int len = 1, mcnt = 0, dir = 0;
	int y = half, x = half;
	int idx = 0;

	memset(bizz, 0, sizeof(bizz));

	while (true) {
		int tlen = 0;
		while (tlen < len) {
			y += rdy[dir];
			x += rdx[dir];
			bizz[idx++] = map[y][x];
			if (y == 0 && x == 0) return;
			tlen++;
		}
		mcnt++;
		dir = (dir + 1) % 4;
		if (mcnt == 2) {
			mcnt = 0;
			len++;
		}
	}
	//Print();
}

void explosion() {
	while (true) {
		
		int i = 0;
		bool boom = false;
		while (i < n*n + 10 && !bizz[i]) i++;

		int tstart = i;
		int tbizz = bizz[i++];
		int sameCnt = 1;

		for (; i < n*n + 10; i++) {
			if (bizz[i] == 0) continue;
			if (tbizz != bizz[i]) {
				if (sameCnt >= 4) {
					ans += tbizz * sameCnt;
					boom = true;
					for (int j = tstart; j < i; j++)
						bizz[j] = 0;
				}
				sameCnt = 1;
				tbizz = bizz[i];
				tstart = i;
			}
			else sameCnt++;
		}

		if (sameCnt >= 4) {
			ans += tbizz * sameCnt;
			boom = true;
			for (int j = tstart; j < i; j++)
				bizz[j] = 0;
		}
		if (!boom) return;
	}
}
void change() {
	memset(tempbizz, 0, sizeof(tempbizz));
	int i = 0;
	while (i < n*n + 10 && !bizz[i]) i++;
	int tbizz = bizz[i++];
	int sameCnt = 1;
	int idx = 0;

	for (; i < n*n + 10; i++) {
		if (bizz[i] == 0) continue;
		if (tbizz != bizz[i]) {
			tempbizz[idx] = sameCnt;
			tempbizz[idx + 1] = tbizz;

			idx += 2; if (idx > n*n + 10) break;
			
			sameCnt = 1;
			tbizz = bizz[i];
		}
		else sameCnt++;
	}

	if (idx != 0) {
		tempbizz[idx] = sameCnt;
		tempbizz[idx + 1] = tbizz;
	}

	int len = 1, mcnt = 0, dir = 0;
	int y = half, x = half;
	idx = 0;

	while (true) {
		int tlen = 0;
		while (tlen < len) {
			y += rdy[dir];
			x += rdx[dir];
			map[y][x] = tempbizz[idx++];
			if (y == 0 && x == 0) return;
			tlen++;
		}
		mcnt++;
		dir = (dir + 1) % 4;
		if (mcnt == 2) {
			mcnt = 0;
			len++;
		}
	}
}



int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++)
		cin >> map[i][j];

	half = n/2;

	while (m--) {
		int d, s; cin >> d >> s;
		blizzard(--d, s);
		explosion();
		change();
		//Print();
	}
	cout << ans;
}