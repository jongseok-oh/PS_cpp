#include <iostream>

using namespace std;

int alpah[26];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	string t;
	cin >> t;

	for (char& c : t) {
		if (c >= 'a') alpah[c - 'a']++;
		else alpah[c - 'A']++;
	}
	
	int _max = -1;
	char ans;
	for (int i = 0; i < 26; i++) {
		if (alpah[i] > _max) {
			_max = alpah[i];
			ans = i + 'A';
		}
		else if (alpah[i] == _max) ans = '?';
	}
	cout << ans;
}