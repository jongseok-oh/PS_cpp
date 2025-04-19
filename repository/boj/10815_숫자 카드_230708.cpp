#include <iostream>
#include <unordered_set>

using namespace std;

int n, m;

unordered_set<int> s;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		int num; cin >> num;
		s.insert(num);
	}

	cin >> m;
	for (int i = 0; i < m; i++) {
		int num; cin >> num;
		if (s.find(num) == s.end()) cout << "0 ";
		else cout << "1 ";
	}
}