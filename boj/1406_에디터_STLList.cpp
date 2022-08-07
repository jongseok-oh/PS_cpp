#include <iostream>
#include <list>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(0); cin.tie(0);
	list<char> l;
	string s; cin >> s;
	for (int i = 0, len = s.size(); i < len; i++) l.push_back(s[i]);
	auto cursor = l.end();

	int n; cin >> n;
	while (n--)
	{
		char cmd; cin >> cmd;
		switch (cmd) {
			case 'L':
				if (cursor != l.begin()) cursor--;
				break;
			case 'D':
				if (cursor != l.end()) cursor++;
				break;
			case 'B':
				if (cursor != l.begin()) {
					cursor--;
					cursor = l.erase(cursor);
				}
				break;
			default:
				char s; cin >> s;
				l.insert(cursor, s);
		}
	}

	for (auto it = l.begin(); it != l.end(); it++) cout << *it;
}
