#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 360000;

int n;
int arr1[200000];
int arr2[200000];


int pi[200000];
int diff1[200000];
int diff2[200000];

void make_pi() {
	int begin = 1, match = 0;

	while (begin + match < n) {
		if (diff1[begin + match] == diff1[match]) {
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

bool solve() {
	int begin = 0, match = 0;
	while (begin < n) {
		if (diff1[match] == diff2[(begin + match) % n]) {
			++match;
			if (match == n) return true;
		}
		else {
			if (!match) ++begin;
			else {
				begin += match - pi[match - 1];
				match = pi[match - 1];
			}
		}
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;

	for (int i = 0; i < n; i++) cin >> arr1[i];

	for (int i = 0; i < n; i++) cin >> arr2[i];

	sort(arr1, arr1 + n);
	sort(arr2, arr2 + n);

	for (int i = 0; i < n - 1; i++) {
		diff1[i] = arr1[i + 1] - arr1[i];
		diff2[i] = arr2[i + 1] - arr2[i];
	}
	
	diff1[n-1] = arr1[0] + MAX - arr1[n-1];
	diff2[n-1] = arr2[0] + MAX - arr2[n-1];

	make_pi();
	cout<<(solve() ? "possible" : "impossible");
}