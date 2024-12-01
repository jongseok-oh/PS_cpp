#include <iostream>
#include <string>
#include <queue>
#include <unordered_map>
#include <algorithm>
#include <limits>

using namespace std;

class AhoCorasick {
	struct Node {
		unordered_map<char, int> child;
		int fail = -1;
		int size = 1e9;
	};
	int root = 0;
	vector<Node> trie;
	int getNode() {
		trie.emplace_back(Node());
		return trie.size() - 1;
	}
public:
	AhoCorasick() {
		root = getNode();
	}
	void insert(string& str) {
		int temp = root;
		for (char c : str) {
			if (!trie[temp].child.count(c)) {
				trie[temp].child[c] = getNode();
			}
			temp = trie[temp].child[c];
		}
		trie[temp].size = str.size();
	}
	void buildFail() {
		queue<int> q;
		trie[root].fail = root;
		for (auto& [c, next] : trie[root].child) {
			trie[next].fail = root;
			q.push(next);
		}

		while (q.size()) {
			int parent = q.front(); q.pop();

			for (auto& [c, next] : trie[parent].child) {
				int fail = trie[parent].fail;
				while (fail != root && !trie[fail].child.count(c)) {
					fail = trie[fail].fail;
				}
				if (trie[fail].child.count(c)) {
					trie[next].fail = trie[fail].child[c];
				}
				else trie[next].fail = root;

				trie[next].size = min(trie[next].size, trie[trie[next].fail].size);
				q.push(next);
			}
		}
	}

	int search(string& str) {
		int temp = root;
		vector<pair<int, int>> matches;
		for (int i = 0, n = str.size(); i < n; ++i) {
			char c = str[i];
			while (temp != root && !trie[temp].child.count(c)) {
				temp = trie[temp].fail;
			}
			if (trie[temp].child.count(c)) {
				temp = trie[temp].child[c];
				int matchSize = trie[temp].size;
				if (matchSize != 1e9) {
					matches.emplace_back(i - matchSize + 1, i);
				}
			}
		}

		sort(matches.begin(), matches.end());
		int ret = 0, containEnd = -1;
		for (auto [start, end] : matches) {
			if (containEnd >= start) {
				containEnd = min(containEnd, end);
			}
			else {
				++ret;
				containEnd = end;
			}
		}

		return ret;
	}

	void clear() {
		trie.clear();
		getNode();
	}
};

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n, m;
	AhoCorasick ac;
	while (true) {
		cin >> n >> m;
		if (n == 0 && m == 0) break;
		ac.clear();

		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		string emoticon;
		while (n--) {
			getline(cin, emoticon);
			ac.insert(emoticon);
		}
		ac.buildFail();

		int ret = 0;
		string text;
		while (m--) {
			getline(cin, text);
			ret += ac.search(text);
		}
		cout << ret << "\n";
	}
}