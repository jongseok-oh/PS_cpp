#include <iostream>
#include <vector>

using namespace std;

const int _MAX = 200000 * 32 + 50;

const int ROOT = 1;
int unused = 2;

int Node[_MAX][2];

int m;
bool bitSet[32];
int cnt[_MAX];

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
	cnt[cur]++;
}

void erase(int t) {
	setBit(t);

	vector<int> nodes;

	int cur = ROOT;
	nodes.push_back(cur);
	for (int i = 0; i < 32; i++) {
		cur = Node[cur][bitSet[i]];
		nodes.push_back(cur);
	}
	cnt[cur]--;
	if (!cnt[cur]) {
		for (int i = nodes.size() - 1; i > 0; i--) {
			if (!Node[nodes[i]][0] && !Node[nodes[i]][1]) {
				Node[nodes[i - 1]][bitSet[i - 1]] = 0;
			}
			else break;
		}
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

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	insert(0);

	cin >> m;
	while (m--) {
		int mode, x; cin >> mode >> x;

		if (mode == 1) { insert(x); }
		else if (mode == 2) { erase(x);}
		else {cout << _XOR(x) << "\n";}
	}
}