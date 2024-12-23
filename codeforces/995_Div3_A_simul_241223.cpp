#include <iostream>
#include <vector>
 
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> mono(n), streo(n);
        for (int& p : mono) cin >> p;
        for (int& p : streo) cin >> p;
 
        int ret = mono[n-1];
        for (int i = 0; i < n - 1; ++i) {
            if (mono[i] > streo[i + 1]) {
                ret += mono[i] - streo[i + 1];
            }
        }
        cout << ret << "\n";
    }
}