#include <iostream>
#include <string>
#include <set>

using namespace std;

struct cmp {
	bool operator ()(const string& a,const string& b) const{
		if (a.size() == b.size()) return a < b;
		return a.size() < b.size();
	}
};

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T; cin >> T;
	for (int tt = 1; tt <= T; tt++) {
		int n; cin >> n;
		set<string, cmp> s;
		for (int i = 0; i < n; i++) {
			string t; cin >> t;
			s.insert(t);
		}
		cout << "#" << tt << "\n";
		for (auto it = s.begin(); it != s.end(); it++) cout << *it << "\n";
	}
}