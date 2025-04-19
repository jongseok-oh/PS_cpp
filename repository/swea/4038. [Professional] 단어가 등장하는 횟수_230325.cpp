#include <iostream>
#include <string>

using namespace std;

const int EXPONENT1 = 31;
const int EXPONENT2 = 37;
const int EXPONENT3 = 43;

int solve(string& book, string& target) {
	int blen = book.size(), tarlen = target.size();

	if (blen < tarlen) return 0;

	// target 문자열의 해쉬 값 세개
	int tarhash1 = 0;
	int tarhash2 = 0;
	int tarhash3 = 0;

	// book의 부분 문자열의 해쉬 값 세개
	int bookhash1 = 0;
	int bookhash2 = 0;
	int bookhash3 = 0;

	// 제곱수
	int pos1 = 1;
	int pos2 = 1;
	int pos3 = 1;
	
	// init
	for (int i = 0; i < tarlen; i++) {
		tarhash1 = tarhash1 * EXPONENT1 + target[i];
		tarhash2 = tarhash2 * EXPONENT2 + target[i];
		tarhash3 = tarhash3 * EXPONENT3 + target[i];
		
		bookhash1 = bookhash1 * EXPONENT1 + book[i];
		bookhash2 = bookhash2 * EXPONENT2 + book[i];
		bookhash3 = bookhash3 * EXPONENT3 + book[i];

		if (i < tarlen - 1) {
			pos1 *= EXPONENT1;
			pos2 *= EXPONENT2;
			pos3 *= EXPONENT3;
		}
	}
	int ret = 0;
	if (tarhash1 == bookhash1 && tarhash2 == bookhash2 && tarhash3 == bookhash3) ret++;

	for (int i = 1; i < blen - tarlen + 1; i++) {
		bookhash1 = (bookhash1 - book[i - 1] * pos1) * EXPONENT1 + book[i + tarlen -1];
		bookhash2 = (bookhash2 - book[i - 1] * pos2) * EXPONENT2 + book[i + tarlen - 1];
		bookhash3 = (bookhash3 - book[i - 1] * pos3) * EXPONENT3 + book[i + tarlen - 1];

		if (tarhash1 == bookhash1 && tarhash2 == bookhash2 && tarhash3 == bookhash3) ret++;
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T; cin >> T;
	for (int tt = 1; tt <= T; tt++) {
		string a, b; cin >> a >> b;
		cout << "#" << tt << " " << solve(a, b) << "\n";
	}
}