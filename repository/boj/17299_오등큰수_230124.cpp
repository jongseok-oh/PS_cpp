#include <iostream>
#include <stack>

using namespace std;

int n;

int arr[1000000];
int cnt[1000001];
int ans[1000000];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		cnt[arr[i]]++;
	}
	stack<int> st;
	for (int i = n - 1; i >= 0; i--) {
		while (st.size() && cnt[arr[i]] >= cnt[st.top()]) st.pop();
		if (!st.size()) ans[i] = -1;
		else ans[i] = st.top();
		st.push(arr[i]);
	}
	for (int i = 0; i < n; i++) cout << ans[i] << " ";
}