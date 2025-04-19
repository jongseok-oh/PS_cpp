#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int c, n, q;

unordered_map<int, bool> color31;
unordered_map<int, bool> name31;

int calcHash(int magicNum, string& s) {
	int hash = 0;
	for (char c : s) {
		hash *= magicNum;
		hash += c;
	}

	return hash;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> c >> n;

	while (c--) {
		string color; cin >> color;
		color31[calcHash(31, color)] = true;
	}

	while (n--) {
		string name; cin >> name;
		name31[calcHash(31, name)] = true;
	}

	cin >> q;
	while (q--) {
		string legend; cin >> legend;
		int size = legend.size();

		int leftHash31 = 0;

		bool no = true;
		// rolling hash
		for (int i = 0; i < min(1000, size); i++) {
			leftHash31 *= 31;
			leftHash31 += legend[i];

			if (size - i - 1 > 1000) continue;

			if (color31.find(leftHash31) != color31.end()) {
				string sub = legend.substr(i + 1, size - i - 1);
				int hash = calcHash(31, sub);
				if (name31.find(hash) != name31.end()) {
					cout << "Yes" << "\n";
					no = false; break;
				}
			}
		}

		if (no) cout << "No" << "\n";
	}
}