#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int n, k;

int pi[1000];

vector<int> program[100];

void make_pi(int start) {
	memset(pi, 0, 4 * k);

	int begin = 1, match = 0;
	while (begin + match < k) {
		if (program[0][start + begin + match] == program[0][start + match]) {
			++match;
			pi[begin + match - 1] = match;
		}
		else {
			if (!match) ++begin;
			else {
				begin += match - pi[match - 1];
				match = pi[match - 1];
			}
		}
	}
}

bool kmp(int start, int idx) {
	int m = program[idx].size();

	// 정방향 탐색
	int begin = 0, match = 0;
	while (begin <= m - k) {
		if (program[idx][begin + match] == program[0][start + match]) {
			++match;
			if (match == k) return true;
		}
		else
		{
			if (!match) ++begin;
			else {
				begin += match - pi[match - 1];
				match = pi[match - 1];
			}
		}
	}

	// 역방향 탐색
	begin = m - 1, match = 0;
	while (begin >= k-1) {
		if (program[idx][begin - match] == program[0][start + match]) {
			++match;
			if (match == k) return true;
		}
		else
		{
			if (!match) --begin;
			else {
				begin -= match - pi[match - 1];
				match = pi[match - 1];
			}
		}
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> k;
	
	int len;
	for (int i = 0; i < n; i++) {
		cin >> len;
		if (len < k) { cout << "NO"; return 0;}
		program[i].resize(len);
		for (int j = 0; j < len; j++){
			cin >> program[i][j];
		}
	}

	int begin = -1;
	while (++begin + k <= program[0].size()) {
		make_pi(begin);

		bool find = true;
		for (int i = 1; i < n; i++) {
			if (!kmp(begin, i)) {
				find = false;
				break;
			}
		}
		if (find) {
			cout << "YES"; return 0;
		}
	}
	cout << "NO";
}