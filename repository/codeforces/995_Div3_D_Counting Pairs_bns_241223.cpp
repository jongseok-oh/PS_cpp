#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
using ll = long long;
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while (t--) {
        ll n, x, y;
        cin >> n >> x >> y;
        
        ll sum = 0;
        vector<int> arr(n);
        for (int& num : arr) {
            cin >> num;
            sum += num;
        }
 
        sort(arr.begin(), arr.end());
        
        ll ret = 0;
        for (int i = 0; i < n-1; ++i) {
            int num = arr[i];
            ll up = sum - num - y, down = sum - num - x;
            
            int upIdx = lower_bound(arr.begin() + i + 1, arr.end(), up) - arr.begin();
            int downIdx = upper_bound(arr.begin() + i + 1, arr.end(), down) - arr.begin();
            ret += downIdx - upIdx;
        }
        cout << ret << "\n";
    }
}