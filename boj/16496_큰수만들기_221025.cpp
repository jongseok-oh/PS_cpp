#include <iostream>
#include <algorithm>
using namespace std;
int n;
string list[1000];

bool cmp(string& a, string& b){
	return a + b > b + a;
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> list[i];
	sort(list, list + n, cmp);
	if (list[0] == "0") {
		cout << '0'; return 0;
	}
	for (int i = 0; i < n; i++)cout << list[i];
}