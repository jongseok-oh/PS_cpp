#include <iostream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

const int bigStart = 26, numStart = 52;

string A, W, S;

int AIdx[62];

int pi[50000];

char convertChar(char t, int shift) {
	int Asize = A.size();

	int idx = -1e9;

	if (t >= 'A' && t <= 'Z') idx = AIdx[t - 'A' + bigStart];
	else if (t >= '0' && t <= '9') idx = AIdx[t - '0' + numStart];
	else idx = AIdx[t - 'a'];

	return A[(idx + shift) % Asize];
}

void make_pi(int shift) {
	int n = W.size();

	int begin = 1, match = 0;
	while (begin + match < n)
	{
		
		if (convertChar(W[begin + match], shift) == convertChar(W[match], shift)) {
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

bool kmp(int shift) {
	int n = W.size(), m = S.size();

	int cnt = 0;
	int begin = 0, match = 0;
	while (begin <= m - n) {
		if (match < n && S[begin + match] == convertChar(W[match], shift)) {
			++match;
			if (match == n) {
				if (cnt) return false;
				else cnt++;
			}
		}
		else {
			if (!match) ++begin;
			else {
				begin += match - pi[match - 1];
				match = pi[match - 1];
			}
		}
	}

	return cnt == 1;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int T; cin >> T;
	while (T--) {
		cin >> A >> W >> S;

		int Asize = A.size();

		for (int i = 0; i < Asize; i++) {
			char t = A[i];
			if (t >= 'A' && t <= 'Z') AIdx[t - 'A' + bigStart] = i;
			else if(t >= '0' && t <= '9') AIdx[t - '0' + numStart] = i;
			else AIdx[t - 'a'] = i;
		}

		vector<int> ansShift;

		for (int shift = 0; shift < Asize; shift++) {
			make_pi(shift);
			if (kmp(shift)) ansShift.push_back(shift);
		}

		int cnt = ansShift.size();

		if (!cnt) cout << "no solution\n";
		else if (cnt == 1)cout << "unique: " << ansShift[0] << "\n";
		else {
			cout << "ambiguous:";
			for (int aShift : ansShift) cout << " " << aShift;
			cout << "\n";
		}
	}
}