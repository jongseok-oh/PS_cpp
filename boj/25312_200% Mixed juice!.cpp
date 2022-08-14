#include <iostream>
#include <algorithm>
using namespace std;

long long n, m;

struct juice {
	long long v, w;
	bool const operator < (juice a) const {
		return (double)v/w > (double)a.v/a.w;
	}
};

juice juices[100000];

long long getGcd(long long a, long long b) {
	if (b == 0) return a;
	return getGcd(b, a % b);
}

int main(void) {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;

	for (int i = 0; i < n; i++) cin >> juices[i].w >> juices[i].v;
	
	sort(juices, juices + n);

	long long son = 0; int idx = 0;
	while (idx<n) {
		if (juices[idx].w > m) break;
		m -= juices[idx].w;
		son += juices[idx].v;
		idx++;
	}
	if (idx == n) cout << son<<"/"<<1;
	else {
		son = juices[idx].v * m + son * juices[idx].w;
		long long mother = juices[idx].w;
		long long gcd = getGcd(son, mother);
		son /= gcd; mother /= gcd;
		cout << son << "/" << mother;
	}

	// 문제가 좀 더럽다.
	// 분모 1이면 자연수로 쓰게 처리 다해놨는데
	// 걍 13/1 이렇게 쓰는게 정답이었다.
	// type check 주의, max가 10만인데 계산하는 과정에서 int를 넘을 수 있다.
	// long long으로 변환
}