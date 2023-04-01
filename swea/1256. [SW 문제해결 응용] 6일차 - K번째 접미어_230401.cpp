#include <iostream>
#include <algorithm>

using namespace std;

string arr[400];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T; cin >> T;
	for (int tt = 1; tt <= T; tt++) {
		int k; string t; cin >> k >> t;
		if (k > t.size()) { 
			cout << "#" << tt << " none\n"; continue;
		}
		for (int i = 0; i < t.size(); i++) {
			arr[i] = t.substr(i);
		}
		sort(arr, arr + t.size());
		cout << "#" << tt << " "<<arr[k-1]<<"\n";
	}
}