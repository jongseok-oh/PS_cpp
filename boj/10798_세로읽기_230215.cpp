#include <iostream>

using namespace std;

string words[5];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	for (int i = 0; i < 5; i++) cin >> words[i];

	for (int i = 0; i < 15; i++) for (int j = 0; j < 5; j++)
		if (words[j].size() > i) cout << words[j][i];
}
