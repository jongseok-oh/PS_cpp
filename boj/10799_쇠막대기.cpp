#include <iostream>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(0); cin.tie(0);
	string stick;
	cin >> stick;

	int answer = 0, size = 0;
	bool islazor = false;
	for (int i = 0, len = stick.size(); i < len; i++) {
		char t = stick[i];
		if (t == '(') { size++; islazor = true;}
		else {
			size--;
			if (islazor) answer += size;
			else answer++;
			islazor = false;
		}
	}
	cout << answer;
}