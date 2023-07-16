#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

int n;
int cnt[10001];

ll calcDiffSum(int mid) {
	ll sum = 0;

	for (int i = 1; i <= 10000; i++)
		sum += (ll)abs(i - mid) * cnt[i];

	return sum;
}

ll calcSqrSum(int mid) {
	ll sum = 0;

	for (int i = 1; i <= 10000; i++)
		sum += (ll)(i - mid) * (i - mid)  * cnt[i];

	return sum;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;

	int LOW = 1e9, HIGH = -1;
	for (int i = 0; i < n; i++) {
		int num; cin >> num;
		LOW = min(LOW, num); HIGH = max(HIGH, num);
		cnt[num]++;
	}

	int low = LOW - 1, high = HIGH;

	while (low + 1 < high) {
		int mid = (low + high) >> 1;

		ll sum1 = calcDiffSum(mid);
		ll sum2 = calcDiffSum(mid + 1);
		
		if (sum1 <= sum2) high = mid;
		else low = mid;
	}

	cout << high << " ";

	low = LOW - 1, high = HIGH;

	while (low + 1 < high) {
		int mid = (low + high) >> 1;

		ll sum1 = calcSqrSum(mid);
		ll sum2 = calcSqrSum(mid + 1);

		if (sum1 <= sum2) high = mid;
		else low = mid;
	}
	cout << high;
}