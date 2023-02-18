#include <iostream>
#include <algorithm>

using namespace std;

int board[100000][3];
int min_board[3], max_board[3];
int tmin[3], tmax[3];

int _min = 1e9, _max = 0;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	for (int i = 0; i < n; i++) for (int j = 0; j < 3; j++)
		cin >> board[i][j];
	
	for (int i = 0; i < 3; i++) 
		max_board[i] = min_board[i] = board[n - 1][i];
	
	
	for (int i = n - 2; i >= 0; i--) {
		for (int j = 0; j < 3; j++) {
			tmin[j] = board[i][j]
				+ min({ (j - 1 >= 0 ? min_board[j - 1] : _min),
					min_board[j],
					(j + 1 <= 2 ? min_board[j + 1] : _min) });

			tmax[j] = board[i][j]
				+ max({ (j - 1 >= 0 ? max_board[j - 1] : _max),
					max_board[j],
					(j + 1 <= 2 ? max_board[j + 1] : _max) });
		}
		for (int j = 0; j < 3; j++) {
			min_board[j] = tmin[j];
			max_board[j] = tmax[j];
		}
	}
	cout << max({ max_board[0], max_board[1], max_board[2] }) << " "
		<< min({ min_board[0], min_board[1], min_board[2] });
}
