#include <iostream>

using namespace std;

const int _MAX = 100000 * 32 + 50;

const int ROOT = 1;
int unused = 2;

int Node[_MAX][2];

int m;
bool bitSet[32];

void setBit(int t) {
	for (int i = 31; i >= 0; i--)
	{
		bitSet[i] = t & 1;
		t >>= 1;
	}
}

void insert(int t) {
	setBit(t);

	int cur = ROOT;

	for (int i = 0; i <32; i++) {
		if (!Node[cur][bitSet[i]]) Node[cur][bitSet[i]] = unused++;
		cur = Node[cur][bitSet[i]];
	}
}

int _XOR(int t) {
	setBit(t);
	int ret = 0;
	int cur = ROOT;
	for (int i = 0; i < 32; i++) {
		ret <<= 1;
		if (Node[cur][!bitSet[i]]) {
			ret |= 1;
			cur = Node[cur][!bitSet[i]];
		}
		else cur = Node[cur][bitSet[i]];
	}
	return ret;
}

int n; int numbers[100000];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> numbers[i];
		insert(numbers[i]);
	}

	int ans = -1;
	for (int i = 0; i < n; i++) ans = max(ans, _XOR(numbers[i]));

	cout << ans;
}