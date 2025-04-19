#include <iostream>
#include <string>

using namespace std;

int vote[26];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	string str; cin >> str;

	for (int i = 0, len = str.size(); i < len; i++)
		vote[str[i] - 'A']++;

	int uvote = vote['U' - 'A'] + vote['C' - 'A'];
	int dpvote = vote['D' - 'A'] + vote['P' - 'A'];
	bool pprint = false;
	if (uvote > (dpvote+1)/2) {
		pprint = true;
		cout << 'U';
	}
	if (dpvote) {
		pprint = true;
		cout << "DP";
	}
	if (!pprint) cout << 'C';
}