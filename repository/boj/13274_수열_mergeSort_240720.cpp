#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

using ll = long long;

int n, k;
vector<ll> arr;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    arr.resize(n);
    for (auto& num : arr) cin >> num;
    
    sort(arr.begin(), arr.end());
    int l, r, x;
    while (k--) {
        cin >> l >> r >> x;
        --l; --r;
        vector<ll> temp(r - l + 1), temp2;
        for (int i = 0; i < n; ++i) {
            if (i >= l && i <= r) temp[i - l] = arr[i] + x;
            else temp2.push_back(arr[i]);
        }
        for (int i = 0, j = 0, k = 0;k<n;++k) {
            if (i == temp.size() || (j != temp2.size() && temp[i] > temp2[j])) {
                arr[k] = temp2[j++];
            }
            else {
                arr[k] = temp[i++];
            }
        }
    }
    
    for (auto& num : arr) cout << num << ' ';
}