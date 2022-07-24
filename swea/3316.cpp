#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

const int mod = 1000000007;

int cache[16][10000];

int main(int argc, char** argv)
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int test_case;
	int T;
	//freopen("input.txt", "r", stdin);
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		string s; cin >> s;
		memset(cache, 0, sizeof(cache));
		
		for (int i = 0, n = s.size(); i < n; i++) {
			int admin = s[i] - 'A';

			for (int j = 1; j < 16; j++) {
				if (i == 0) {
					if ((j & (1 << 0)) && (j & (1 << admin))) {
						cache[j][0] = 1;
					}
				}
				else {
					if (!(j & (1 << admin))) continue;

					for (int yesterday = 1; yesterday < 16; yesterday++) {
						if(yesterday & j){
							cache[j][i] += cache[yesterday][i - 1];
							cache[j][i] %= mod;
						}
					}
				}
			}
		}
		int answer = 0;
		for (int i = 1; i < 16; i++) {
			answer += cache[i][s.size() - 1];
			answer %= mod;
		}
		cout << "#" << test_case << " " << answer << "\n";
	}
	return 0;
}