#include <iostream>

using namespace std;

int alpha[26] = { 0, };

int main(int argc, char** argv)
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	string s; cin >> s;
	for (int i = 0, len = s.size(); i < len; i++) alpha[s[i] - 'a']++;

	for (int i = 0; i < 26; i++) cout << alpha[i] << ' ';
}
