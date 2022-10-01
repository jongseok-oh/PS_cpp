#include <iostream>
#include <stack>

using namespace std;

int r, c, n;
stack<pair<int, int>> s[30];

string board[30000];

void throwStone(int col) {
    if (s[col].empty()) {
        s[col].push({ 0, col });
    }
    else {
        while (true) {
            auto [y, x] = s[col].top();
            if (board[y][x] != 'O') break;
            s[col].pop();
        }
    }
    while (true) {
        int y = s[col].top().first,
            x = s[col].top().second;

        if (y + 1 == r || board[y + 1][x] == 'X') { // 1
            board[y][x] = 'O';
            s[col].pop();
            return;
        }
        if (board[y + 1][x] == '.') {   // 2
            s[col].push({ y + 1,x });
        }
        else { // 3

            if (x > 0 && board[y][x - 1] == '.' && board[y + 1][x - 1] == '.') { // 3.1
                s[col].push({ y + 1,x - 1 }); continue;
            }

            if (x < c - 1 && board[y][x + 1] == '.' && board[y + 1][x + 1] == '.') { // 3.2
                s[col].push({ y + 1,x + 1 }); continue;
            }

            board[y][x] = 'O';
            s[col].pop();
            return; // 3.3
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cout.tie(0);
    cin >> r >> c;
    
    for (int i = 0; i < r; i++) cin >> board[i];

    cin >> n;
    while (n--) {
        int col; cin >> col;
        throwStone(col - 1);
    }

    for (int i = 0; i < r; i++) cout << board[i] << "\n";
}