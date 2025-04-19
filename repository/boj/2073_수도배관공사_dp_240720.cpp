#include <iostream>
#include <algorithm>

using namespace std;

const int _MAX = 100001;

int D, P;
int dp[_MAX];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> D >> P;
    
    dp[0] = 1e9;
    int l, c;
    for (int i = 0; i < P; ++i) {
        cin >> l >> c;
        for (int j = _MAX - l -1; j >=0 ; --j) {
            if (dp[j]) {
                int cap = min(dp[j], c);
                dp[j + l] = max(dp[j + l], cap);
            }
        }
    }
    cout << dp[D];
}