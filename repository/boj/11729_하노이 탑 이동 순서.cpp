#include <iostream>
using namespace std;

int n;

struct ft {int from, to;};

ft buffer[1 << 20];

int idx = 0;
void hanoi(int num, int from, int to) {
	if (num == 1) { buffer[idx++] = { from,to }; return;}
	hanoi(num - 1, from, to ^ from);
	buffer[idx++] = { from, to };
	hanoi(num - 1, to ^ from, to);
}

int main(void) {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	hanoi(n, 1, 3);
	cout << idx << "\n";
	for (int i = 0; i < idx; i++) cout << buffer[i].from << " " << buffer[i].to << "\n";
}