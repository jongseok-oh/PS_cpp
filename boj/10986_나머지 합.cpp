#include <iostream>

using namespace std;

int n, m;

long long modCnt[1000];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n >> m;
	
	long long sum = 0;
	for (int i = 0; i < n; i++) {
		long long a; cin >> a;
		sum = (sum + a) % m;
		modCnt[sum]++;
	}

	long long answer = modCnt[0];
	
	for (int i = 0; i < m; i++) answer += modCnt[i] * (modCnt[i] - 1) / 2;
	cout << answer;
}