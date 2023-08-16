#include <iostream>
#include <vector>

using namespace std;

int n;

vector<vector<char>> makeStar(int t) {
	if (t == 3) {
		vector<vector<char>> smallStart(3, vector<char>(3, '*'));
		smallStart[1][1] = ' ';

		return smallStart;
	}

	vector<vector<char>> myStar(t, vector<char>(t, ' '));

	auto littleStar = makeStar(t / 3);

	for (int i = 0; i < 3; i++) for (int j = 0; j < 3; j++) {
		if (i == 1 && j == 1) continue;
		for (int k = 0; k < t / 3; k++) for (int z = 0; z < t / 3; z++) {
			myStar[i * t / 3 + k][j * t / 3 + z] = littleStar[k][z];
		}
	}

	return myStar;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;

	auto star = makeStar(n);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) cout << star[i][j];
		cout << "\n";
	}
}