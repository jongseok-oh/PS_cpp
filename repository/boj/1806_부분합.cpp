#include <iostream>
#include <algorithm>

using namespace std;

int n, s;

int answer = 1e9;

int arr[100000];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> s;
	for (int i = 0; i < n; i++) cin >> arr[i];
	
	int sum = arr[0];
	
	int low = 0, high = 0;
	while (high < n) {
		if (sum < s) {
			if (++high == n) break;
			sum += arr[high];
		}
		else {
			answer = min(answer, high - low + 1);
			sum -= arr[low++];
		}
	}
	cout << (answer == 1e9 ? 0 : answer);
}