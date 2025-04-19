#include <iostream>
#include <string>
using namespace std;

string a, b;

int n;

bool visit[10];
string temp(' ',10);
string ans;

bool comp() {
	if (n < b.size()) return true;
	return temp < b;
}

void premute(int idx) {
	if (idx == n) {
		if (comp() && temp > ans) ans = temp;
	}
	for (int i = 0; i < n; i++) {
		if (visit[i]) continue;
		visit[i] = true;
		temp[idx] = a[i];
		premute(idx + 1);
		visit[i] = false;
	}
}

string solve() {
	if (a.size() > b.size()) return "-1";
	premute(0);
	if (ans[0] == '0') return "-1";
	if (ans == "") return "-1";
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> a >> b;
	n = a.size();
	cout << solve();
}