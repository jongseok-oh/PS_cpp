#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(0); cin.tie(0);
	while (1) {
		string t;
		getline(cin, t);
		if (t == ".") return 0;
		stack<char> s;
		bool yes = true;
		for (int i = 0, len = t.size(); i < len; i++) {
			char tt = t[i];
			if ( tt== '(' || tt == '[') s.push(tt);
			else if (tt == ')' || tt == ']') {
				if (s.empty()) { yes = false; break;}
				if (s.top() == '(' && tt == ')') s.pop();
				else if (s.top() == '[' && tt == ']') s.pop();
				else { yes = false; break;}
			}
		}
		if (!s.empty()) yes = false;
		if (yes) cout << "yes" << "\n";
		else cout << "no" << "\n";
	}
}