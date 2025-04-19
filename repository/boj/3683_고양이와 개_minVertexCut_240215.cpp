#include <iostream>
#include <cstring>
#include <vector>
#include <string>

using namespace std;

int T, c,d,v, n,m;

struct LH {
	int love, hate;
};

vector<LH> catLover;
vector<LH> dogLover;

vector<int> con[500];

int catMatch[500], dogMatch[500];

bool visit[500];
bool dfs(int cat) {
	if (visit[cat]) return false;
	visit[cat] = true;
	for (int dog : con[cat]) {
		if (dogMatch[dog] == -1 || dfs(dogMatch[dog])) {
			catMatch[cat] = dog;
			dogMatch[dog] = cat;
			return true;
		}
	}
	return false;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> T;
	while (T--)
	{
		cin >> c >> d >> v;

		catLover.clear(); dogLover.clear();

		string love, hate;
		for (int i = 0; i < v; ++i) {
			cin >> love >> hate;
			int loveNum = stoi(love.substr(1)), hateNum = stoi(hate.substr(1));

			if (love[0] == 'C') catLover.push_back({ loveNum, hateNum });
			else dogLover.push_back({ loveNum, hateNum });
		}

		n = catLover.size(), m = dogLover.size();

		for (int i = 0; i < n; ++i) con[i].clear();

		for (int i = 0; i <n; ++i) for (int j = 0; j <m; ++j) {
			if (catLover[i].love == dogLover[j].hate || catLover[i].hate == dogLover[j].love)
				con[i].push_back(j);
		}

		memset(catMatch, -1, 4 * n);
		memset(dogMatch, -1, 4 * m);

		int ret = v;
		for (int i = 0; i < n; ++i) {
			memset(visit, 0, n);
			if (dfs(i)) --ret;
		}

		cout << ret<<"\n";
	}
}