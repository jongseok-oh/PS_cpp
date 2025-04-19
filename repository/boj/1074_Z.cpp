#include <iostream>
#include <math.h>

using namespace std;

int N, r, c;

int solve(int starty, int startx, int len, int startNum) {
	if (len == 2) {
		int rr = r - starty, cc = c - startx;
		return startNum + (rr << 1) + cc;
	}
	int half = len / 2;

	if (r >= starty && r < starty + half && c >= startx && c < startx + half) return solve(starty, startx, half, startNum);
	if (r >= starty && r < starty + half && c >= startx + half && c < startx + len) return solve(starty, startx + half, half, startNum + half * half);
	if (r >= starty + half && r < starty + len && c >= startx && c < startx + half) return solve(starty + half, startx, half, startNum + half * half * 2);
	if (r >= starty + half && r < starty + len && c >= startx + half && c < startx + len) return solve(starty + half, startx + half, half, startNum + half * half * 3);
}

int main() {
	cin >> N >> r >> c;

	cout<<solve(0, 0, pow(2, N), 0);
}