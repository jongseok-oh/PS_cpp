#include <iostream>
#include <map>
#include <vector>

using namespace std;

const int _MAX = 500 * 80;
const int ROOT = 1;

int unused = 2;

map<string, int> nodes[_MAX];
int depth[_MAX];

void insert(string& t) {
	string temp = "";
	vector<string> dirs;
	for (int i = 0; i <= t.size(); i++) {
		if (i == t.size() || t[i] == '\\') {
			dirs.push_back(temp);
			temp = "";
		}
		else temp.push_back(t[i]);
	}

	int cur = ROOT;
	int tDepth = 0;

	for (int i = 0; i < dirs.size(); i++) {
		depth[cur] = tDepth++;
		auto it = nodes[cur].find(dirs[i]);
		if (it == nodes[cur].end()) {
			nodes[cur].insert({ dirs[i], unused });
			cur = unused++;
		}
		else cur = it->second;
	}
}

void Print(int node) {

	for (auto it = nodes[node].begin(); it != nodes[node].end(); it++) {
		for (int i = 0; i < depth[node]; i++) cout << " ";

		cout << it->first << "\n";
		Print(it->second);
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	while (n--) {
		string str; cin >> str;
		insert(str);
	}

	Print(ROOT);
}